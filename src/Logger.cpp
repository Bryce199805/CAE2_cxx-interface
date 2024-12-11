//
// Created by Bryce on 24-12-10.
//

#include "Logger.h"

Logger::Logger(std::string &serverAddr, std::string &username, std::string &passwd) {
    // ���뻷�����
    this->m_rt_ = dpi_alloc_env(&this->m_henv_);
    this->m_rt_ = dpi_set_env_attr(this->m_henv_, DSQL_ATTR_LOCAL_CODE, (dpointer) PG_UTF8, sizeof(PG_UTF8));
    // �������Ӿ��
    this->m_rt_ = dpi_alloc_con(this->m_henv_, &this->m_hcon_);
    // �������ݿ�
    this->m_rt_ = dpi_login(this->m_hcon_,
                            reinterpret_cast<sdbyte *>(serverAddr.data()),
                            reinterpret_cast<sdbyte *>(username.data()),
                            reinterpret_cast<sdbyte *>(passwd.data())
    );
    // ����
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

    /* ��ȡ������Ϣ���� */
    dpi_get_diag_rec(hndl_type, hndl, 1, &err_code, err_msg, sizeof(err_msg), &msg_len);
    std::cout << "[Logger ERROR]: Err_msg = " << err_msg << ", Err_code = " << err_code << std::endl;
}

uint32_t Logger::__ip2Int(std::string ip) {
    if (inet_pton(AF_INET, ip.c_str(), &this->m_addr_) != 1) {
        std::cerr << "Invalid IP address: " << ip << std::endl;
        return 0;
    }
    // ת��Ϊ�����ֽ���
    return ntohl(this->m_addr_.s_addr);
}

bool Logger::__ip_in_cidr(std::string ip, std::string cidr) {
    size_t pos = cidr.find('/');
    std::string cidr_ip_str = cidr.substr(0, pos);
    int netmask_len = std::stoi(cidr.substr(pos + 1));

    // ��IP��ַת��Ϊ32λ����
    uint32_t ip_value = this->__ip2Int(ip);
    // ��CIDR�����ַת��Ϊ32λ����
    uint32_t cidr_ip_value = this->__ip2Int(cidr_ip_str);

    // �����������루CIDR�������ȣ�
    uint32_t ip_mask = (0xFFFFFFFF << (32 - netmask_len)) & 0xFFFFFFFF;

    // ���IP�Ƿ���CIDR��ַ����
    return (ip_value & ip_mask) == (cidr_ip_value & ip_mask);
}

bool Logger::__getIP(const std::string &file_path) {
    // ��ȡyaml�ļ�
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(0);
    }
    // ��ȡ������
    std::string cidr = data_config["log"]["cidr"].as<std::string>();
    std::string ip;

    //PIP_ADAPTER_INFO�ṹ��ָ��洢����������Ϣ
    PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
    //�õ��ṹ���С,����GetAdaptersInfo����
    unsigned long stSize = sizeof(IP_ADAPTER_INFO);
    //����GetAdaptersInfo����,���pIpAdapterInfoָ�����;����stSize��������һ��������Ҳ��һ�������
    int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    if (ERROR_BUFFER_OVERFLOW == nRel) {
        //����������ص���ERROR_BUFFER_OVERFLOW
        //��˵��GetAdaptersInfo�������ݵ��ڴ�ռ䲻��,ͬʱ�䴫��stSize,��ʾ��Ҫ�Ŀռ��С
        //��Ҳ��˵��ΪʲôstSize����һ��������Ҳ��һ�������
        //�ͷ�ԭ�����ڴ�ռ�
        delete pIpAdapterInfo;
        //���������ڴ�ռ������洢����������Ϣ
        pIpAdapterInfo = (PIP_ADAPTER_INFO) new BYTE[stSize];
        //�ٴε���GetAdaptersInfo����,���pIpAdapterInfoָ�����
        nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    }
    if (ERROR_SUCCESS == nRel) {
        //���������Ϣ
        //�����ж�����,���ͨ��ѭ��ȥ�ж�
        while (pIpAdapterInfo) {
            IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
            do {
                ip = pIpAddrString->IpAddress.String;
                if (this->__ip_in_cidr(ip, cidr)) {
                    this->m_ip = ip;
                    // std::cout << this->m_ip << std::endl;
                    return true;
                }
                pIpAddrString = pIpAddrString->Next;
            } while (pIpAddrString);
            pIpAdapterInfo = pIpAdapterInfo->Next;
        }
    }
    //�ͷ��ڴ�ռ�
    if (pIpAdapterInfo) {
        delete pIpAdapterInfo;
    }
    return false;
}

