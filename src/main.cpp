//
// Created by Bryce on 24-9-27.
//

#include <iostream>
#include "DamengDB.h"

int main() {
    DamengDB obj("../config.yaml");
    std::string query_sql = "select * from TEST.USERS";
    obj.Query(query_sql);
    std::string insert_sql = "insert into TEST.USERS values (5, 'aaa', 12344, 708, 'aaa', 'aaa', 1)";
    obj.Insert(insert_sql);

}