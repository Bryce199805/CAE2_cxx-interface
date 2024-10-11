//
// Created by Bryce on 24-9-27.
//

#include <iostream>
#include "DamengDB.h"

int main() {

    DamengDB obj("../config.yaml");
    std::string query_sql = "select * from TEST.USERS";
    // std::string query_sql = "select * FROM TEST.T_JSON_OBJECT WHERE JSON_VALUE(c1, '$.name') = 'ÕÅÈý'";

    obj.Query(query_sql);
    // std::string insert_sql = "insert into TEST.USERS values (5, 'aaa', 12344, 708, 'aaa', 'aaa', 1)";
    // std::string insert_sql = "select * FROM TEST.T_JSON_OBJECT WHERE JSON_VALUE(c1, '$.ÐÕÃû') = '123'";
    // obj.Insert(insert_sql);
    return 0;
}