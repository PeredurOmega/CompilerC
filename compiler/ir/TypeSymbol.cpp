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
    if (type == "int") return new PrimaryType(INT);
    else if (type == "char") return new PrimaryType(CHAR);
    else throw InvalidType();
}
