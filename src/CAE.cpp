//
// Created by Bryce on 24-9-26.
//

#include "CAE.h"

// constructor

CAE::CAE(const std::string &file_path) {
    this->initDB_(file_path);
}

CAE::~CAE() {
    this->m_rt_ = dpi_logout(this->m_hcon_);

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->dpiErrorMsgPrint_(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }
    printf("========== dpi: disconnect from server success! ==========\n");

    // �ͷ����Ӿ���ͻ������
    this->m_rt_ = dpi_free_con(this->m_hcon_);
    this->m_rt_ = dpi_free_env(this->m_henv_);
}

// private function

bool CAE::initDB_(const std::string &file_path) {
    // ��ȡyaml�ļ�
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(1);
    }
    // ���뻷�����
    this->m_rt_ = dpi_alloc_env(&this->m_henv_);
    // �������Ӿ��
    this->m_rt_ = dpi_alloc_con(this->m_henv_, &this->m_hcon_);
    // �������ݿ�
    this->m_rt_ = dpi_login(this->m_hcon_,
                            reinterpret_cast<sdbyte *>(data_config["database"]["server"].as<std::string>().data()),
                            reinterpret_cast<sdbyte *>(data_config["database"]["username"].as<std::string>().data()),
                            reinterpret_cast<sdbyte *>(data_config["database"]["passwd"].as<std::string>().data())
    );
    // ����
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        dpiErrorMsgPrint_(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }
    printf("========== dpi: connect to server success! ==========\n");

    return true;
}

bool CAE::isValidSQLCommand_(const std::string &sql, const std::string type) {
    std::string trimmedSQL = sql;
    trimmedSQL.erase(0, trimmedSQL.find_first_not_of(" \t"));

    // �ҵ���һ������
    size_t pos = trimmedSQL.find(' ');
    std::string firstWord = (pos == std::string::npos) ? trimmedSQL : trimmedSQL.substr(0, pos);

    // ת��ΪСд�Խ��в����ִ�Сд�Ƚ�
    std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::tolower);

    // ����һ������
    return firstWord == type;
}

void CAE::dpiErrorMsgPrint_(sdint2 hndl_type, dhandle hndl) {
    sdint4 err_code;
    sdint2 msg_len;
    sdbyte err_msg[SDBYTE_MAX];

    /* ��ȡ������Ϣ���� */
    dpi_get_diag_rec(hndl_type, hndl, 1, &err_code, err_msg, sizeof(err_msg), &msg_len);
    std::cout << "err_msg = " << err_msg << ", err_code = " << err_code << std::endl;
}

// public function

bool CAE::Query(std::string &sql_str, std::vector<std::vector<std::string> > &res) {
    std::cout << "---------- Query ----------" << std::endl;
    // ========== ��ʼ���ж� ==========
    // �ж�sql�Ƿ���select��ͷ
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql���׼�����ѯ ==========
    // sql�������ת��ΪDM����
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // ���������
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // ִ��sql���
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    // �жϲ�ѯ���
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "query error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // ========== �����ѯ��� ==========
    // ��ȡ��ѯ�������
    sdint2 temp;
    this->m_rt_ = dpi_number_columns(this->m_hstmt_, &temp);
    int col_number = static_cast<int>(temp);

    // ��������ָ�����ݴ洢���
    std::unique_ptr<char[]> ptr[col_number];

    // ����󶨽���������
    const int col_buf_len = 30;
    sdbyte *col_name = new sdbyte[col_buf_len];
    sdint2 name_len, sql_type, dec_digits, nullable;
    ulength col_sz, row_num;
    slength out_length = 0;

    // �����ÿһ������
    for (int i = 1; i <= col_number; i++) {
        // ��ѯÿһ��������Ϣ
        this->m_rt_ = dpi_desc_column(this->m_hstmt_, static_cast<sdint2>(i), col_name, col_buf_len, &name_len,
                                      &sql_type, &col_sz, &dec_digits, &nullable);
        // std::cout << "name " << col_name << " name_len " << name_len << " sqltype " << sql_type << " col_sz " << col_sz << " dec_digits " << dec_digits << " nullable " << nullable<< std::endl;

        // ��ʼ��������
        ptr[i - 1] = std::make_unique<char[]>(col_sz + 1);
        // �����ݵ���
        this->m_rt_ = dpi_bind_col(
            this->m_hstmt_, i, DSQL_C_NCHAR, static_cast<void *>(ptr[i - 1].get()), col_sz + 1, &out_length);
    }
    // �ͷ������洢�ռ�ָ���ÿ�
    delete[] col_name;
    col_name = nullptr;


    // ѭ������ÿһ�м�¼
    while (dpi_fetch(this->m_hstmt_, &row_num) != DSQL_NO_DATA) {
        std::vector<std::string> temp;
        for (int i = 0; i < col_number; i++) {
            temp.push_back(std::string(ptr[i].get()));
        }
        res.push_back(temp);
    }

    //todo �����־д�벿��

    // �ͷ������
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

    std::cout << "query success!" << std::endl;
    return true;
}

