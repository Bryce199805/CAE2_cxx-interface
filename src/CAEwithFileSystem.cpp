//
// Created by Bryce on 24-11-19.
//


#include "CAE.h"

#ifdef USE_FILESYSTEM

// constructor

CAE::CAE(const std::string &file_path, bool withFile = true) {
    if (withFile) {
        this->initDB_(file_path);
        this->initFileSystem_(file_path);
    } else {
        this->initDB_(file_path);
    }
}

// private function
bool CAE::initFileSystem_(const std::string &file_path) {
    // 读取yaml文件
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(0);
    }
    // 提取配置项
    std::string endpoint = data_config["minio"]["endpoint"].as<std::string>();
    std::string username = data_config["minio"]["username"].as<std::string>();
    std::string passwd = data_config["minio"]["passwd"].as<std::string>();

    // 注意：使用SSE-C加密需开启HTTPS服务，否则报错，开启后，关闭baseurl的验证并使用https连接
    this->base_url = new minio::s3::BaseUrl(endpoint, false);
    this->provider = new minio::creds::StaticProvider(username, passwd);
    this->m_client_ = new minio::s3::Client(*base_url, provider);
    // 测试连接
    try {
        minio::s3::ListBucketsArgs args;
        minio::s3::ListBucketsResponse result = this->m_client_->ListBuckets(args);
        if (result) {
            std::cout << "FileSystem connection successful." << std::endl;
        }
    } catch (const minio::error::Error &e) {
        std::cout << "Error: " << e << std::endl;
        exit(0);
    }
    return true;
}


bool CAE::parseDBPath_(std::string &path) {
    std::stringstream ss(path);

    std::string token;
    // 临时存储路径字段
    std::vector<std::string> fields;
    // 按 '/' 分割路径并存储到 fields 中
    while (getline(ss, token, '/')) {
        if (!token.empty()) {  // 跳过空字符串
            fields.push_back(token);
        }
    }
    // 将字段逐个赋值给传入的变量
    this->m_bucket_ = fields[0];
    this->m_filepath_ = fields[1] + "/" + fields[2];
    this->m_object_ = fields[3];
    return true;
}

bool CAE::checkFilePath_(std::string dbName, std::string tableName, std::string col) {
    std::unordered_set<std::string> it = this->m_FileMap_.find(dbName)->second.find(tableName)->second;
    if (it.find(col) != it.end())
        return true;
    return false;
}

bool CAE::local2FilePath_(std::string &dbName, std::string tableName, std::string id, std::string &path) {
    // 转小写 -替换_
    std::transform(dbName.begin(), dbName.end(), dbName.begin(), ::tolower);
    std::replace(dbName.begin(), dbName.end(), '_', '-');
    // 提取最后一个斜杠后面的部分
    size_t pos = path.find_last_of("/");


    this->m_bucket_ = dbName;
    this->m_filepath_ = tableName + "/" + id;
    this->m_object_ = path.substr(pos + 1);
}

//bool CAE::getLocalName_(std::string path) {
//    size_t pos = path.find_last_of("/");
//    if (pos != std::string::npos) {
//        // 提取最后一个斜杠后面的部分
//        this->m_object_ = path.substr(pos + 1);
//    }
//}

//public function

bool
CAE::UploadFile(std::string dbName, std::string tableName, std::string id, std::string col, std::string local_path) {
    // sql query minio path
    // 1. record exist. col not null ->  minio path
    // 2, record exist. col null ->  make path
    // 3. record not exist. map映射对应不上->  return
    //check the parameters of the function;
    if (!std::filesystem::exists(local_path)) {
        std::cerr << "Error: The file does not exist at " << local_path << std::endl;
        return false;
    }
    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(), "HULL_ID",
            id.c_str());
    this->m_sql_ = sqlStr;

    this->Query(this->m_sql_, this->m_res_);
    //check the record exist or not;
    if (this->m_res_.size() == 0) {
        //The record does not exist.
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }
    std::string path = this->m_res_[0][0];

    //check the col path exist or not;
    if (path == "" || path == " ") {
        //this file is not exist.
        this->local2FilePath_(dbName, tableName, id, local_path);
    } else {
        //file exist.
        this->parseDBPath_(path);
    }
    std::string bucket = this->m_bucket_;
    std::string filepath = this->m_filepath_;
    std::string object = this->m_object_;

    std::cout << "m_bucket_: " << bucket << std::endl;
    std::cout << "m_filepath_: " << filepath << std::endl;
    std::cout << "m_object_: " << object << std::endl;

    minio::s3::UploadObjectArgs args;
    args.bucket = this->m_bucket_;
    args.object = this->m_filepath_ + "/" + this->m_object_;
    args.filename = this->m_object_;
    minio::s3::UploadObjectResponse resp = this->m_client_->UploadObject(args);

    if (resp) {
        std::cout << "object is successfully uploaded" << std::endl;
        // update　DM file path
        char sqlStr[1024];
        std::string minio_path = this->m_bucket_ + "/" + tableName + "/" + id + this->m_object_;
        sprintf(sqlStr, "UPDATE %s.%s SET %s = %s WHERE %s ='%s'", dbName.c_str(), tableName.c_str(), col.c_str(),
                minio_path.c_str(), "HULL_ID", id.c_str());
        this->m_sql_ = sqlStr;
        std::cout << this->m_sql_ << std::endl;
        this->Update(this->m_sql_);

    } else {
        std::cout << "unable to upload object" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}