bool Logger::__getUserName(const std::string &file_path) {
    // ��ȡyaml�ļ�
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(0);
    }
    // ��ȡ������
    this->m_dbusername = data_config["database"]["username"].as<std::string>();
    this->m_fsusername = data_config["fileSystem"]["username"].as<std::string>();
    return true;
}

bool Logger::__parseSQL(const std::string sql) {

    std::cout << "logger test" << std::endl;
    return true;
}

bool Logger::__insert(std::string &sql) {
    // ========== sql���׼����ִ�� ==========
    sdbyte *_sql = reinterpret_cast<sdbyte *>(sql.data());
    // ���������
    this->m_rt_ = dpi_alloc_stmt(this->m_hcon_, &this->m_hstmt_);
    // ִ��sql���
    this->m_rt_ = dpi_exec_direct(this->m_hstmt_, _sql);

    if (!DSQL_SUCCEEDED(this->m_rt_)) {
        std::cout << "[Logger ERROR]: record insert error!" << std::endl;
        this->__dpiErrorMsgPrint(DSQL_HANDLE_STMT, this->m_hstmt_);
        this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
        return false;
    }

    // �ͷ������
    this->m_rt_ = dpi_free_stmt(this->m_hstmt_);
    return true;
}

bool Logger::insertRecord(std::string &sql, std::string operation, bool exec_result) {
    // sprint ���� insert ģ�� ��ȫ�����

    char sqlStr[1024];
    sprintf(sqlStr, "INSERT INTO LOGS.LOG (user_name, ip_addr, source, operation, schemas, tables, time, result) "
            "VALUES ('%s', '%s', 'C++���ݽӿ�', '%s', tables('%s'), tables('%s'), SYSTIMESTAMP, %d)"
            , this->m_dbusername.c_str(), this->m_ip.c_str(), operation.c_str(), this->m_db_.c_str(),
            this->m_tb_.c_str(), exec_result);

    this->logger_sql = sqlStr;
    if (!this->__insert(logger_sql)) {
        std::cout << "insert error." << std::endl;
    }
    return true;
}

bool Logger::insertRecord(std::string &db_name, std::string &table_name, std::string operation, bool exec_result) {
    std::string logger_sql = "insert ...";
    char sqlStr[1024];
    sprintf(sqlStr, "INSERT INTO LOGS.LOG (user_name, ip_addr, source, operation, schemas, tables, time, result) "
        "VALUES ('%s', '%s', 'C++���ݽӿ�', '%s', tables('%s'), tables('%s'), SYSTIMESTAMP, %d)"
        , this->m_fsusername.c_str(), this->m_ip.c_str(), operation.c_str(), db_name.c_str(),
        table_name.c_str(), exec_result);

    this->logger_sql = sqlStr;

    if (!this->__insert(logger_sql)) {
        std::cout << "insert error." << std::endl;
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

    // �ͷ����Ӿ���ͻ������ �����ÿ��ִ�����ͷ�
    this->m_rt_ = dpi_free_con(this->m_hcon_);
    this->m_rt_ = dpi_free_env(this->m_henv_);
    this->m_hcon_ = this->m_henv_ = this->m_hstmt_ = nullptr;
}
