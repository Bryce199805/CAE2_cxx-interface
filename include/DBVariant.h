//
// Created by Bryce on 24-10-14.
//

#ifndef DBVARIANT_H
#define DBVARIANT_H

#include <variant>
#include <string>
#include <vector>


class DBVariant {
private:
    std::variant<std::string, int, float, double> m_var_;

public:
    // 默认构造函数
    DBVariant() = default;

    // 接受不同类型的构造函数
    DBVariant(const std::string& val) : m_var_(val) {
    }

    DBVariant(int val) : m_var_(val) {
    }

    DBVariant(float val) : m_var_(val) {
    }

    DBVariant(double val) : m_var_(val) {
    }

    void setValue(const std::string& val);
    void setValue(int val);
    void setValue(float val);
    void setValue(double val);

    std::string asTypeString();
    int asTypeInteger();
    float asTypeFloat();
    double asTypeDouble();
};

#endif //DBVARIANT_H