bool CAE::GetFile(std::string dbName, std::string tableName, std::string id, std::string col, std::string local_path) {
    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }
    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(), "HULL_ID",
            id.c_str());
    this->m_sql_ = sqlStr;

    this->Query(this->m_sql_, this->m_res_);
    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }
    std::string path = this->m_res_[0][0];
    if (path == "" || path == " ") {
        std::cout << "this file is not exist." << std::endl;
        return false;
    }
    this->parseDBPath_(m_res_[0][0]);

    std::string bucket = this->m_bucket_;
    std::string filepath = this->m_filepath_;
    std::string object = this->m_object_;

    std::cout << "m_bucket_: " << bucket << std::endl;
    std::cout << "m_filepath_: " << filepath << std::endl;
    std::cout << "m_object_: " << object << std::endl;


    minio::s3::DownloadObjectArgs args;

    args.bucket = this->m_bucket_;
    args.object = this->m_filepath_ + "/" + this->m_object_;
    args.filename = local_path + "/" + this->m_object_;
    minio::s3::DownloadObjectResponse resp = this->m_client_->DownloadObject(args);

    // Handle response.
    if (resp) {
        std::cout << "m_object_ is successfully downloaded" << std::endl;
    } else {
        std::cout << "unable to download m_object_" << resp.Error().String() << std::endl;
        return false;
    }

    return true;
}


bool CAE::GetFile(std::string dbName, std::string tableName, std::string id, std::string col,
                  std::vector<unsigned char> &object_data) {
    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }

    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(), "HULL_ID",
            id.c_str());
    this->m_sql_ = sqlStr;

    this->Query(this->m_sql_, this->m_res_);

    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }
    std::string path = this->m_res_[0][0];
    if (path == "" || path == " ") {
        std::cout << "this file is not exist." << std::endl;
        return false;
    }

    this->parseDBPath_(this->m_res_[0][0]);

    std::string bucket = this->m_bucket_;
    std::string filepath = this->m_filepath_;
    std::string object = this->m_object_;

    std::cout << "m_bucket_: " << bucket << std::endl;
    std::cout << "m_filepath_: " << filepath << std::endl;
    std::cout << "m_object_: " << object << std::endl;

    minio::s3::GetObjectArgs args;

    args.bucket = this->m_bucket_;
    args.object = this->m_filepath_ + "/" + this->m_object_;

    args.datafunc = [&object_data](minio::http::DataFunctionArgs args) -> bool {
        object_data.insert(object_data.end(), args.datachunk.begin(), args.datachunk.end());
        return true;
    };

    minio::s3::GetObjectResponse resp = this->m_client_->GetObject(args);
    if (resp) {
        std::cout << "data received successfully" << std::endl;

    } else {
        std::cout << "unable to get m_object_" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}

bool CAE::DeleteFile(std::string dbName, std::string tableName, std::string id, std::string col) {
    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }
    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(), "HULL_ID",
            id.c_str());
    this->m_sql_ = sqlStr;

    this->Query(this->m_sql_, this->m_res_);
    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }

    std::string path = this->m_res_[0][0];
    if (path == "" || path == " ") {
        std::cout << "this file is not exist." << std::endl;
        return false;
    }

    this->parseDBPath_(path);

    minio::s3::RemoveObjectArgs args;
    args.bucket = this->m_bucket_;
    args.object = this->m_filepath_ + "/" + this->m_object_;
    minio::s3::RemoveObjectResponse resp = this->m_client_->RemoveObject(args);

    if (resp) {
        std::cout << "m_object_ is successfully deleted" << std::endl;
        // deletel DM col path
        char sqlStr[1024];
        sprintf(sqlStr, "UPDATE %s.%s SET %s = ' '  WHERE %s ='%s'", dbName.c_str(), tableName.c_str(), col.c_str(),
                "HULL_ID", id.c_str());
        this->m_sql_ = sqlStr;
        std::cout << this->m_sql_ << std::endl;
        this->Update(this->m_sql_);

    } else {
        std::cout << "unable to delete m_object_" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}

bool CAE::DeleteRecord(std::string dbName, std::string tableName, std::string id) {
    // if  have file
    // if can delete dir -> delete minio-id dir
    // if can't delete -> delete file one by one
    // this->Detete()
    if (!this->checkFilePath_(dbName, tableName, "HULL_3D_MODEL")) {
        std::cout << "Noting to do. There is no file." << std::endl;
        return false;
    }
    minio::s3::ListObjectsArgs args;
    args.bucket = dbName;
    minio::s3::ListObjectsResult result = this->m_client_->ListObjects(args);
    for (; result; result++) {
        minio::s3::Item item = *result;
        if (item) {
            minio::s3::RemoveObjectArgs delete_args;
            delete_args.bucket = dbName;
            delete_args.object = item.name;

            m_client_->RemoveObject(delete_args);  // 删除对象
        }
    }
    return true;

}


#endif
