//
// Created by pauls on 16/06/2022.
//

#include <iostream>
#include "Declaration.h"

Declaration::Declaration(PrimaryType *type) : IrInstruction(false), type(type) {

}

void Declaration::addRawDeclaration(RawDeclaration *rawDec) {
    declarations.push_back(rawDec);
}

void Declaration::renderX86(ostream &o) const {
    for (auto d: declarations) {
        if (d->init != nullptr) {
            auto *assignment = new Assignment(*d->name, d->init);
            assignment->setOwner(owner);
            assignment->offset = owner->getOffset(*d->name);
            assignment->renderX86(o);
        } else {
            // Nothing to do when declaring new variables without initializing them
        }
    }
}

void Declaration::affect(IrScope *owner) {
    setOwner(owner);
    for (auto d: declarations) {
        if (d->init != nullptr) {
            // We don't affect constant for optimization purposes
            if(dynamic_cast<Constant *>(d->init) == nullptr) {
                d->init->affect(owner);
            }
            owner->insertInitializedVariable(*d->name);
        } else {
            owner->insertDeclaration(*d->name);
        }
    }
}

RawDeclaration::RawDeclaration(string *name, Expression *init) : name(name),
                                                                 init(init) {

}
