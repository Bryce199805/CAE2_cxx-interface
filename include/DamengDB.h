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

public:
    DamengDB(char* dm_server, char* dm_user, char* dm_pwd);
    void connectTest();

};

#endif //DAMENGDB_H
