//
// Created by pauls on 27/06/2022.
//

#include <iostream>
#include "IrScope.h"
#include "../ast/Scope.h"

int IrScope::getOffset(string *varName) {
    if (varName == nullptr) {
        return insertTempVariable();
    } else if (symbolTable.find(*varName) == symbolTable.end()) {
        if (parent != nullptr) return parent->getOffset(varName);
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

int IrScope::insertInitializedVariable(string &varName) {
    symbolTable[varName] = incrementOffset(4);
    return currentOffset;
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
    return incrementOffset(4);
}

int IrScope::incrementOffset(int offset) {
    currentOffset -= offset;
    owner->stackSize = min(owner->stackSize, currentOffset);
    return currentOffset;
}

IrScope::IrScope(IrFunction *owner) : owner(owner), parent(owner->currentScope) {
    if (parent != nullptr) {
        currentOffset = parent->currentOffset;
    }
}

void IrScope::syncOffset() {
    if (parent != nullptr) {
        parent->syncOffset();
        if (currentOffset > parent->currentOffset) {
            currentOffset = parent->currentOffset;
        }
    }
}
