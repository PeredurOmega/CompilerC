//
// Created by pauls on 24/06/2022.
//

#include "IrInstruction.h"
#include <sstream>

using namespace std;

string IrVariable::comment(const string &opType) const {
    if (name == nullptr) {
        return " # Temp " + opType;
    } else {
        return " # " + *name + " " + opType;
    }
}

ostream &operator<<(ostream &o, IrVariable *var) {
    if (dynamic_cast<IrRegister *>(var) != nullptr) {
        o << (IrRegister *) var;
    } else {
        o << var->offset << "(%rbp)";
    }
    return o;
}

ostream &operator<<(ostream &o, IrRegister *var) {
    o << "%" << *(var->registerName);
    return o;
}

string IrRegister::comment(const string &opType) const {
    if (name == nullptr) {
        return " # Temp " + opType;
    } else {
        return " # " + *name + " " + opType;
    }
}