//
// Created by Bryce on 24-12-10.
//

#ifndef LOGGER_H
#define LOGGER_H

#include "CAE.h"
#include <cstdint>
#include <WinSock2.h>
#include <Iphlpapi.h>
#include <iostream>
#include <ws2tcpip.h>
#include <sqltoast.h>

class Logger {
private:
    // DAMENG 初始化参数
    dhenv __m_henv;
    dhcon __m_hcon;
    dhstmt __m_hstmt;
    DPIRETURN __m_rt;

    std::string __m_username;

    // 不应被CAE类访问的类成员变量 用双下划线__标识

    std::string __m_ip_; // ip
    struct in_addr __m_addr_;

    std::string __m_logger_sql_;
    std::vector<std::string> __m_res_lst_;

    std::string __m_db_; // 拼接数据库名
    std::string __m_tb_; // 拼接表名

    bool m_use_log = true;
    bool m_useQuery = true;

    // 所有参数可根据具体需求调整
    Logger( std::string& db_server, std::string& log_username, std::string& log_passwd,
        const std::string& db_username, const std::string& cidr, const bool use_log);

    void __dpiErrorMsgPrint(sdint2 hndl_type, dhandle hndl);

    uint32_t __ip2Int(std::string ip);

    bool __ip_in_cidr(std::string ip, std::string cidr);

    // 初始化时调用一次 保存到m_ip中
    bool __getIP(const std::string &cidr);

    bool __parseSQL(const std::string sql);

    bool __insert(std::string& sql);

    bool insertRecord(std::string& sql, std::string operation, bool exec_result);

    bool insertRecord(std::string& db_name, std::string& table_name, std::string operation, bool exec_result);

    ~Logger();

public:
    friend class CAE;
};

#endif //LOGGER_H
