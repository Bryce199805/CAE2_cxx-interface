//
// Created by Bryce on 24-10-14.
//

#include "DBVariant.h"

void DBVariant::setValue(const std::string& val) {
    this->m_var_ = val;
}

void DBVariant::setValue(int val) {
    this->m_var_ = val;
}

void DBVariant::setValue(float val) {
    this->m_var_ = val;
}

void DBVariant::setValue(double val) {
    this->m_var_ = val;
}

std::string DBVariant::asTypeString() {
    if (std::holds_alternative<std::string>(this->m_var_)) {
        return std::get<std::string>(this->m_var_);
    }
    throw std::bad_variant_access();
}

int DBVariant::asTypeInteger() {
    if (std::holds_alternative<int>(this->m_var_)) {
        return std::get<int>(this->m_var_);
    }
    throw std::bad_variant_access();
}

float DBVariant::asTypeFloat() {
    if (std::holds_alternative<float>(this->m_var_)) {
        return std::get<float>(this->m_var_);
    }
    throw std::bad_variant_access();
}

double DBVariant::asTypeDouble() {
    if (std::holds_alternative<double>(this->m_var_)) {
        return std::get<double>(this->m_var_);
    }
    throw std::bad_variant_access();
}
