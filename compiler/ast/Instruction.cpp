//
// Created by pauls on 16/06/2022.
//

#include "Instruction.h"

void Instruction::setOwner(IrScope *_owner) {
    this->owner = _owner;
}

vector<IrInstruction *> *Empty::linearize() {
    return new vector<IrInstruction *>();
}
