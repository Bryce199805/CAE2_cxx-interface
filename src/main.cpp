//
// Created by Bryce on 24-9-27.
//

#include <iostream>
#include "CAE.h"
#include "DBVariant.h"

int main() {
    CAE obj("../config.yaml", true);

    // 查询测试
    std::string query_sql = "select * from BASIC_SHIP_INFORMATION_DB.SHIP_DATA_INFO";
    std::vector<std::vector<DBVariant>> result2;
    std::vector<int> col_types;

    if(obj.Query(query_sql, result2, col_types)) {
        // 输出打印测试
        obj.printResult(result2, col_types);
    }

    // 插入测试
    std::string insert_sql =
            "insert into BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO (SHIP_DATA_ID, SISTER_DATA_ID, SHIP_NAME) "
            "values (7082002, 7082006, 'test No1')";
    if(obj.Insert(insert_sql)) {
        std::cout << "insert done." << std::endl;
    }

    // 更新测试
    std::string update_sql =
            "update BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO set SHIP_NAME = 'test No2' where SHIP_NAME = 'test No1'";
    if(obj.Update(update_sql)) {
        std::cout << "update done." << std::endl;
    }

    //删除测试
    std::string delete_sql =
            "delete from BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO where SHIP_NAME = 'test No2'";
    if(obj.Delete(delete_sql)) {
        std::cout << "delete done." << std::endl;
    }


    // 测试上传文件
    // todo 断点处有一个bug，上传时内部文件流出错，怀疑该函数内部使用的PutObject方法
    // todo 可以尝试使用PutObject方法，但是需要将文件流转换为二进制流
//    obj.UploadFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081002", "TRANSVERSE_AREA_CURVE", "./test.jpg");
    // 测试下载文件
     obj.GetFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081002", "TRANSVERSE_AREA_CURVE", ".");
    // 测试下载字符流
    std::vector<unsigned char> object_data;
    obj.GetFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081002", "TRANSVERSE_AREA_CURVE",object_data);
    std::cout << "object_data size: " << object_data.size() << std::endl;
    // 测试删除文件
//    obj.DeleteFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081002", "TRANSVERSE_AREA_CURVE");
    return 0;
}
