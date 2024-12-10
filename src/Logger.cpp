//
// Created by Bryce on 24-12-10.
//

#include "Logger.h"

Logger::Logger(std::string& serverAddr, std::string& username, std::string& passwd) {
    // 申请环境句柄
    this->m_rt_ = dpi_alloc_env(&this->m_henv_);
    this->m_rt_ = dpi_set_env_attr(this->m_henv_, DSQL_ATTR_LOCAL_CODE, (dpointer) PG_UTF8, sizeof(PG_UTF8));
    // 申请连接句柄
    this->m_rt_ = dpi_alloc_con(this->m_henv_, &this->m_hcon_);
    // 连接数据库
    this->m_rt_ = dpi_login(this->m_hcon_,
                            reinterpret_cast<sdbyte *>(serverAddr.data()),
                            reinterpret_cast<sdbyte *>(username.data()),
                            reinterpret_cast<sdbyte *>(passwd.data())
    );
    // 测试
    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->__dpiErrorMsgPrint(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }
    printf("========== Logger: init done! ==========\n");
}

void Logger::__dpiErrorMsgPrint(sdint2 hndl_type, dhandle hndl) {
    sdint4 err_code;
    sdint2 msg_len;
    sdbyte err_msg[SDBYTE_MAX];

    /* 获取错误信息集合 */
    dpi_get_diag_rec(hndl_type, hndl, 1, &err_code, err_msg, sizeof(err_msg), &msg_len);
    std::cout << "[Logger ERROR]: Err_msg = " << err_msg << ", Err_code = " << err_code << std::endl;
}

bool Logger::__getIP() {
    std::cout << "logger test" << std::endl;
    return true;
}

bool Logger::__getUserName() {
    std::cout << "logger test" << std::endl;
    return true;
}

bool Logger::__parseSQL() {
    std::cout << "logger test" << std::endl;
    return true;
}

bool Logger::__insert(std::string& sql) {
    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql.data());
    // 申请语句句柄
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // 执行sql语句
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "[Logger ERROR]: record insert error!" << std::endl;
        this->__dpiErrorMsgPrint(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // 释放语句句柄
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    return true;
}

bool Logger::insertRecord(std::string& sql, bool exec_result) {

    // sprint 定义 insert 模板 补全后插入
    std::string logger_sql = "insert ...";
    if(this->__insert(logger_sql)) {

    }
    return true;
}

bool Logger::insertRecord(std::string& db_name, std::string& table_name, bool exec_result) {

    std::string logger_sql = "insert ...";
    if(this->__insert(logger_sql)) {

    }
    return true;
}

Logger::~Logger() {
    this->m_rt_ = dpi_logout(this->m_hcon_);

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        this->__dpiErrorMsgPrint(DSQL_HANDLE_DBC, this->m_hcon_);
        exit(-1);
    }
    printf("========== Logger: disconnect from server success! ==========\n");

    // 释放连接句柄和环境句柄 语句句柄每次执行已释放
    this->m_rt_ = dpi_free_con(this->m_hcon_);
    this->m_rt_ = dpi_free_env(this->m_henv_);
    this->m_hcon_ = this->m_henv_ = this->m_hstmt_ = nullptr;
}


