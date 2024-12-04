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
#include <fstream>
#include <windows.h>
#undef GetObject

#undef DeleteFile


class CAE {
private:
    dhenv m_henv_; // 环境句柄
    dhcon m_hcon_; // 连接句柄
    dhstmt m_hstmt_; // 语句句柄
    dhdesc m_hdesc_; // 描述符句柄
    DPIRETURN m_rt_; // 函数返回值

    bool isValidSQLCommand_(const std::string &sql, const std::string type);

    void dpiErrorMsgPrint_(sdint2 hndl_type, dhandle hndl);

    bool initDB_(const std::string &file_path);

#ifdef USE_FILESYSTEM
    // 定义文件系统私有成员
    std::string m_bucket_; //桶名
    std::string m_prefix_; //前缀名
    std::string m_object_; //文件名
    std::string m_sql_; //sql语句
    std::string m_id_; //表中文件ID
    std::string m_path_; //查询到的文件路径
    std::vector<std::vector<DBVariant> > m_result_;
    std::vector<int> m_col_types_;

    std::vector<std::vector<std::string> > m_res_; //查询结果

    // init file system.
    bool initFileSystem_(const std::string &file_path);

    // check if the path contains file.
    bool checkFilePath_(const std::string &dbName, const std::string &tableName, const std::string &col);

    // check if the path contains file.
    bool checkFilePath_(const std::string &dbName, const std::string &tableName);

    // check if the path is null.
    bool checkFileExist_(std::string path);

    // transform the local path to file path.
    void local2FilePath_(std::string dbName, std::string tableName, const std::string &id,
                         std::string &local_path);

    // parse the file path in DM.
    void parseDBPath_(std::string path);

    // get the name of local file.
    void getFileName_(std::string &path);

    // get the file id in filesystem.
    std::string getTableID_(std::string &dbName, std::string &tableName);

    // transform the dbName, use - replace _
    std::string TransDBName_(std::string dbName);

    // transform the dbName, tableName to upper.
    void UpperName_(std::string &dbName,std::string &tableName);

    // Map 2 Define
    // key: dbName -> tableName -> colName check for file path
    const std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<std::string> > > m_FileMap_
            = {
                {
                    "HULL_MODEL_AND_INFORMATION_DB", {
                        {"HULL_PARAMETER_INFO", {"TRANSVERSE_AREA_CURVE", "HULL_3D_MODEL", "OFFSETS_TABLE"}}
                    }
                }
            };
    // key:dbName -> tableName -> id check for id
    const std::unordered_map<std::string, std::unordered_map<std::string, std::string> > m_KeyMap_ = {
        {
            "HULL_MODEL_AND_INFORMATION_DB", {
                {"HULL_PARAMETER_INFO", "HULL_ID"}
            }
        }
    };

#endif

public:
    CAE(const std::string &file_path);

    ~CAE();

    // void connectTest(const std::string &file_path);

    bool Query(std::string &sql_str, std::vector<std::vector<std::string> > &res);

    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res);

    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types);

    bool Delete(std::string &sql_str);

    bool Update(std::string &sql_str);

    bool Insert(std::string &sql_str);

    void printResult(std::vector<std::vector<std::string> > &res);

    void printResult(std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types);


#ifdef USE_FILESYSTEM
    minio::s3::BaseUrl *base_url;
    minio::creds::StaticProvider *provider;
    minio::s3::Client *m_client_ = nullptr;

    CAE(const std::string &file_path, bool withFile);

    // bool QuerywithFile(std::string sqlstr);
    bool UploadFile(std::string dbName, std::string tableName, const std::string &id,
                    const std::string &col, std::string local_path);

    bool GetFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col,
                  std::string local_path);

    bool GetFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col,
                 std::vector<unsigned char> &object_data);

    bool DeleteFile(std::string dbName, std::string tableName, const std::string &id,
                    const std::string &col);

    bool DeleteRecord(std::string dbName, std::string tableName, const std::string &id);


#endif
};

#endif //CAE_H
