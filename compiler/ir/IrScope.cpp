//
// Created by pauls on 15/06/2022.
//

#include <iostream>
#include "IrScope.h"

int IrScope::getOffset(string &varName) {
    if (symbolTable.find(varName) == symbolTable.end()) {
        if (owner != nullptr) return owner->getOffset(varName);
        else {
            UndefinedVariable e = UndefinedVariable();
            cerr << e.what() << " '" << varName << "'";//TODO
            throw e;
        }
    } else {
        int offset = symbolTable.at(varName);
        if (offset == 0) insertInitializedVariable(varName);
        return symbolTable.at(varName);
    }
}

void IrScope::insertInitializedVariable(string &varName) {
    currentOffset -= 4;
    symbolTable[varName] = currentOffset;
}

void IrScope::insertParameter(string &varName, int offset) {
    symbolTable[varName] = offset;
}

void IrScope::insertDeclaration(string &varName) {
    // Offset equals to zero means the value has been declared but not
    // initialized yet - Useful for DCE
    symbolTable[varName] = 0;
}

int IrScope::insertTempVariable() {
    currentOffset -= 4;
    return currentOffset;
}

void IrScope::setOwner(IrScope *_owner) {
    currentOffset = _owner->currentOffset;
    owner = _owner;
    label = owner->label;
}

int IrScope::getNewLabel() {
    *label = *label + 1;
    return *label;
}

IrScope::IrScope() : IrInstruction() {

}

set<string *> *IrScope::use() {
    return nullptr;
}

set<string *> *IrScope::def() {
    return nullptr;
}

