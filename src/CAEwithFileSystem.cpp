//
// Created by Bryce on 24-11-19.
//

#include "CAE.h"

#ifdef USE_FILESYSTEM

// ============================== constructor ==============================

CAE::CAE(const std::string &file_path, bool withFile = true) {
    if (withFile) {
        this->initDB_(file_path);
        this->initFileSystem_(file_path);
    } else {
        this->initDB_(file_path);
    }
    //todo�������ʼ��log����
    // todo ����ʵ������޸�
    std::string logger_username = "loguser";
    std::string logger_passwd = "SYSDBA1234";

    this->initLogger_(this->m_server_, logger_username, logger_passwd);

    if(!this->logger_obj->__getIP(file_path)) {
        std::cout<<"ip false"<<std::endl;
    }
    this->logger_obj->__getUserName(file_path);
}

// ============================== private function ==============================

bool CAE::initFileSystem_(const std::string &file_path) {
    // ��ȡyaml�ļ�
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(0);
    }
    // ��ȡ������
    std::string endpoint = data_config["fileSystem"]["endpoint"].as<std::string>();
    std::string username = data_config["fileSystem"]["username"].as<std::string>();
    std::string passwd = this->encrypt_(data_config["fileSystem"]["passwd"].as<std::string>());

    // ע�⣺ʹ��SSE-C�����迪��HTTPS���񣬷��򱨴������󣬹ر�baseurl����֤��ʹ��https����
    this->base_url = new minio::s3::BaseUrl(endpoint, false);
    this->provider = new minio::creds::StaticProvider(username, passwd);
    this->m_client_ = new minio::s3::Client(*base_url, provider);
    // ��������
    try {
        minio::s3::ListBucketsArgs args;
        minio::s3::ListBucketsResponse result = this->m_client_->ListBuckets(args);
        if (result) {
            std::cout << "========== file system :connect to server success! ==========" << std::endl;
        }
    } catch (const minio::error::Error &e) {
        std::cout << "Error: " << e << std::endl;
        exit(0);
    }
    return true;
}


void CAE::parseDBPath_(std::string path) {
    // ���ҵ�һ��б�ܣ���ȡbucket����
    size_t firstSlash = path.find('/');
    if (firstSlash == std::string::npos) {
        std::cout << "Invalid path format" << std::endl;
        return;
    }
    // ���ҵڶ���б��
    size_t secondSlash = path.find('/', firstSlash + 1);
    if (secondSlash == std::string::npos) {
        std::cout << "Invalid path format" << std::endl;
        return;
    }
    // �������һ��б�ܣ���ȡobject����
    size_t lastSlash = path.rfind('/');
    if (lastSlash == std::string::npos || lastSlash == firstSlash) {
        std::cout << "Invalid path format" << std::endl;
        return;
    }
    // ��ȡ��һ��б�ܺ͵ڶ���б��֮��Ĳ���
    this->m_bucket_ = path.substr(firstSlash + 1, secondSlash - firstSlash - 1);
    // ��ȡ�м��prefix����
    // ���ڵڶ���б�ܺ����һ��б��֮��Ĳ���
    this->m_prefix_ = path.substr(secondSlash + 1, lastSlash - secondSlash - 1);
    this->m_object_ = path.substr(lastSlash + 1);
}

bool CAE::checkFilePath_(const std::string &dbName, const std::string &tableName, const std::string &col) {
    if(this->m_FileMap_.find(dbName)==this->m_FileMap_.end()) {
        return false;
    }
    if(this->m_FileMap_.find(dbName)->second.find(tableName)==this->m_FileMap_.find(dbName)->second.end()) {
        return false;
    }
    if(this->m_FileMap_.find(dbName)->second.find(tableName)->second.find(col)==this->m_FileMap_.find(dbName)->second.find(tableName)->second.end()) {
        return false;
    }
    return true;
}

bool CAE::checkFilePath_(const std::string &dbName, const std::string &tableName) {
    if(this->m_FileMap_.find(dbName)==this->m_FileMap_.end()) {
        return false;
    }
    if(this->m_FileMap_.find(dbName)->second.find(tableName)==this->m_FileMap_.find(dbName)->second.end()) {
        return false;
    }
    return true;
}

bool CAE::checkFileExist_(std::string path) {
    // �ҵ���һ���ǿհ��ַ���λ��
    size_t start = path.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        // ȫ�ǿհ��ַ����մ�
        return false;
    }
    return true;
}

void CAE::local2FilePath_(std::string dbName, std::string tableName, const std::string &id, std::string &local_path) {
    this->m_bucket_ = this->transDBName2BucketName_(dbName);
    this->m_prefix_ = tableName + "/" + id;
    this->m_object_ = this->getFileName_(local_path);
}

std::string CAE::getFileName_(std::string path) {
    size_t pos = path.find_last_of("/");
    // ��ȡ���һ��б�ܺ���Ĳ���
    return path.substr(pos + 1);
}

