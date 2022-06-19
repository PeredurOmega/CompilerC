//
// Created by pauls on 16/06/2022.
//

#include "IrInstruction.h"

void IrInstruction::setOwner(IrScope *_owner) {
    this->owner = _owner;
}

IrInstruction::IrInstruction() {

}

Empty::Empty() {

}

void Empty::affect(IrScope *owner) {

}

void Empty::renderX86(ostream &o) const {

}
