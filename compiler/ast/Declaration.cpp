//
// Created by pauls on 16/06/2022.
//

#include <iostream>
#include "Declaration.h"

void Declaration::addRawDeclaration(RawDeclaration *rawDec) {
    declarations.push_back(rawDec);
}

vector<IrInstruction *> *Declaration::linearize() {
    auto *instr = new vector<IrInstruction *>();
    for (auto d: declarations) {
        if (d->init != nullptr) {
            d->init->assignTo = d->name;
            // Init is the first thing to happen in C
            owner->insertInitializedVariable(*d->name);
            auto *l = d->init->linearize();
            instr->insert(instr->end(), l->begin(), l->end());
        } else {
            owner->insertDeclaration(*d->name);
            // Nothing to do when declaring new variables without initializing them
        }
    }
    return instr;
}

void Declaration::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    for (auto d: declarations) {
        if (d->init != nullptr) {
            d->init->setOwner(owner);
        }
    }
}
