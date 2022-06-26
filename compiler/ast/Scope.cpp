//
// Created by pauls on 15/06/2022.
//

#include <iostream>
#include "Scope.h"

int Scope::currentOffset = 0;

int Scope::getOffset(string *varName) {
    if (varName == nullptr) {
        return insertTempVariable();
    } else if (symbolTable.find(*varName) == symbolTable.end()) {
        if (owner != nullptr) return owner->getOffset(varName);
        else {
            UndefinedVariable e = UndefinedVariable();
            cerr << e.what() << " '" << *varName << "'";//TODO
            throw e;
        }
    } else {
        int offset = symbolTable.at(*varName);
        if (offset == 0) insertInitializedVariable(*varName);
        return symbolTable.at(*varName);
    }
}

int Scope::insertInitializedVariable(string &varName) {
    currentOffset -= 4;
    symbolTable[varName] = currentOffset;
    return currentOffset;
}

void Scope::insertParameter(string &varName, int offset) {
    symbolTable[varName] = offset;
}

void Scope::insertDeclaration(string &varName) {
    // Offset equals to zero means the value has been declared but not
    // initialized yet - Useful for DCE
    symbolTable[varName] = 0;
}

int Scope::insertTempVariable() {
    currentOffset -= 4;
    symbolTable["Temp_" + to_string(currentOffset)] = currentOffset; // TODO Fix
    return currentOffset;
}

void Scope::setOwner(Scope *_owner) {
    owner = _owner;
    label = owner->label;
}

int Scope::getNewLabel() {
    *label = *label + 1;
    return *label;
}