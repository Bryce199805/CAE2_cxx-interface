//
// Created by Bryce on 24-9-26.
//

#ifndef CAE_H
#define CAE_H


#include <string>
#include <iostream>
#include <variant>

#include "DBVariant.h"
#include "DPI.h"
#include "DPIext.h"
#include "DPItypes.h"
#include "yaml-cpp/yaml.h"

#include <iomanip>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

#include "Logger.h"
#include <unordered_set>


#ifdef USE_FILESYSTEM

#include <complex>
#include "miniocpp/client.h"
#include <filesystem>
#include <fstream>
#include <windows.h>
#include <regex>
#include <thread>

#endif

#undef GetObject
#undef DeleteFile

class Logger;

class CAE {
private:
    dhenv m_henv_; // 环境句柄
    dhcon m_hcon_; // 连接句柄
    dhstmt m_hstmt_; // 语句句柄
    DPIRETURN m_rt_; // 函数返回值

    // 输出控制
    bool m_show_msg_ = true;
    const std::string m_system_msg_ = "\033[33m\033[1m[DB Message]: \033[0m";   // 黄色 加粗
    const std::string m_error_msg_ = "\033[31m\033[1m[DB Error]: \033[0m";      // 红色 加粗
    const std::string m_success_msg_ = "\033[32m\033[1m[DB Message]: \033[0m";  // 绿色 加粗

    Logger* logger_obj = nullptr;

    bool isValidSQLCommand_(const std::string &sql, const std::string type);

    void dpiErrorMsgPrint_(sdint2 hndl_type, dhandle hndl);

    bool initDB_(std::string& db_server, std::string& db_username, std::string& db_passwd);

    bool initLogger_(
        std::string& db_server, std::string& log_username, std::string& log_passwd,
        const std::string& db_username, const std::string& cidr, const bool use_log);

    std::string encrypt_(const std::string &data);

    void releaseDB_();

    void releaseLogger_();

#ifdef USE_FILESYSTEM
    // 定义文件系统私有成员

    minio::s3::BaseUrl* base_url = nullptr;
    minio::creds::StaticProvider* provider = nullptr;
    minio::s3::Client* m_client_ = nullptr;

    std::vector<std::vector<std::string>> m_res_; //查询结果
    std::vector<std::shared_ptr<std::thread>> m_threads_; //线程池
    std::vector<std::string> m_temp_path_;

    std::string m_bucket_; //桶名
    std::string m_prefix_; //前缀名
    std::string m_object_; //文件名
    std::string m_sql_; //sql语句
    std::string m_id_; //表中文件ID
    std::string m_path_; //查询到的文件路径

    // init file system.
    bool initFileSystem_(const std::string &fs_server, const std::string& fs_username, const std::string& fs_passwd);

    // check if the path contains file.
    bool checkFilePath_(const std::string &dbName, const std::string &tableName, const std::string &col);

    // check if the path contains file.
    bool checkFilePath_(const std::string &dbName, const std::string &tableName);

    // check if the path is null.
    bool checkFileExist_(std::string path);

    // check the extension of the file.
    bool checkExtension_(std::string filename, std::string col);

    // transform the local path to file path.
    void local2FilePath_(std::string dbName, std::string tableName, const std::string &id, std::string &local_path);

    // parse the file path in DM.
    void parseDBPath_(std::string path);

    void to_stl_(std::string path, std::string ext, std::string bucket, std::string object);

    // get the name of local file.
    std::string getFileName_(std::string path);

    // get the file id in filesystem.
    std::string getTableID_(std::string &dbName, std::string &tableName);

    // transform the dbName, use - replace _
    std::string transDBName2BucketName_(std::string dbName);

    // transform the dbName, tableName to upper.
    void upperName_(std::string &str);

    void lowerName_(std::string &str);

    // release the file system.
    void releaseFileSystem_();


    // Map 2 Define
    // key: dbName -> tableName -> colName check for file path
//    const std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<std::string>>>> m_FileMap_
//            = {
//                    {
//                            "HULL_MODEL_AND_INFORMATION_DB", {
//                            {
//                                "HULL_PARAMETER_INFO", {
//                                    {"TRANSVERSE_AREA_CURVE", {"png","jpg","jpeg"}, },
//                                    {"HULL_3D_MODEL",{"stp","stl","igs","step","iges"}, },
//                                    {"OFFSETS_TABLE", {"*"}}
//                                }
//                            }
//                    }
//                    }
//            };

    const std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<std::string>>> m_FileMap_
            = {
                    {
                            "HULL_MODEL_AND_INFORMATION_DB", {
                            {
                                    "HULL_PARAMETER_INFO", {"TRANSVERSE_AREA_CURVE", "HULL_3D_MODEL", "OFFSETS_TABLE"}
                            }
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

    const std::unordered_map<std::string, std::string> m_extension_pattern_ = {
            {"TRANSVERSE_AREA_CURVE", R"([^.]*\.(png|jpg|jpeg)$)"},
            {"HULL_3D_MODEL", R"([^.]*\.(stp|stl|igs|step|iges)$)"}
    };

#endif

public:
    CAE(const std::string &file_path);

    ~CAE();

    bool Query(std::string &sql_str, std::vector<std::vector<std::string> > &res);

    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res);

    bool Query(std::string &sql_str, std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types);

    bool Delete(std::string &sql_str);

    bool Update(std::string &sql_str);

    bool Insert(std::string &sql_str);

    void printResult(std::vector<std::vector<std::string> > &res);

    void printResult(std::vector<std::vector<DBVariant> > &res, std::vector<int> &col_types);


#ifdef USE_FILESYSTEM

    CAE(const std::string &file_path, bool withFile);

    // bool QuerywithFile(std::string sqlstr);
    bool UploadFile(std::string dbName, std::string tableName, const std::string &id,
                    std::string col, std::string local_path);

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
