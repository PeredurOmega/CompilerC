//
// Created by pauls on 16/06/2022.
//

#include <iostream>
#include "Declaration.h"

Declaration::Declaration(PrimaryType *type) : IrInstruction(), type(type) {

}

void Declaration::addRawDeclaration(RawDeclaration *rawDec) {
    declarations.push_back(rawDec);
}

void Declaration::renderX86(ostream &o) const {
    for (auto d: declarations) {
        if (d->init != nullptr) {
            d->init->renderX86(o);
        } else {
            // Nothing to do when declaring new variables without initializing them
        }
    }
}

void Declaration::affect(IrScope *owner) {
    setOwner(owner);
    for (auto d: declarations) {
        if (d->init != nullptr) {
            d->init->assignTo = d->name;
            // Init is the first thing to happen in C
            owner->insertInitializedVariable(*d->name);
            d->init->affect(owner);
        } else {
            owner->insertDeclaration(*d->name);
        }
    }
}

RawDeclaration::RawDeclaration(string *name, Expression *init) : name(name),
                                                                 init(init) {
}
