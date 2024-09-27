//
// Created by Bryce on 24-9-27.
//

#include <iostream>
#include "DamengDB.h"

int main() {
    DamengDB obj("192.168.8.201:5236","SYSDBA","SYSDBA");
    obj.connectTest();
}