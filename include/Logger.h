//
// Created by Bryce on 24-12-10.
//

#ifndef LOGGER_H
#define LOGGER_H

#include "CAE.h"


class Logger {
private:
    // DAMENG 初始化参数
    dhenv m_henv_;
    dhcon m_hcon_;
    dhstmt m_hstmt_;
    DPIRETURN m_rt_;

    std::string m_username;
    std::string m_ip;

    // todo 所有参数可根据具体需求调整

    Logger(std::string& serverAddr, std::string& username, std::string& passwd);

    void __dpiErrorMsgPrint(sdint2 hndl_type, dhandle hndl);

    // todo 初始化时调用一次 保存到m_ip中
    bool __getIP();

    //todo 初始化时调用一次 保存到m_username中
    bool __getUserName();

    bool __parseSQL();

    bool __insert(std::string& sql);

    bool insertRecord(std::string& sql, bool exec_result);

    bool insertRecord(std::string& db_name, std::string& table_name, bool exec_result);

    ~Logger();

public:
    friend class CAE;
};

#endif //LOGGER_H
