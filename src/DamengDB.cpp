//
// Created by Bryce on 24-9-26.
//

#include <iostream>
#include "DamengDB.h"

DamengDB::DamengDB(char* dm_server, char* dm_user, char* dm_pwd) {
    // 申请环境句柄
    this->m_rt = dpi_alloc_env(&this->m_henv);

    // 申请连接句柄
    this->m_rt = dpi_alloc_con(this->m_henv, &this->m_hcon);

    // 连接数据库
    this->m_rt = dpi_login(this->m_hcon,
        reinterpret_cast<signed char*>(dm_server),
        reinterpret_cast<signed char*>(dm_user),
        reinterpret_cast<signed char*>(dm_pwd)
    );

    // 测试
    if(!DSQL_SUCCEEDED(this->m_rt)) {
        dpiErrorMsgPrint(DSQL_HANDLE_DBC, this->m_hcon);
	    exit(-1);
    }

    printf("dpi: connect to server success!\n");
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
    std::cout << "connectTest" << std::endl;
}