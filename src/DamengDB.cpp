//
// Created by Bryce on 24-9-26.
//

#include <iostream>
#include "DamengDB.h"
#include "yaml-cpp/yaml.h"


DamengDB::DamengDB(const std::string &file_path) {
    // 读取yaml文件
    YAML::Node data_config = YAML::LoadFile(file_path);
    if(!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(1);
    }

    // 申请环境句柄
    this->m_rt = dpi_alloc_env(&this->m_henv);

    // 申请连接句柄
    this->m_rt = dpi_alloc_con(this->m_henv, &this->m_hcon);

    // 连接数据库
    this->m_rt = dpi_login(this->m_hcon,
        reinterpret_cast<sdbyte*>(data_config["database"]["server"].as<std::string>().data()),
        reinterpret_cast<sdbyte*>(data_config["database"]["username"].as<std::string>().data()),
        reinterpret_cast<sdbyte*>(data_config["database"]["passwd"].as<std::string>().data())
    );

    // 测试
    if(!DSQL_SUCCEEDED(this->m_rt)) {
        dpiErrorMsgPrint(DSQL_HANDLE_DBC, this->m_hcon);
	    exit(-1);
    }

    printf("dpi: connect to server success!\n");
}

DamengDB::~DamengDB() {
    this->m_rt = dpi_logout(this->m_hcon);
    if(!DSQL_SUCCEEDED(this->m_rt)){
        this->dpiErrorMsgPrint(DSQL_HANDLE_DBC, this->m_hcon);
        exit(-1);
    }
    printf( "dpi: disconnect from server success!\n" );

    // 释放连接句柄和环境句柄
    this->m_rt = dpi_free_con(this->m_hcon);
    this->m_rt = dpi_free_env(this->m_henv);
}

bool DamengDB::Query(std::string &sql_str) {
    sdbyte* _sql = reinterpret_cast<sdbyte*>(sql_str.data());
    // 申请语句句柄
    this->m_rt = dpi_alloc_stmt(this->m_hcon, &this->m_hstmt);

    // 执行sql语句
    this->m_rt = dpi_exec_direct(this->m_hstmt, _sql);

    //todo 添加日志写入部分

    if(!DSQL_SUCCEEDED(this->m_rt)) {
        std::cout << "query error" << std::endl;
        this->dpiErrorMsgPrint(DSQL_HANDLE_STMT, this->m_hstmt);
        this->m_rt = dpi_free_stmt(this->m_hstmt);
        return false;
    }
    std::cout << "query success." << std::endl;
    ulength* temp;
    sdint4* aaa;
    this->m_rt = dpi_get_stmt_attr(this->m_hstmt, DSQL_ATTR_ROW_STATUS_PTR, temp, 10, aaa);
    std::cout<< *aaa << std::endl;
    this->m_rt = dpi_free_stmt(this->m_hstmt);
    return true;
}

bool DamengDB::Delete(std::string &sql_str) {
    sdbyte* _sql = reinterpret_cast<sdbyte*>(sql_str.data());
    // 申请语句句柄
    this->m_rt = dpi_alloc_stmt(this->m_hcon, &this->m_hstmt);

    // 执行sql语句
    this->m_rt = dpi_exec_direct(this->m_hstmt, _sql);

    //todo 添加日志写入部分

    if(!DSQL_SUCCEEDED(this->m_rt)) {
        std::cout << "delete error" << std::endl;
        this->dpiErrorMsgPrint(DSQL_HANDLE_STMT, this->m_hstmt);
        this->m_rt = dpi_free_stmt(this->m_hstmt);
        return false;
    }
    std::cout << "delete success." << std::endl;
    this->m_rt = dpi_free_stmt(this->m_hstmt);
    return true;
}

bool DamengDB::Update(std::string &sql_str) {
    sdbyte* _sql = reinterpret_cast<sdbyte*>(sql_str.data());
    // 申请语句句柄
    this->m_rt = dpi_alloc_stmt(this->m_hcon, &this->m_hstmt);

    // 执行sql语句
    this->m_rt = dpi_exec_direct(this->m_hstmt, _sql);

    //todo 添加日志写入部分

    if(!DSQL_SUCCEEDED(this->m_rt)) {
        std::cout << "update error" << std::endl;
        this->dpiErrorMsgPrint(DSQL_HANDLE_STMT, this->m_hstmt);
        this->m_rt = dpi_free_stmt(this->m_hstmt);
        return false;
    }
    std::cout << "update success." << std::endl;
    this->m_rt = dpi_free_stmt(this->m_hstmt);
    return true;
}

bool DamengDB::Insert(std::string &sql_str) {

    sdbyte* _sql = reinterpret_cast<sdbyte*>(sql_str.data());
    // 申请语句句柄
    this->m_rt = dpi_alloc_stmt(this->m_hcon, &this->m_hstmt);

    // 执行sql语句
    this->m_rt = dpi_exec_direct(this->m_hstmt, _sql);

    //todo 添加日志写入部分

    if(!DSQL_SUCCEEDED(this->m_rt)) {
        std::cout << "insert error" << std::endl;
        this->dpiErrorMsgPrint(DSQL_HANDLE_STMT, this->m_hstmt);
        this->m_rt = dpi_free_stmt(this->m_hstmt);
        return false;
    }
    std::cout << "insert success." << std::endl;
    this->m_rt = dpi_free_stmt(this->m_hstmt);
    return true;
}

void DamengDB::dpiErrorMsgPrint(sdint2 hndl_type, dhandle hndl) {
    sdint4 err_code;
    sdint2 msg_len;
    sdbyte err_msg[SDBYTE_MAX];

    /* 获取错误信息集合 */
    dpi_get_diag_rec(hndl_type, hndl, 1, &err_code, err_msg, sizeof(err_msg), &msg_len);
    std::cout << "err_msg = " << err_msg << ", err_code = " << err_code << std::endl;
}

void DamengDB::connectTest() {
    // std::cout << "connectTest" << std::endl;
    YAML::Node config = YAML::LoadFile("../config.yaml");

    if (!config) {
        std::cout << "Open config File:" << "test " << " failed.";
    }

    std::cout << config["database"]["host"] << std::endl;
}

#ifdef USE_FILESYSTEM
void DamengDB::FileTest() {
    std::cout<< "use file system" <<std::endl;
    // test git
}
#endif
