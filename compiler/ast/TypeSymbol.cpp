//
// Created by pauls on 15/06/2022.
//

#include "TypeSymbol.h"


const char *InvalidType::what() const noexcept {
    return "Invalid type";
}

bool IrType::operator==(const IrType &other) const {
    return this->k == other.k;
}

bool IrType::operator==(int typeId) const {
    return this->k == typeId;
}

PrimaryType *PrimaryType::parse(const string &type) {
    if (type == "int") return new IntType();
    else if (type == "char") return new CharType();
    else throw InvalidType();
}

string PrimaryType::text(PrimaryType *type) {
    if (*type == PrimaryType::INT) {
        return "int";
    } else if (*type == PrimaryType::CHAR) {
        return "char";
    } else {
        throw exception();
    }
}
