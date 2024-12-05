//
// Created by Bryce on 24-9-26.
//

#include "CAE.h"

// constructor

CAE::CAE(const std::string &file_path) {
    this->initDB_(file_path);
}

CAE::~CAE() {
    this->releaseDB_();

#ifdef USE_FILESYSTEM
    std::cout << "minio release" << std::endl;
#endif
}

// private function

bool CAE::initDB_(const std::string &file_path) {
    // 读取yaml文件
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(1);
    }

    // 申请环境句柄
    this->m_rt_ = dpi_alloc_env(&this->m_henv_);
    this->m_rt_ = dpi_set_env_attr(this->m_henv_, DSQL_ATTR_LOCAL_CODE, (dpointer) PG_UTF8, sizeof(PG_UTF8));
    // 申请连接句柄
    this->m_rt_ = dpi_alloc_con(this->m_henv_, &this->m_hcon_);
    // 连接数据库
    this->m_rt_ = dpi_login(this->m_hcon_,
                            reinterpret_cast<sdbyte *>(data_config["database"]["server"].as<std::string>().data()),
                            reinterpret_cast<sdbyte *>(data_config["database"]["username"].as<std::string>().data()),
                            reinterpret_cast<sdbyte *>(data_config["database"]["passwd"].as<std::string>().data())
    );
    // 测试
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        dpiErrorMsgPrint_(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }
    printf("========== dpi: connect to server success! ==========\n");

    return true;
}

void CAE::releaseDB_() {
    this->m_rt_ = dpi_logout(this->m_hcon_);

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }
    printf("========== dpi: disconnect from server success! ==========\n");

    // 释放连接句柄和环境句柄
    this->m_rt_ = dpi_free_con(this->m_hcon_);
    this->m_rt_ = dpi_free_env(this->m_henv_);
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
    std::cout << "err_msg = " << err_msg << ", err_code = " << err_code << std::endl;
}

// public function

bool CAE::Query(std::string &sql_str, std::vector<std::vector<std::string> > &res) {
//    std::cout << "---------- Query ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以select开头
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << "illegal statement." << std::endl;
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
        std::cout << "query error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
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

    //todo 添加日志写入部分

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
        std::cout << "illegal statement." << std::endl;
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
        std::cout << "query error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
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

    //todo 添加日志写入部分

    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

//    std::cout << "query success!" << std::endl;
    return true;
}

bool CAE::Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types) {
//    std::cout << "---------- Query ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以select开头
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << "illegal statement." << std::endl;
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
        std::cout << "query error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
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

    //todo 添加日志写入部分

    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

//    std::cout << "query success!" << std::endl;
    return true;
}

bool CAE::Delete(std::string &sql_str) {
//    std::cout << "---------- Delete ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以delete开头
    if (!this->isValidSQLCommand_(sql_str, "delete")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    //todo 添加日志写入部分

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "delete error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
//    std::cout << "delete success!" << std::endl;
    return true;
}

bool CAE::Update(std::string &sql_str) {
//    std::cout << "---------- Update ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以update开头
    if (!this->isValidSQLCommand_(sql_str, "update")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    //todo 添加日志写入部分

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "update error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
//    std::cout << "update success!" << std::endl;
    return true;
}

bool CAE::Insert(std::string &sql_str) {
//    std::cout << "---------- Insert ----------" << std::endl;
    // ========== 初始化判断 ==========
    // 判断sql是否以insert开头
    if (!this->isValidSQLCommand_(sql_str, "insert")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    //todo 添加日志写入部分

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "insert error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
//    std::cout << "insert success!" << std::endl;
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
                    std::cout << "unknow Type." << " ";
            }
        }
        std::cout << std::endl;
    }
}
