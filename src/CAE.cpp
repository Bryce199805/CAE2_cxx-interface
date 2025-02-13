//
// Created by Bryce on 24-9-26.
//

#include "CAE.h"

// constructor

CAE::CAE(const std::string &file_path) {
    // 读取yaml文件
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << this->m_error_msg_ << "Open config File:" << file_path << " failed.";
        exit(1);
    }

    bool use_log;
    std::string db_server, username, password,log_username, log_password, cidr;

    try {
        db_server = data_config["server"]["database-server"].as<std::string>();
        username = data_config["server"]["username"].as<std::string>();
        password = this->encrypt_(data_config["server"]["password"].as<std::string>());

        log_username = data_config["log"]["username"].as<std::string>();
        log_password = this->encrypt_(data_config["log"]["password"].as<std::string>());
        cidr = data_config["log"]["cidr"].as<std::string>();
        use_log = data_config["log"]["enable"].as<bool>();
    }
    catch (YAML::Exception &e) {
        std::cout << this->m_error_msg_ << "YAML ERROR:" << e.what() << std::endl;
        exit(-1);
    }

    this->initDB_(db_server, username, password);
    // 初始化log对象
    this->initLogger_(db_server, log_username, log_password, username, cidr, use_log);

    std::cout << "----------------------------------------------------------------------" << std::endl;
}

CAE::~CAE() {
    this->releaseDB_();

#ifdef USE_FILESYSTEM
    // 等待所有线程结束
    for(auto& thread : this->m_threads_) {
        if (thread->joinable()){
            thread->join();
        }
    }

    for(auto &temp_path : this->m_temp_path_){
        std::filesystem::remove_all(temp_path);
    }

    this->releaseFileSystem_();
#endif

    this->releaseLogger_();
    std::cout << this->m_system_msg_ << "Disconnect from server success!" << std::endl;
}


// private function

bool CAE::initDB_(std::string &db_server, std::string &db_username, std::string &db_passwd) {
    // 申请环境句柄
    this->m_rt_ = dpi_alloc_env(&this->m_henv_);
    this->m_rt_ = dpi_set_env_attr(this->m_henv_, DSQL_ATTR_LOCAL_CODE, (dpointer) PG_UTF8, sizeof(PG_UTF8));
    // 申请连接句柄
    this->m_rt_ = dpi_alloc_con(this->m_henv_, &this->m_hcon_);

    // get connect parameters

    // 连接数据库
    this->m_rt_ = dpi_login(this->m_hcon_,
                            reinterpret_cast<sdbyte *>(db_server.data()),
                            reinterpret_cast<sdbyte *>(db_username.data()),
                            reinterpret_cast<sdbyte *>(db_passwd.data()));

    // 测试
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        dpiErrorMsgPrint_(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }

    return true;
}

bool CAE::initLogger_(std::string &db_server, std::string &log_username, std::string &log_passwd,
                      const std::string &db_username, const std::string &cidr, const bool use_log) {
    this->logger_obj = new Logger(db_server, log_username, log_passwd, db_username, cidr, use_log);
    return true;
}

void CAE::releaseDB_() {
    this->m_rt_ = dpi_logout(this->m_hcon_);

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }

    // 释放连接句柄和环境句柄
    this->m_rt_ = dpi_free_con(this->m_hcon_);
    this->m_rt_ = dpi_free_env(this->m_henv_);
    this->m_hcon_ = this->m_henv_ = this->m_hstmt_ = nullptr;
}

void CAE::releaseLogger_() {
    delete this->logger_obj;
    this->logger_obj = nullptr;
}


bool CAE::isValidSQLCommand_(const std::string &sql, const std::string type) {
    std::string trimmedSQL = sql;
    trimmedSQL.erase(0, trimmedSQL.find_first_not_of(" \t"));

    // 找到第一个单词
    size_t pos = trimmedSQL.find(' ');
    std::string firstWord = (pos == std::string::npos) ? trimmedSQL : trimmedSQL.substr(0, pos);

    // 转换为小写以进行不区分大小写比较
    std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::tolower);

    // 检查第一个单词
    return firstWord == type;
}

