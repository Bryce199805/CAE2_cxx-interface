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

class Logger {
private:
    // DAMENG 初始化参数
    dhenv m_henv_;
    dhcon m_hcon_;
    dhstmt m_hstmt_;
    DPIRETURN m_rt_;

    std::string m_dbusername;
    std::string m_fsusername;
    std::string m_ip;
    struct in_addr m_addr_;
    std::string logger_sql;
    std::string m_db_;
    std::string m_tb_;

    // 所有参数可根据具体需求调整

    Logger(std::string& serverAddr, std::string& username, std::string& passwd);

    void __dpiErrorMsgPrint(sdint2 hndl_type, dhandle hndl);


    uint32_t __ip2Int(std::string ip);

    bool __ip_in_cidr(std::string ip, std::string cidr);

    // 初始化时调用一次 保存到m_ip中
    bool __getIP(const std::string &file_path);


    // 初始化时调用一次 保存到m_username中
    bool __getUserName(const std::string &file_path);

    bool __parseSQL(const std::string sql);

    bool __insert(std::string& sql);

    bool insertRecord(std::string& sql, std::string operation, bool exec_result);

    bool insertRecord(std::string& db_name, std::string& table_name, std::string operation, bool exec_result);

    ~Logger();

public:
    friend class CAE;
};

#endif //LOGGER_H
