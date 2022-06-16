//
// Created by pauls on 16/06/2022.
//

#include "IrInstruction.h"

IrInstruction::IrInstruction(bool alwaysReturn) : alwaysReturn(alwaysReturn) {

}

void IrInstruction::setOwner(IrScope *_owner) {
    this->owner = _owner;
}