bool CAE::Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res) {
    std::cout << "---------- Query ----------" << std::endl;
    // ========== ��ʼ���ж� ==========
    // �ж�sql�Ƿ���select��ͷ
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql���׼�����ѯ ==========
    // sql�������ת��ΪDM����
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // ���������
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // ִ��sql���
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    // �жϲ�ѯ���
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "query error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // ========== �����ѯ��� ==========
    // ��ȡ��ѯ�������
    sdint2 temp;
    this->m_rt_ = dpi_number_columns(this->m_hstmt_, &temp);
    int col_number = static_cast<int>(temp);

    // ��������ָ�����ݴ洢���
    std::unique_ptr<char[]> ptr[col_number];

    // ����󶨽���������
    const int col_buf_len = 30;
    sdbyte *col_name = new sdbyte[col_buf_len];
    sdint2 name_len, sql_type, dec_digits, nullable;
    ulength col_sz, row_num;
    slength out_length = 0;
    std::vector<int> types;

    // �����ÿһ������
    for (int i = 1; i <= col_number; i++) {
        // ��ѯÿһ��������Ϣ
        this->m_rt_ = dpi_desc_column(this->m_hstmt_, static_cast<sdint2>(i), col_name, col_buf_len, &name_len,
                                      &sql_type, &col_sz, &dec_digits, &nullable);
        // std::cout << "name " << col_name << " name_len " << name_len << " sqltype " << sql_type << " col_sz " << col_sz << " dec_digits " << dec_digits << " nullable " << nullable<< std::endl;
        types.push_back(static_cast<int>(sql_type));
        // ��ʼ��������
        ptr[i - 1] = std::make_unique<char[]>(col_sz + 1);
        // �����ݵ���
        this->m_rt_ = dpi_bind_col(
            this->m_hstmt_, i, DSQL_C_NCHAR, static_cast<void *>(ptr[i - 1].get()), col_sz + 1, &out_length);
    }
    // �ͷ������洢�ռ�ָ���ÿ�
    delete[] col_name;
    col_name = nullptr;

    // ѭ������ÿһ�м�¼
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

    //todo �����־д�벿��

    // �ͷ������
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

    std::cout << "query success!" << std::endl;
    return true;
}

bool CAE::Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types) {
    std::cout << "---------- Query ----------" << std::endl;
    // ========== ��ʼ���ж� ==========
    // �ж�sql�Ƿ���select��ͷ
    if (!this->isValidSQLCommand_(sql_str, "select")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql���׼�����ѯ ==========
    // sql�������ת��ΪDM����
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // ���������
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // ִ��sql���
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    // �жϲ�ѯ���
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "query error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // ========== �����ѯ��� ==========
    // ��ȡ��ѯ�������
    sdint2 temp;
    this->m_rt_ = dpi_number_columns(this->m_hstmt_, &temp);
    int col_number = static_cast<int>(temp);

    // ��������ָ�����ݴ洢���
    std::unique_ptr<char[]> ptr[col_number];

    // ����󶨽���������
    const int col_buf_len = 30;
    sdbyte *col_name = new sdbyte[col_buf_len];
    sdint2 name_len, sql_type, dec_digits, nullable;
    ulength col_sz, row_num;
    slength out_length = 0;
    std::vector<int> types;

    // �����ÿһ������
    for (int i = 1; i <= col_number; i++) {
        // ��ѯÿһ��������Ϣ
        this->m_rt_ = dpi_desc_column(this->m_hstmt_, static_cast<sdint2>(i), col_name, col_buf_len, &name_len,
                                      &sql_type, &col_sz, &dec_digits, &nullable);
        // std::cout << "name " << col_name << " name_len " << name_len << " sqltype " << sql_type << " col_sz " << col_sz << " dec_digits " << dec_digits << " nullable " << nullable<< std::endl;
        types.push_back(static_cast<int>(sql_type));
        // ��ʼ��������
        ptr[i - 1] = std::make_unique<char[]>(col_sz + 1);
        // �����ݵ���
        this->m_rt_ = dpi_bind_col(
            this->m_hstmt_, i, DSQL_C_NCHAR, static_cast<void *>(ptr[i - 1].get()), col_sz + 1, &out_length);
    }
    // �ͷ������洢�ռ�ָ���ÿ�
    delete[] col_name;
    col_name = nullptr;

    // ѭ������ÿһ�м�¼
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

    //todo �����־д�벿��

    // �ͷ������
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);

    std::cout << "query success!" << std::endl;
    return true;
}

bool CAE::Delete(std::string &sql_str) {
    std::cout << "---------- Delete ----------" << std::endl;
    // ========== ��ʼ���ж� ==========
    // �ж�sql�Ƿ���delete��ͷ
    if (!this->isValidSQLCommand_(sql_str, "delete")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql���׼����ִ�� ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // ���������
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // ִ��sql���
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    //todo �����־д�벿��

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "delete error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // �ͷ������
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    std::cout << "delete success!" << std::endl;
    return true;
}

bool CAE::Update(std::string &sql_str) {
    std::cout << "---------- Update ----------" << std::endl;
    // ========== ��ʼ���ж� ==========
    // �ж�sql�Ƿ���update��ͷ
    if (!this->isValidSQLCommand_(sql_str, "update")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql���׼����ִ�� ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // ���������
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // ִ��sql���
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    //todo �����־д�벿��

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "update error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // �ͷ������
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    std::cout << "update success!" << std::endl;
    return true;
}

bool CAE::Insert(std::string &sql_str) {
    std::cout << "---------- Insert ----------" << std::endl;
    // ========== ��ʼ���ж� ==========
    // �ж�sql�Ƿ���insert��ͷ
    if (!this->isValidSQLCommand_(sql_str, "insert")) {
        std::cout << "illegal statement." << std::endl;
        return false;
    }

    // ========== sql���׼����ִ�� ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql_str.data());
    // ���������
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // ִ��sql���
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    //todo �����־д�벿��

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "insert error!" << std::endl;
        this->dpiErrorMsgPrint_(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // �ͷ������
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    std::cout << "insert success!" << std::endl;
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