std::string CAE::getTableID_(std::string &dbName, std::string &tableName) {
    return m_KeyMap_.find(dbName)->second.find(tableName)->second;
}

std::string CAE::transDBName2BucketName_(std::string dbName) {
    std::transform(dbName.begin(), dbName.end(), dbName.begin(), tolower);
    std::replace(dbName.begin(), dbName.end(), '_', '-');
//    std::cout << dbName << std::endl;
    return dbName;
}

void CAE::upperName_(std::string &dbName, std::string &tableName) {
    std::transform(dbName.begin(), dbName.end(), dbName.begin(), ::toupper);
    std::transform(tableName.begin(), tableName.end(), tableName.begin(), ::toupper);
}

void CAE::releaseFileSystem_() {
    delete this->base_url;
    this->base_url = nullptr;
    delete this->provider;
    this->provider = nullptr;
    delete this->m_client_;
    this->m_client_ = nullptr;
    std::cout << "========== file system :disconnect from server success! ==========" << std::endl;
}
// ============================== public function ==============================

bool CAE::UploadFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col,
                     std::string local_path) {
    // sql query minio path
    // 1. record exist. col not null ->  minio path
    // 2, record exist. col null ->  make path
    // 3. record not exist. mapӳ���Ӧ����->  return

    //check the parameters of the function;

    this->upperName_(dbName, tableName);
    // std::cout << dbName << " " << tableName << std::endl;
    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }

    //check the local file path.
    if (!std::filesystem::exists(local_path)) {
        std::cerr << "Error: The file does not exist at " << local_path << std::endl;
        return false;
    }

    this->m_id_ = this->getTableID_(dbName, tableName);

    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'",
            col.c_str(), dbName.c_str(), tableName.c_str(), this->m_id_.c_str(), id.c_str());

    this->m_sql_ = sqlStr;
    this->Query(this->m_sql_, this->m_res_);

    //check the record exist or not;
    if (this->m_res_.size() == 0) {
        //The record does not exist.
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }

    this->m_path_ = this->m_res_[0][0];
    //check the col path exist or not;
    if (!this->checkFileExist_(this->m_path_)) {
        //this file is not exist.
        this->local2FilePath_(dbName, tableName, id, local_path);
    } else {
        //file exist.
        this->parseDBPath_(this->m_path_);
        this->m_object_ = this->getFileName_(local_path);
    }

    //�ļ���ȡ
    std::filesystem::path zh_path(local_path);
    std::ifstream file(zh_path, std::ios::binary);

    //��ȡ�ļ���С
    file.seekg(0, std::ios::end);
    std::streamsize file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    minio::s3::PutObjectArgs args(file, file_size, 0);
    //�ϴ�·����bucket/path/path/filename, prefix=path/path/
    //bucket:this->bucket object:prefix/this->object filename:this->object
    args.bucket = this->m_bucket_;
    args.object = this->m_prefix_ + "/" + this->m_object_;
    minio::s3::PutObjectResponse resp = this->m_client_->PutObject(args);

    if (resp) {
        // std::cout << "File is successfully uploaded , updating DM..." << std::endl;
        // update��DM file path
        std::string minio_path = "/" + this->m_bucket_ + "/" + tableName + "/" + id + "/" + this->m_object_;
        sprintf(sqlStr, "UPDATE %s.%s SET %s = '%s' WHERE %s ='%s'", dbName.c_str(), tableName.c_str(),
                col.c_str(), minio_path.c_str(), m_id_.c_str(), id.c_str());
        this->m_sql_ = sqlStr;
        this->Update(this->m_sql_);
    } else {
        std::cout << "Unable to upload file:" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}

bool CAE::GetFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col,
                  std::string local_path) {

    this->upperName_(dbName, tableName);

    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }

    this->m_id_ = this->getTableID_(dbName, tableName);

    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'",
            col.c_str(), dbName.c_str(), tableName.c_str(), this->m_id_.c_str(), id.c_str());

    this->m_sql_ = sqlStr;
    this->Query(this->m_sql_, this->m_res_);

    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }

    this->m_path_ = this->m_res_[0][0];
    if (!this->checkFileExist_(this->m_path_)) {
        std::cout << "This file is not exist." << std::endl;
        return false;
    }

    this->parseDBPath_(this->m_path_);

    minio::s3::GetObjectArgs args;

    // Create a string stream to capture the data.
    std::stringstream object_data;

    args.bucket = this->m_bucket_;
    args.object = this->m_prefix_ + "/" + this->m_object_;
    std::string path = local_path + "/" + this->m_object_;

    // args.filename = local_path + "/" + this->m_object_;
    args.datafunc = [&object_data](minio::http::DataFunctionArgs args) -> bool {
        object_data.write(args.datachunk.data(), args.datachunk.size());
        // ���ļ�  ����д��
        std::ofstream outFile("./temp", std::ios::binary); // �Զ�����ģʽ���ļ�

        if (outFile.is_open()) {
            // �� stringstream �е�����д�뵽�ļ�
            outFile << object_data.str(); // ͨ�� str() ��ȡ stringstream ������
            outFile.close(); // �ر��ļ�
        } else {
            std::cerr << "operate file error." << std::endl;
        }
        return true;
    };

    // ���ض���
    minio::s3::GetObjectResponse resp = this->m_client_->GetObject(args);

    if (!resp) {
        std::cerr << "Unable to download object:" << resp.Error().String() << std::endl;
    } else {
        std::filesystem::rename("./temp", path);
    }

    return true;
}


