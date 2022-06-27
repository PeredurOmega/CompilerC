//
// Created by pauls on 24/06/2022.
//

#include "IrInstruction.h"
#include "IrScope.h"
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
    } else if (dynamic_cast<IrStaticVariable *>(var) != nullptr) {
        o << (IrStaticVariable *) var;
    } else {
        o << var->offset << "(%rbp)";
    }
    return o;
}

void IrTempVariable::assignMemory(IrScope *scope) {
    offset = scope->insertTempVariable();
}

void IrVariable::assignMemory(IrScope *scope) {
    offset = scope->getOffset(name);
}

ostream &operator<<(ostream &o, IrRegister *var) {
    o << "%" << *(var->registerName);
    return o;
}

void IrRegister::assignMemory(IrScope *scope) {

}

/*
ostream &operator<<(ostream &o, IrArgument *var) {
    o << var->offset << "(%rbp)";
    return o;
}*/
ostream &operator<<(ostream &o, IrStaticVariable *var) {
    o << *(var->name) << "(%rip)";
    return o;
}

void IrStaticVariable::assignMemory(IrScope *scope) {

}
