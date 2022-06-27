//
// Created by pauls on 15/06/2022.
//

#include <iostream>
#include <utility>
#include "Scope.h"

void Scope::setOwner(Scope *_owner) {
    owner = _owner;
    label = owner->label;
}

int Scope::getNewLabel() {
    *label = *label + 1;
    return *label;
}

PrimaryType *Scope::getType(string *varName) {
    if (varTable.find(*varName) == varTable.end()) {
        if (owner != nullptr) return owner->getType(varName);
        else {
            UndefinedVariable e = UndefinedVariable();
            cerr << e.what() << " '" << *varName << "'"; //TODO
            throw e;
        }
    } else {
        return varTable.at(*varName);
    }
}

PrimaryType *Scope::declareVariable(string *varName, PrimaryType *type) {
    if (varTable.find(*varName) != varTable.end()) {
        AlreadyDeclaredVariable e = AlreadyDeclaredVariable();
        cerr << e.what() << " '" << *varName << "'";//TODO
        throw e;
    } else {
        return varTable[*varName] = type;
    }
}

const IrType *Scope::getFunctionType(string functionName) {
    if (owner == nullptr) {
        return nullptr;
    } else {
        return owner->getFunctionType(std::move(functionName));
    }
}
