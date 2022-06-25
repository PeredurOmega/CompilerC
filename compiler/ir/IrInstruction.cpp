//
// Created by pauls on 24/06/2022.
//

#include "IrInstruction.h"
#include <sstream>

using namespace std;

ostream &IrVariable::operator<<(ostream &o) const {
    o << offset << "(%rbp)";
    return o;
}

string IrVariable::comment(const string &opType) const {
    if (name == nullptr) {
        return " # Temp " + opType;
    } else {
        return " # " + *name + " " + opType;
    }
}

ostream &IrRegister::operator<<(ostream &o) const {
    o << "%" << *registerName;
    return o;
}

string IrRegister::comment(const string &opType) const {
    if (name == nullptr) {
        return " # Temp " + opType;
    } else {
        return " # " + *name + " " + opType;
    }
}