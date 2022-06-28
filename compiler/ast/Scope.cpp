//
// Created by pauls on 15/06/2022.
//

#include <iostream>
#include <utility>
#include "Scope.h"
#include "Declaration.h"
#include "Prog.h"

void Scope::setOwner(Scope *_owner) {
    owner = _owner;
    label = owner->label;
    globalScope = owner->globalScope;
}

int Scope::getNewLabel() {
    *label = *label + 1;
    return *label;
}

IrVariable *Scope::getIrVariable(string *varName) {
    if (varTable.find(*varName) == varTable.end()) {
        if (owner != nullptr) return owner->getIrVariable(varName);
        auto staticVar = globalScope->getStaticIrVariable(varName);
        if (staticVar != nullptr) {
            return staticVar;
        } else {
            UndefinedVariable e = UndefinedVariable();
            cerr << e.what() << " '" << *varName << "'"; //TODO
            throw e;
        }
    } else {
        usedVar.insert(pair(*varName, true));
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
    globalScope->declareStaticVariable(sDeclaration);
}

void Scope::warnAboutUnusedVariables() {
    for (auto &it: varTable) {
        if (usedVar.find(it.first) == usedVar.end()) {
            cerr << "Warning: unused variable '" << it.first << "'." << endl;
        }
    }
}
