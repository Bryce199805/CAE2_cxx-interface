//
// Created by Bryce on 24-9-27.
//

#include <iostream>
#include "CAE.h"
#include "DBVariant.h"

int main() {
    CAE obj("../config.yaml", true);

    // 查询测试
    //    std::string query_sql = "select * from BASIC_SHIP_INFORMATION_DB.SHIP_DATA_INFO where ship_type = '油船'";
    //    std::vector<std::vector<DBVariant> > result2;
    //    std::vector<int> col_types;

    //    if (obj.Query(query_sql, result2, col_types)) {
    //        // 输出打印测试
    //        obj.printResult(result2, col_types);
    //    }

    // 插入测试
    //    std::string insert_sql =
    //            "insert into BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO (SHIP_DATA_ID, SISTER_DATA_ID, SHIP_NAME) "
    //            "values (7082002, 7082006, 'test No1')";
    //    if (obj.Insert(insert_sql)) {
    //        std::cout << "insert done." << std::endl;
    //    }

    // 更新测试
    //    std::string update_sql = "update BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO set SHIP_NAME = 'test No2' where SHIP_NAME = 'test No1'";
    //    if (obj.Update(update_sql)) {
    //        std::cout << "update done." << std::endl;
    //    }

    //删除测试
    //    std::string delete_sql = "delete from BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO where SHIP_NAME = 'test No2'";
    //    if (obj.Delete(delete_sql)) {
    //        std::cout << "delete done." << std::endl;
    //    }


    //文件操作测试

    //上传文件 指定路径，带文件名 hull_parameter_info
    if (obj.UploadFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081005", "TRANSVERSE_AREA_CURVE",
                       "../doc/blue.png")) {
        std::cout << "Upload file done." << std::endl;
    }

    // 下载文件 指定路径，不带文件名
    if (obj.GetFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081004", "PARALLEL_MIDDLE_LENGTH",
                    ".")) {
        std::cout << "Download file done." << std::endl;
    }

    //下载字符流
    std::vector<unsigned char> object_data;
    if (obj.GetFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081001", "TRANSVERSE_AREA_CURVE",
                    object_data)) {
        std::cout << "Download data stream done." << std::endl;
        std::cout << "object_data size: " << object_data.size() << std::endl;
    }

    // 删除文件
    if (obj.DeleteFile("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081001", "TRANSVERSE_AREA_CURVE")) {
        std::cout << "Delete file done." << std::endl;
    }

    //删除记录
    if (obj.DeleteRecord("HULL_MODEL_AND_INFORMATION_DB", "HULL_PARAMETER_INFO", "M7081001")) {
        std::cout << "Delete record done." << std::endl;
    }

    return 0;
}
