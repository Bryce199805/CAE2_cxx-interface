//
// Created by Bryce on 24-9-26.
//

#ifndef CAE_H
#define CAE_H


#include <string>
#include <iostream>
#include <unordered_set>
#include <variant>

#include "DBVariant.h"
#include "DPI.h"
#include "DPIext.h"
#include "DPItypes.h"
#include "yaml-cpp/yaml.h"

#include <complex>
#include <unordered_set>
#include "miniocpp/client.h"
#include <filesystem>

#undef GetObject

#undef DeleteFile


class CAE {
private:
    dhenv m_henv_;   // 环境句柄
    dhcon m_hcon_;   // 连接句柄
    dhstmt m_hstmt_; // 语句句柄
    dhdesc m_hdesc_; // 描述符句柄
    DPIRETURN m_rt_; // 函数返回值

    bool isValidSQLCommand_(const std::string &sql, const std::string type);

    void dpiErrorMsgPrint_(sdint2 hndl_type, dhandle hndl);

    bool initDB_(const std::string &file_path);

#ifdef USE_FILESYSTEM
    // 定义文件系统私有成员
    std::string m_filepath_;
    std::string m_bucket_;
    std::string m_object_;
    std::string m_filename_;
    std::string m_sql_;
    std::vector<std::vector<std::string>> m_res_;

    bool initFileSystem_(const std::string &file_path);

    bool checkFilePath_(std::string dbName, std::string tableName, std::string col);

    bool local2FilePath_(std::string &dbName, std::string tableName, std::string id, std::string &path);

    bool parseDBPath_(std::string &path);

    // Map 2 Define
    // key: dbName -> tableName -> colName
    const std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<std::string>>> m_FileMap_ = {
            {"HULL_MODEL_AND_INFORMATION_DB", {
                    {"HULL_PARAMETER_INFO", {"TRANSVERSE_AREA_CURVE", "HULL_3D_MODEL", "OFFSETS_TABLE"}}
            }}
    };
    const std::unordered_map<std::string, std::unordered_set<std::string>> m_KeyMap_ = {
            {"HULL_MODEL_AND_INFORMATION_DB", {"HULL_PARAMETER_INFO", "HULL_ID"}}
    };

#endif

public:
    CAE(const std::string &file_path);

    ~CAE();
    // void connectTest(const std::string &file_path);

    bool Query(std::string &sql_str, std::vector<std::vector<std::string>> &res);

    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>> &res);

    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant>> &res, std::vector<int> &col_types);

    bool Delete(std::string &sql_str);

    bool Update(std::string &sql_str);

    bool Insert(std::string &sql_str);

    void printResult(std::vector<std::vector<std::string>> &res);

    void printResult(std::vector<std::vector<DBVariant>> &res, std::vector<int> &col_types);


#ifdef USE_FILESYSTEM
    minio::s3::BaseUrl *base_url;
    minio::creds::StaticProvider *provider;
    minio::s3::Client *m_client_ = nullptr;

    CAE(const std::string &file_path, bool withFile);

    // bool QuerywithFile(std::string sqlstr);
    bool UploadFile(std::string dbName, std::string tableName, std::string id, std::string col, std::string local_path);

    bool GetFile(std::string dbName, std::string tableName, std::string id, std::string col, std::string local_path);

    bool GetFile(std::string dbName, std::string tableName, std::string id, std::string col, std::vector<unsigned char> &object_data);

    bool DeleteFile(std::string dbName, std::string tableName, std::string id, std::string col);

    bool DeleteRecord(std::string dbName, std::string tableName, std::string id);


#endif

};

#endif //CAE_H
