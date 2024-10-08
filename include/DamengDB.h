//
// Created by Bryce on 24-9-26.
//

#ifndef DAMENGDB_H
#define DAMENGDB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "DPI.h"
#include "DPIext.h"
#include "DPItypes.h"

class DamengDB {
private:
    dhenv m_henv;   // 环境句柄
    dhcon m_hcon;   // 连接句柄
    dhstmt m_hstmt; // 语句句柄
    dhdesc m_hdesc; // 描述符句柄
    DPIRETURN m_rt; // 函数返回值

    void dpiErrorMsgPrint(sdint2 hndl_type, dhandle hndl);

#ifdef USE_FILESYSTEM
    // 定义文件系统私有成员

#endif

public:
    DamengDB(const std::string &file_path);
    ~DamengDB();
    void connectTest();

    bool Query(std::string &sql_str);
    bool Delete(std::string &sql_str);
    bool Update(std::string &sql_str);
    bool Insert(std::string &sql_str);

#ifdef USE_FILESYSTEM
    void FileTest();
#endif
};

#endif //DAMENGDB_H