void CAE::dpiErrorMsgPrint_(sdint2 hndl_type, dhandle hndl) {
    sdint4 err_code;
    sdint2 msg_len;
    sdbyte err_msg[SDBYTE_MAX];

    /* 获取错误信息集合 */
    dpi_get_diag_rec(hndl_type, hndl, 1, &err_code, err_msg, sizeof(err_msg), &msg_len);
    std::cout << this->m_error_msg_ << err_msg << ", ERROR_CODE = " << err_code << std::endl;
}

std::string CAE::encrypt_(const std::string &data) {
    unsigned char *result;
    unsigned int len = SHA256_DIGEST_LENGTH;
    std::string key = "3G@ln$UOd8Ptf@XU";

    // HMAC-SHA256
    result = HMAC(EVP_sha256(), key.c_str(), key.length(), reinterpret_cast<const unsigned char *>(data.c_str()),
                  data.length(), NULL, &len);

    // 截取前 16 字节（128 位）
    unsigned char truncated_result[16];
    for (int i = 0; i < 16; i++) {
        truncated_result[i] = result[i];
    }

    // 转换为十六进制字符串
    std::ostringstream hex_result;
    for (int i = 0; i < 16; i++) {
        hex_result << std::hex << std::setw(2) << std::setfill('0') << (int) truncated_result[i];
    }
    return hex_result.str();
}

// public function

bool CAE::Query(std::string &sql_str, std::vector<std::vector<std::string> > &res) {
    // ========== 初始化判断 ==========
    // 判断sql是否以select开头
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << this->m_error_msg_ << "Illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与查询 ==========
    // sql语句类型转换为DM类型
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    // 判断查询结果
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

        if (logger_obj->m_use_log && logger_obj->m_use_query) {
            logger_obj->insertRecord(sql_str, "查询", false);
        }
        return false;
    }

    // ========== 处理查询结果 ==========
    // 获取查询结果列数
    sdint2 temp;
    this->m_rt_ = dpi_number_columns(this->m_hstmt_, &temp);
    int col_number = static_cast<int>(temp);

    // 定义智能指针数据存储结果
    std::unique_ptr<char[]> ptr[col_number];

    // 定义绑定结果所需变量
    const int col_buf_len = 30;
    sdbyte *col_name = new sdbyte[col_buf_len];
    sdint2 name_len, sql_type, dec_digits, nullable;
    ulength col_sz, row_num;
    slength out_length = 0;

    // 处理绑定每一列数据
    for (int i = 1; i <= col_number; i++) {
        // 查询每一列数据信息
        this->m_rt_ = dpi_desc_column(this->m_hstmt_, static_cast<sdint2>(i), col_name, col_buf_len, &name_len,
                                      &sql_type, &col_sz, &dec_digits, &nullable);
        // std::cout << "name " << col_name << " name_len " << name_len << " sqltype " << sql_type << " col_sz " << col_sz << " dec_digits " << dec_digits << " nullable " << nullable<< std::endl;

        // 初始化列数组
        ptr[i - 1] = std::make_unique<char[]>(col_sz + 1);
        // 绑定数据到列
        this->m_rt_ = dpi_bind_col(
            this->m_hstmt_, i, DSQL_C_NCHAR, static_cast<void *>(ptr[i - 1].get()), col_sz + 1, &out_length);
    }
    // 释放列名存储空间指针置空
    delete[] col_name;
    col_name = nullptr;


    // 循环读出每一行记录
    while (dpi_fetch(this->m_hstmt_, &row_num) != DSQL_NO_DATA) {
        std::vector<std::string> temp;
        for (int i = 0; i < col_number; i++) {
            temp.push_back(std::string(ptr[i].get()));
        }
        res.push_back(temp);
    }
    if (logger_obj->m_use_log && logger_obj->m_use_query) {
        logger_obj->insertRecord(sql_str, "查询", true);
    }

    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

    //    std::cout << "query success!" << std::endl;
    return true;
}