bool CAE::GetFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col,
                  std::vector<unsigned char> &object_data) {

    this->upperName_(dbName, tableName);

    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }

    this->m_id_ = this->getTableID_(dbName, tableName);

    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'",
            col.c_str(), dbName.c_str(), tableName.c_str(), this->m_id_.c_str(), id.c_str());

    this->m_sql_ = sqlStr;
    this->Query(this->m_sql_, this->m_res_);

    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }

    this->m_path_ = this->m_res_[0][0];
    if (!this->checkFileExist_(this->m_path_)) {
        std::cout << "This file is not exist." << std::endl;
        return false;
    }

    this->parseDBPath_(this->m_path_);

    minio::s3::GetObjectArgs args;

    args.bucket = this->m_bucket_;
    args.object = this->m_prefix_ + "/" + this->m_object_;

    args.datafunc = [&object_data](minio::http::DataFunctionArgs args) -> bool {
        object_data.insert(object_data.end(), args.datachunk.begin(), args.datachunk.end());
        return true;
    };

    minio::s3::GetObjectResponse resp = this->m_client_->GetObject(args);

    if (!resp) {
        std::cout << "Unable to get data:" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}

bool CAE::DeleteFile(std::string dbName, std::string tableName, const std::string &id, const std::string &col) {

    this->upperName_(dbName, tableName);

    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }

    this->m_id_ = this->getTableID_(dbName, tableName);

    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'",
            col.c_str(), dbName.c_str(), tableName.c_str(), this->m_id_.c_str(), id.c_str());

    this->m_sql_ = sqlStr;
    this->Query(this->m_sql_, this->m_res_);

    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }

    this->m_path_ = this->m_res_[0][0];
    if (!this->checkFileExist_(this->m_path_)) {
        std::cout << "This file is not exist." << std::endl;
        return false;
    }

    this->parseDBPath_(this->m_path_);

    std::cout << "---------- Delete File ----------" << std::endl;

    minio::s3::RemoveObjectArgs args;
    args.bucket = this->m_bucket_;
    args.object = this->m_prefix_ + "/" + this->m_object_;

    minio::s3::RemoveObjectResponse resp = this->m_client_->RemoveObject(args);

    if (resp) {
        // deletel DM col path
        sprintf(sqlStr, "UPDATE %s.%s SET %s = ' '  WHERE %s ='%s'",
                dbName.c_str(), tableName.c_str(), col.c_str(), this->m_id_.c_str(), id.c_str());
        this->m_sql_ = sqlStr;
        this->Update(this->m_sql_);
    } else {
        std::cout << "Unable to delete file:" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}

bool CAE::DeleteRecord(std::string dbName, std::string tableName, const std::string &id) {
    this->upperName_(dbName, tableName);
    if (!this->checkFilePath_(dbName, tableName)) {
        std::cout << "Noting to do. There is no file." << std::endl;
        return false;
    }

    this->m_id_ = this->getTableID_(dbName, tableName);

    char sqlStr[1024];
    sprintf(sqlStr, "SELECT * FROM %s.%s WHERE %s='%s'",
            dbName.c_str(), tableName.c_str(), this->m_id_.c_str(), id.c_str());

    this->m_sql_ = sqlStr;
    this->Query(this->m_sql_, this->m_res_);

    if (this->m_res_.size() == 0) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }

    minio::s3::ListObjectsArgs args;
    args.bucket = this->transDBName2BucketName_(dbName);
    args.prefix = tableName + "/" + id + "/";

    minio::s3::ListObjectsResult result = this->m_client_->ListObjects(args);

    bool is_empty = true;
    for (; result; result++) {
        minio::s3::Item item = *result;
        if (item) {
            is_empty = false;
            std::cout << "---------- Delete File ----------" << std::endl;
            minio::s3::RemoveObjectArgs delete_args;
            delete_args.bucket = this->transDBName2BucketName_(dbName);
            delete_args.object = item.name;
            m_client_->RemoveObject(delete_args);
        } else {
            break;
        }
    }

    if (is_empty) {
        std::cout << "Folder is empty, nothing to delete." << std::endl;
        return false;
    } else {
        this->m_id_ = this->getTableID_(dbName, tableName);

        char sqlStr[1024];
        sprintf(sqlStr, "DELETE FROM %s.%s WHERE %s ='%s'",
                dbName.c_str(), tableName.c_str(), this->m_id_.c_str(), id.c_str());

        this->m_sql_ = sqlStr;
        this->Delete(this->m_sql_);
    }
    return true;
}

#endif
