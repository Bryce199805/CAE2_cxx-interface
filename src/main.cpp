//
// Created by Bryce on 24-9-27.
//

#include <iostream>
#include "CAE.h"
#include "DBVariant.h"

int main() {

    CAE obj("../config.yaml");
    std::string query_sql = "select * from BASIC_SHIP_INFORMATION_DB.SHIP_DATA_INFO";
    // std::string query_sql = "select * FROM TEST.T_JSON_OBJECT WHERE JSON_VALUE(c1, '$.name') = '张三'";
    // 查询测试
    std::vector<std::vector<std::string>> result1;
    std::vector<std::vector<DBVariant>> result2;
    std::vector<int> col_types;
    if(obj.Query(query_sql, result1)) {
        obj.printResult(result1);
    }

    if(obj.Query(query_sql, result2, col_types)) {
        obj.printResult(result2, col_types);
    }

    // std::string insert_sql = "insert into TEST.USERS values (5, 'aaa', 12344, 708, 'aaa', 'aaa', 1)";
    // std::string insert_sql = "select * FROM TEST.T_JSON_OBJECT WHERE JSON_VALUE(c1, '$.姓名') = '123'";
    // obj.Insert(insert_sql);
    return 0;
}
