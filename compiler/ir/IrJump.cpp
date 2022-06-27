//
// Created by pauls on 24/06/2022.
//

#include "IrJump.h"
#include <sstream>

void IrJump::renderX86(ostream &o) const {
    o << "    jmp      .L" << toLabel << endl;
}

void IrJump::assignMemory() {

}

void IrJumpIfEqual::renderX86(ostream &o) const {
    o << "    je      .L" << toLabel << endl;
}

void IrJumpIfEqual::assignMemory() {

}

void IrJumpIfNotEqual::renderX86(ostream &o) const {
    o << "    jne      .L" << toLabel << endl;
}

void IrJumpIfNotEqual::assignMemory() {

}
