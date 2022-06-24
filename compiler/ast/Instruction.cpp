//
// Created by pauls on 16/06/2022.
//

#include "Instruction.h"

void Instruction::setOwner(IrScope *_owner) {
    this->owner = _owner;
}

Instruction::Instruction() {

}

Empty::Empty() {

}

void Empty::affect(IrScope *owner) {

}

void Empty::renderX86(ostream &o) const {

}
