//
// Created by pauls on 15/06/2022.
//

#include <iostream>
#include <utility>
#include "Scope.h"
#include "Declaration.h"

void Scope::setOwner(Scope *_owner) {
    owner = _owner;
    label = owner->label;
    staticVarTable = owner->staticVarTable;
}

int Scope::getNewLabel() {
    *label = *label + 1;
    return *label;
}

IrVariable *Scope::getIrVariable(string *varName) {
    if (varTable.find(*varName) == varTable.end()) {
        if (owner != nullptr) return owner->getIrVariable(varName);
        else if (staticVarTable->find(*varName) != staticVarTable->end()) {
            return new IrStaticVariable(varName, staticVarTable->at(*varName)->type);
        } else {
            UndefinedVariable e = UndefinedVariable();
            cerr << e.what() << " '" << *varName << "'"; //TODO
            throw e;
        }
    } else {
        return new IrVariable(varName, varTable.at(*varName));
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

PrimaryType *Scope::declareStaticVariable(StaticDeclaration *sDeclaration) {
    if (staticVarTable->find(*sDeclaration->name) != staticVarTable->end()) {
        AlreadyDeclaredVariable e = AlreadyDeclaredVariable();
        cerr << e.what() << " '" << *sDeclaration->name << "'";//TODO
        throw e;
    } else {
        staticVarTable->insert(pair(*(sDeclaration->name), sDeclaration));
        return sDeclaration->type;
    }
}
