//
// Created by pauls on 16/06/2022.
//

#include "Instruction.h"

void Instruction::setOwner(Scope *_owner) {
    this->owner = _owner;
}

void Empty::linearize(IrFunction *fun) {

}