bool CAE::Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res) {
    //    std::cout << "---------- Query ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以select开头
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << this->m_error_msg_ << "Illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与查询 ==========
    // sql语句类型转换为DM类型
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    // 判断查询结果
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

        if (logger_obj->m_use_log && logger_obj->m_use_query) {
            logger_obj->insertRecord(sql_str, "查询", false);
        }

        return false;
    }

    // ========== 处理查询结果 ==========
    // 获取查询结果列数
    sdint2 temp;
    this->m_rt_ = dpi_number_columns(this->m_hstmt_, &temp);
    int col_number = static_cast<int>(temp);

    // 定义智能指针数据存储结果
    std::unique_ptr<char[]> ptr[col_number];

    // 定义绑定结果所需变量
    const int col_buf_len = 30;
    sdbyte *col_name = new sdbyte[col_buf_len];
    sdint2 name_len, sql_type, dec_digits, nullable;
    ulength col_sz, row_num;
    slength out_length = 0;
    std::vector<int> types;

    // 处理绑定每一列数据
    for (int i = 1; i <= col_number; i++) {
        // 查询每一列数据信息
        this->m_rt_ = dpi_desc_column(this->m_hstmt_, static_cast<sdint2>(i), col_name, col_buf_len, &name_len,
                                      &sql_type, &col_sz, &dec_digits, &nullable);
        // std::cout << "name " << col_name << " name_len " << name_len << " sqltype " << sql_type << " col_sz " << col_sz << " dec_digits " << dec_digits << " nullable " << nullable<< std::endl;
        types.push_back(static_cast<int>(sql_type));
        // 初始化列数组
        ptr[i - 1] = std::make_unique<char[]>(col_sz + 1);
        // 绑定数据到列
        this->m_rt_ = dpi_bind_col(
            this->m_hstmt_, i, DSQL_C_NCHAR, static_cast<void *>(ptr[i - 1].get()), col_sz + 1, &out_length);
    }
    // 释放列名存储空间指针置空
    delete[] col_name;
    col_name = nullptr;

    // 循环读出每一行记录
    while (dpi_fetch(this->m_hstmt_, &row_num) != DSQL_NO_DATA) {
        std::vector<DBVariant> temp;
        std::string str;
        for (int i = 0; i < col_number; i++) {
            str = ptr[i].get();
            switch (types[i]) {
                case 3: // BIT
                case 5: // TinyInt
                case 6: // SmallInt
                case 7: // Int
                case 8: // BigInt
                    // all to int
                    temp.push_back(std::stoi(str));
                    break;
                case 10: // Float
                    temp.push_back(std::stof(str));
                    break;
                case 11: // Double
                    // all to double
                    temp.push_back(std::stod(str));
                    break;
                default:
                    // 2 varchar  14 date
                    // else to string
                    temp.push_back(str);
            }
        }
        res.push_back(temp);
    }

    if (logger_obj->m_use_log && logger_obj->m_use_query) {
        logger_obj->insertRecord(sql_str, "查询", true);
    }
    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

    if (this->m_show_msg_) {
        std::cout << m_success_msg_ << "Query Success!" << std::endl;
    }
    return true;
}

bool CAE::Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types) {
    //    std::cout << "---------- Query ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以select开头
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << this->m_error_msg_ << "Illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与查询 ==========
    // sql语句类型转换为DM类型
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    // 判断查询结果
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

        if (logger_obj->m_use_log && logger_obj->m_use_query) {
            logger_obj->insertRecord(sql_str, "查询", false);
        }
        return false;
    }

    // ========== 处理查询结果 ==========
    // 获取查询结果列数
    sdint2 temp;
    this->m_rt_ = dpi_number_columns(this->m_hstmt_, &temp);
    int col_number = static_cast<int>(temp);

    // 定义智能指针数据存储结果
    std::unique_ptr<char[]> ptr[col_number];

    // 定义绑定结果所需变量
    const int col_buf_len = 30;
    sdbyte *col_name = new sdbyte[col_buf_len];
    sdint2 name_len, sql_type, dec_digits, nullable;
    ulength col_sz, row_num;
    slength out_length = 0;
    std::vector<int> types;

    // 处理绑定每一列数据
    for (int i = 1; i <= col_number; i++) {
        // 查询每一列数据信息
        this->m_rt_ = dpi_desc_column(this->m_hstmt_, static_cast<sdint2>(i), col_name, col_buf_len, &name_len,
                                      &sql_type, &col_sz, &dec_digits, &nullable);
        // std::cout << "name " << col_name << " name_len " << name_len << " sqltype " << sql_type << " col_sz " << col_sz << " dec_digits " << dec_digits << " nullable " << nullable<< std::endl;
        types.push_back(static_cast<int>(sql_type));
        // 初始化列数组
        ptr[i - 1] = std::make_unique<char[]>(col_sz + 1);
        // 绑定数据到列
        this->m_rt_ = dpi_bind_col(
            this->m_hstmt_, i, DSQL_C_NCHAR, static_cast<void *>(ptr[i - 1].get()), col_sz + 1, &out_length);
    }
    // 释放列名存储空间指针置空
    delete[] col_name;
    col_name = nullptr;

    // 循环读出每一行记录
    while (dpi_fetch(this->m_hstmt_, &row_num) != DSQL_NO_DATA) {
        std::vector<DBVariant> temp;
        std::string str;
        for (int i = 0; i < col_number; i++) {
            str = ptr[i].get();
            switch (types[i]) {
                case 3: // BIT
                case 5: // TinyInt
                case 6: // SmallInt
                case 7: // Int
                case 8: // BigInt
                    // all to int
                    temp.push_back(std::stoi(str));
                    col_types.push_back(1);
                    break;
                case 10: // Float
                    temp.push_back(std::stof(str));
                    col_types.push_back(2);
                    break;
                case 11: // Double
                    // all to double
                    temp.push_back(std::stod(str));
                    col_types.push_back(3);
                    break;
                default:
                    // 2 varchar  14 date
                    // else to string
                    temp.push_back(str);
                    col_types.push_back(0);
            }
        }
        res.push_back(temp);
    }
    if (logger_obj->m_use_log && logger_obj->m_use_query) {
        logger_obj->insertRecord(sql_str, "查询", true);
    }
    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

    if (this->m_show_msg_) {
        std::cout << this->m_success_msg_ << "Query Success!" << std::endl;
    }
    return true;
}

