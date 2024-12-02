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
    // ��ȡyaml�ļ�
    YAML::Node data_config = YAML::LoadFile(file_path);
    if (!data_config) {
        std::cout << "Open config File:" << file_path << " failed.";
        exit(0);
    }
    // ��ȡ������
    std::string endpoint = data_config["minio"]["endpoint"].as<std::string>();
    std::string username = data_config["minio"]["username"].as<std::string>();
    std::string passwd = data_config["minio"]["passwd"].as<std::string>();

    // ע�⣺ʹ��SSE-C�����迪��HTTPS���񣬷��򱨴������󣬹ر�baseurl����֤��ʹ��https����
    this->base_url = new minio::s3::BaseUrl(endpoint, false);
    this->provider = new minio::creds::StaticProvider(username, passwd);
    this->m_client_ = new minio::s3::Client(*base_url, provider);
    // ��������
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


void CAE::parseDBPath_(const std::string &path) {
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
    std::unordered_set<std::string> it = this->m_FileMap_.find(dbName)->second.find(tableName)->second;
    if (it.find(col) != it.end())
        return true;
    return false;
}

bool CAE::checkFilePath_(const std::string &dbName, const std::string &tableName) {
    std::unordered_map<std::string, std::unordered_set<std::string> > it = this->m_FileMap_.find(dbName)->second;
    if (it.find(tableName) != it.end())
        return true;
    return false;
}

bool CAE::checkFileNull_(std::string path) {
    // �ҵ���һ���ǿհ��ַ���λ��
    size_t start = path.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        // ȫ�ǿհ��ַ����մ�
        return false;
    }
    return true;
}

void CAE::local2FilePath_(const std::string &dbName, const std::string &tableName, const std::string &id,
                          const std::string &local_path) {
    std::string dbname = dbName;
    std::string path = local_path;
    // תСд -�滻_
    std::transform(dbname.begin(), dbname.end(), dbname.begin(), tolower);
    std::replace(dbname.begin(), dbname.end(), '_', '-');
    this->m_bucket_ = dbname;
    this->m_prefix_ = tableName + "/" + id;
    this->m_object_ = this->getLocalName_(path);
}

std::string CAE::getLocalName_(std::string &path) {
    size_t pos = path.find_last_of("/");
    // ��ȡ���һ��б�ܺ���Ĳ���
    path = path.substr(pos + 1);
    return path;
}

std::string CAE::getTableID_(const std::string &dbName, const std::string &tableName) {
    return m_KeyMap_.find(dbName)->second.find(tableName)->second;
}

std::string CAE::TransDBName_(const std::string &dbName) {
    std::string dbname = dbName;
    std::transform(dbname.begin(), dbname.end(), dbname.begin(), tolower);
    std::replace(dbname.begin(), dbname.end(), '_', '-');
    return dbname;
}

//public function

bool CAE::UploadFile(const std::string &dbName, const std::string &tableName, const std::string &id,
                     const std::string &col,
                     const std::string &local_path) {
    // sql query minio path
    // 1. record exist. col not null ->  minio path
    // 2, record exist. col null ->  make path
    // 3. record not exist. mapӳ���Ӧ����->  return

    //check the parameters of the function;
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
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(),
            this->m_id_.c_str(), id.c_str());
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
    if(this->checkFileNull_(path)) {
        //this file is not exist.
        this->local2FilePath_(dbName, tableName, id, local_path);
    }else {
        //file exist.
        this->parseDBPath_(path);
    }

    //�Զ����ƴ��ļ�
    std::ifstream file(local_path, std::ios::binary);
    //��ȡ�ļ���С
    file.seekg(0, std::ios::end);
    std::streamsize file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    //print the path for check.
    // std::string bucket = this->m_bucket_;
    // std::string prefix = this->m_prefix_;
    // std::string object = this->m_object_;
    //
    // std::cout << "m_bucket_: " << bucket << std::endl;
    // std::cout << "m_prefix_: " << prefix << std::endl;
    // std::cout << "m_object_: " << object << std::endl;

    minio::s3::PutObjectArgs args(file, file_size, 0);
    //�ϴ�·����bucket/path/path/filename, prefix=path/path/
    //bucket:this->bucket object:prefix/this->object filename:this->object
    args.bucket = this->m_bucket_;
    args.object = this->m_prefix_ + "/" + this->m_object_;
    minio::s3::PutObjectResponse resp = this->m_client_->PutObject(args);

    if (resp) {
        // std::cout << "File is successfully uploaded , updating DM..." << std::endl;
        // update��DM file path
        this->m_id_ = this->getTableID_(dbName, tableName);
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

bool CAE::GetFile(const std::string &dbName, const std::string &tableName, const std::string &id,
                  const std::string &col, const std::string &local_path) {
    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }
    this->m_id_ = this->getTableID_(dbName, tableName);
    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(),
            this->m_id_.c_str(),
            id.c_str());
    this->m_sql_ = sqlStr;

    this->Query(this->m_sql_, this->m_res_);
    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }
    std::string path = this->m_res_[0][0];
    if(this->checkFileNull_(path)) {
        std::cout << "This file is not exist." << std::endl;
        return false;
    }
    this->parseDBPath_(m_res_[0][0]);

    minio::s3::DownloadObjectArgs args;

    args.bucket = this->m_bucket_;
    args.object = this->m_prefix_ + "/" + this->m_object_;
    args.filename = local_path + "/" + this->m_object_;
    minio::s3::DownloadObjectResponse resp = this->m_client_->DownloadObject(args);

    // Handle response.
    if (!resp) {
        std::cout << "Unable to download object:" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}


