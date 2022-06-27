//
// Created by pauls on 16/06/2022.
//

#include <iostream>
#include "Declaration.h"

void Declaration::addRawDeclaration(RawDeclaration *rawDec) {
    declarations.push_back(rawDec);
}

void Declaration::linearize(IrFunction *fun) {
    for (auto d: declarations) {
        fun->currentScope->insertDeclaration(*d->name);
        if (d->init != nullptr) {
            d->init->assignTo = d->name;
            // Init is the first thing to happen in C
            owner->declareVariable(d->name, type);
            d->init->linearize(fun);
        } else {
            owner->declareVariable(d->name, type);
            // Nothing to do when declaring new variables without initializing them
        }
    }
}

void Declaration::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    for (auto d: declarations) {
        if (d->init != nullptr) {
            d->init->setOwner(owner);
        }
    }
}

void StaticDeclaration::linearize(IrFunction *fun) {
}

void StaticDeclaration::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
}

void StaticDeclaration::renderX86(ostream &o) const {
    o << *name << ": " << endl;
    o << "    .long   " << init << endl;
}
