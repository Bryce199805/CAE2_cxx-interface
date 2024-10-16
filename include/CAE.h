//
// Created by Bryce on 24-9-26.
//

#ifndef CAE_H
#define CAE_H

#include <string>
#include <iostream>
#include <any>
#include <variant>


#include "DBVariant.h"
#include "DPI.h"
#include "DPIext.h"
#include "DPItypes.h"
#include "yaml-cpp/yaml.h"

class CAE {
private:
    dhenv m_henv_;   // 环境句柄
    dhcon m_hcon_;   // 连接句柄
    dhstmt m_hstmt_; // 语句句柄
    dhdesc m_hdesc_; // 描述符句柄
    DPIRETURN m_rt_; // 函数返回值

    bool isValidSQLCommand_(const std::string &sql, const std::string type);
    void dpiErrorMsgPrint_(sdint2 hndl_type, dhandle hndl);

#ifdef USE_FILESYSTEM
    // 定义文件系统私有成员

#endif

public:
    CAE(const std::string &file_path);
    ~CAE();
    void connectTest();

    bool Query(std::string &sql_str, std::vector<std::vector<std::string>>& res);
    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>>& res);
    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>>& res, std::vector<int>& col_types);

    bool Delete(std::string &sql_str);
    bool Update(std::string &sql_str);
    bool Insert(std::string &sql_str);

    void printResult(std::vector<std::vector<std::string>>& res);
    void printResult(std::vector<std::vector<DBVariant>>& res, std::vector<int>& col_types);


#ifdef USE_FILESYSTEM
    void FileTest();
#endif

};

#endif //CAE_H
