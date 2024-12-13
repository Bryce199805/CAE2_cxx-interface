//
// Created by Bryce on 24-12-10.
//

#include "Logger.h"

#include "getTBName.h"

Logger::Logger(std::string &db_server, std::string &log_username, std::string &log_passwd,
               const std::string &db_username, const std::string &cidr, const bool use_log) {
    std::string ip;
    this->__getIP(cidr, ip);
    this->__m_username = db_username;
    this->m_use_log = use_log;

    // 申请环境句柄
    this->__m_rt = dpi_alloc_env(&this->__m_henv);
    this->__m_rt = dpi_set_env_attr(this->__m_henv, DSQL_ATTR_LOCAL_CODE, (dpointer) PG_UTF8, sizeof(PG_UTF8));
    // 申请连接句柄
    this->__m_rt = dpi_alloc_con(this->__m_henv, &this->__m_hcon);
    // 连接数据库
    this->__m_rt = dpi_login(this->__m_hcon,
                             reinterpret_cast<sdbyte *>(db_server.data()),
                             reinterpret_cast<sdbyte *>(log_username.data()),
                             reinterpret_cast<sdbyte *>(log_passwd.data())
    );
    // 测试
    if (!DSQL_SUCCEEDED(this->__m_rt)) {
        this->__dpiErrorMsgPrint(DSQL_HANDLE_DBC, this->__m_hcon);
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

uint32_t Logger::__ip2Int(std::string ip) {
    if (inet_pton(AF_INET, ip.c_str(), &this->__m_addr_) != 1) {
        std::cerr << "Invalid IP address: " << ip << std::endl;
        return 0;
    }
    // 转换为主机字节序
    return ntohl(this->__m_addr_.s_addr);
}

bool Logger::__ip_in_cidr(std::string ip, std::string cidr) {
    size_t pos = cidr.find('/');
    std::string cidr_ip_str = cidr.substr(0, pos);
    int netmask_len = std::stoi(cidr.substr(pos + 1));

    // 将IP地址转换为32位整数
    uint32_t ip_value = this->__ip2Int(ip);
    // 将CIDR网络地址转换为32位整数
    uint32_t cidr_ip_value = this->__ip2Int(cidr_ip_str);

    // 计算子网掩码（CIDR子网长度）
    uint32_t ip_mask = (0xFFFFFFFF << (32 - netmask_len)) & 0xFFFFFFFF;

    // 检查IP是否在CIDR地址块内
    return (ip_value & ip_mask) == (cidr_ip_value & ip_mask);
}

bool Logger::__getIP(const std::string &cidr, std::string &ip) {
    //PIP_ADAPTER_INFO结构体指针存储本机网卡信息
    PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
    //得到结构体大小,用于GetAdaptersInfo参数
    unsigned long stSize = sizeof(IP_ADAPTER_INFO);
    //调用GetAdaptersInfo函数,填充pIpAdapterInfo指针变量;其中stSize参数既是一个输入量也是一个输出量
    int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    if (ERROR_BUFFER_OVERFLOW == nRel) {
        //如果函数返回的是ERROR_BUFFER_OVERFLOW
        //则说明GetAdaptersInfo参数传递的内存空间不够,同时其传出stSize,表示需要的空间大小
        //这也是说明为什么stSize既是一个输入量也是一个输出量
        //释放原来的内存空间
        delete pIpAdapterInfo;
        //重新申请内存空间用来存储所有网卡信息
        pIpAdapterInfo = (PIP_ADAPTER_INFO) new BYTE[stSize];
        //再次调用GetAdaptersInfo函数,填充pIpAdapterInfo指针变量
        nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    }
    if (ERROR_SUCCESS == nRel) {
        //输出网卡信息
        //可能有多网卡,因此通过循环去判断
        while (pIpAdapterInfo) {
            IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
            do {
                ip = pIpAddrString->IpAddress.String;
                if (this->__ip_in_cidr(ip, cidr)) {
                    this->__m_ip_ = ip;
                    // std::cout << this->m_ip << std::endl;
                    return true;
                }
                pIpAddrString = pIpAddrString->Next;
            } while (pIpAddrString);
            pIpAdapterInfo = pIpAdapterInfo->Next;
        }
    }
    //释放内存空间
    if (pIpAdapterInfo) {
        delete pIpAdapterInfo;
    }
    return false;
}

bool Logger::__parseSQL(const std::string sql, std::string &db, std::string &table) {
    if (!sqltoaster::getTBName(sql, this->__m_res_lst_)) {
        return false;
    }

    this->__m_db_.clear();
    this->__m_tb_.clear();

    for (size_t i = 0; i < this->__m_res_lst_.size(); ++i) {
        size_t dot_pos = this->__m_res_lst_[i].find('.');
        if (dot_pos != std::string::npos) {
            db = this->__m_res_lst_[i].substr(0, dot_pos);
            table = this->__m_res_lst_[i].substr(dot_pos + 1);
            if (!__m_db_.empty()) {
                __m_db_ += "','";
                __m_tb_ += "','";
            }
            __m_db_ += db;
            __m_tb_ += table;
        }
    }
    return true;
}

bool Logger::__insert(std::string &sql) {
    // ========== sql语句准备与执行 ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql.data());
    // 申请语句句柄
    this->__m_rt = dpi_alloc_stmt(this->__m_hcon, &this->__m_hstmt);
    // 执行sql语句
    this->__m_rt = dpi_exec_direct(this->__m_hstmt, _sql);

    if (!DSQL_SUCCEEDED(this->__m_rt)) {
        std::cout << "[Logger ERROR]: record insert error!" << std::endl;
        this->__dpiErrorMsgPrint(DSQL_HANDLE_STMT, this->__m_hstmt);
        this->__m_rt = dpi_free_stmt(this->__m_hstmt);
        return false;
    }

    // 释放语句句柄
    this->__m_rt = dpi_free_stmt(this->__m_hstmt);
    return true;
}

bool Logger::insertRecord(std::string &sql, std::string operation, bool exec_result) {
    std::string db;
    std::string table;
    if (!this->__parseSQL(sql, db, table)) {
        return false;
    }
    char sqlStr[1024];
    sprintf(sqlStr, "INSERT INTO LOGS.LOG (user_name, ip_addr, source, operation, schemas, tables, time, result) "
            "VALUES ('%s', '%s', 'c++接口', '%s', tables('%s'), tables('%s'), SYSTIMESTAMP, %d)"
            , this->__m_username.c_str(), this->__m_ip_.c_str(), operation.c_str(), this->__m_db_.c_str(),
            this->__m_tb_.c_str(), exec_result);

    this->__m_logger_sql_ = sqlStr;
    if (!this->__insert(__m_logger_sql_)) {
        std::cout << "insert error." << std::endl;
    }
    return true;
}

bool Logger::insertRecord(std::string &db_name, std::string &table_name, std::string operation, bool exec_result) {
    char sqlStr[1024];

    sprintf(sqlStr, "INSERT INTO LOGS.LOG (user_name, ip_addr, source, operation, schemas, tables, time, result) "
            "VALUES ('%s', '%s', 'c++接口', '%s', tables('%s'), tables('%s'), SYSTIMESTAMP, %d)"
            , this->__m_username.c_str(), this->__m_ip_.c_str(), operation.c_str(), db_name.c_str(),
            table_name.c_str(), exec_result);
    this->__m_logger_sql_ = sqlStr;

    if (!this->__insert(__m_logger_sql_)) {
        std::cout << "insert error." << std::endl;
    }
    return true;
}

Logger::~Logger() {
    this->__m_rt = dpi_logout(this->__m_hcon);

    if (!DSQL_SUCCEEDED(this->__m_rt)) {
        this->__dpiErrorMsgPrint(DSQL_HANDLE_DBC, this->__m_hcon);
        exit(-1);
    }
    printf("========== Logger: disconnect from server success! ==========\n");

    // 释放连接句柄和环境句柄 语句句柄每次执行已释放
    this->__m_rt = dpi_free_con(this->__m_hcon);
    this->__m_rt = dpi_free_env(this->__m_henv);
    this->__m_hcon = this->__m_henv = this->__m_hstmt = nullptr;
}