bool CAE::GetFile(const std::string &dbName, const std::string &tableName, const std::string &id,
                  const std::string &col,
                  std::vector<unsigned char> &object_data) {
    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }
    this->m_id_ = this->getTableID_(dbName, tableName);
    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(),
            this->m_id_.c_str(),
            id.c_str());
    this->m_sql_ = sqlStr;

    this->Query(this->m_sql_, this->m_res_);

    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }
    std::string path = this->m_res_[0][0];
    if(this->checkFileNull_(path)) {
        std::cout << "This file is not exist." << std::endl;
        return false;
    }
    this->parseDBPath_(this->m_res_[0][0]);

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

bool CAE::DeleteFile(const std::string &dbName, const std::string &tableName, const std::string &id,
                     const std::string &col) {
    if (!this->checkFilePath_(dbName, tableName, col)) {
        std::cout << "Error: check your dbname/tablename/colname." << std::endl;
        return false;
    }
    this->m_id_ = this->getTableID_(dbName, tableName);
    char sqlStr[1024];
    sprintf(sqlStr, "SELECT %s FROM %s.%s WHERE %s='%s'", col.c_str(), dbName.c_str(), tableName.c_str(),
            this->m_id_.c_str(),
            id.c_str());
    this->m_sql_ = sqlStr;

    this->Query(this->m_sql_, this->m_res_);
    if (this->m_res_.size() == 0) {
        std::cout << "Error: The record does not exist." << std::endl;
        return false;
    }

    std::string path = this->m_res_[0][0];
    if(this->checkFileNull_(path)) {
        std::cout << "This file is not exist." << std::endl;
        return false;
    }
    this->parseDBPath_(path);
    std::cout << "---------- Delete File ----------" << std::endl;
    minio::s3::RemoveObjectArgs args;
    args.bucket = this->m_bucket_;
    args.object = this->m_prefix_ + "/" + this->m_object_;
    minio::s3::RemoveObjectResponse resp = this->m_client_->RemoveObject(args);

    if (resp) {
        // deletel DM col path
        sprintf(sqlStr, "UPDATE %s.%s SET %s = ' '  WHERE %s ='%s'", dbName.c_str(), tableName.c_str(),
                col.c_str(), this->m_id_.c_str(), id.c_str());
        this->m_sql_ = sqlStr;
        this->Update(this->m_sql_);
    } else {
        std::cout << "Unable to delete file:" << resp.Error().String() << std::endl;
        return false;
    }
    return true;
}

bool CAE::DeleteRecord(const std::string &dbName, const std::string &tableName, const std::string &id) {
    if (!this->checkFilePath_(dbName, tableName)) {
        std::cout << "Noting to do. There is no file." << std::endl;
        return false;
    }
    minio::s3::ListObjectsArgs args;
    args.bucket = this->TransDBName_(dbName);
    args.prefix = tableName + "/" + id + "/";

    minio::s3::ListObjectsResult result = this->m_client_->ListObjects(args);
    bool is_empty = true;
    for (; result; result++) {
        minio::s3::Item item = *result;
        if (item) {
            is_empty = false;
            std::cout << "---------- Delete File ----------" << std::endl;
            minio::s3::RemoveObjectArgs delete_args;
            delete_args.bucket = this->TransDBName_(dbName);
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
        sprintf(sqlStr, "DELETE FROM %s.%s WHERE %s ='%s'", dbName.c_str(), tableName.c_str(),
                this->m_id_.c_str(), id.c_str());
        this->m_sql_ = sqlStr;
        this->Delete(this->m_sql_);
    }
    return true;
}

#endif