bool CAE::Delete(std::string &sql_str) {
    //    std::cout << "---------- Delete ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以delete开头
    if (!this->isValidSQLCommand_(sql_str, "delete")) {
        std::cout << this->m_error_msg_ << "Illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);


    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

        if (logger_obj->m_use_log && logger_obj->m_use_query) {
            logger_obj->insertRecord(sql_str, "删除", false);
        }

        return false;
    }

    if (logger_obj->m_use_log && logger_obj->m_use_query) {
        logger_obj->insertRecord(sql_str, "删除", true);
    }
    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    if (this->m_show_msg_) {
        std::cout << this->m_success_msg_ << "Delete success!" << std::endl;
    }
    return true;
}

bool CAE::Update(std::string &sql_str) {
    // ========== 初始化判断 ==========
    // 判断sql是否以update开头
    if (!this->isValidSQLCommand_(sql_str, "update")) {
        std::cout << this->m_error_msg_ << "Illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);


    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

        if (logger_obj->m_use_log && logger_obj->m_use_query) {
            logger_obj->insertRecord(sql_str, "修改", false);
        }

        return false;
    }
    if (logger_obj->m_use_log && logger_obj->m_use_query) {
        logger_obj->insertRecord(sql_str, "修改", true);
    }
    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    if (this->m_show_msg_) {
        std::cout << this->m_success_msg_ <<  "Update success!" << std::endl;
    }
    return true;
}

bool CAE::Insert(std::string &sql_str) {
    // ========== 初始化判断 ==========
    // 判断sql是否以insert开头
    if (!this->isValidSQLCommand_(sql_str, "insert")) {
        std::cout << this->m_error_msg_ << "Illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);


    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        if (logger_obj->m_use_log && logger_obj->m_use_query) {
            logger_obj->insertRecord(sql_str, "插入", false);
        }
        return false;
    }

    if (logger_obj->m_use_log && logger_obj->m_use_query) {
        logger_obj->insertRecord(sql_str, "插入", true);
    }
    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    if (this->m_show_msg_) {
        std::cout << this->m_success_msg_ << "Insert success!" << std::endl;
    }
    return true;
}

void CAE::printResult(std::vector<std::vector<std::string> > &res) {
    for (auto row: res) {
        for (auto col: row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

void CAE::printResult(std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types) {
    for (auto row: res) {
        for (int i = 0; i < row.size(); i++) {
            switch (col_types[i]) {
                case 0: //string
                    std::cout << row[i].asTypeString() << " ";
                    break;
                case 1: //int
                    std::cout << row[i].asTypeInteger() << " ";
                    break;
                case 2: //float
                    std::cout << row[i].asTypeFloat() << " ";
                    break;
                case 3: //double
                    std::cout << row[i].asTypeDouble() << " ";
                    break;
                default:
                    std::cout << this->m_system_msg_ <<  "Unknown Type." << " ";
            }
        }
        std::cout << std::endl;
    }
}
