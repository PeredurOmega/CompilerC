//
// Created by pauls on 25/06/2022.
//

#include "IrNoOp.h"
#include <sstream>

void IrNoOp::renderX86(ostream &o) const {
    o << "    nop" << endl;
}

void IrNoOp::assignMemory() {

}
