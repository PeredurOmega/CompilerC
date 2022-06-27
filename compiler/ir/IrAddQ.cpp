//
// Created by pauls on 25/06/2022.
//

#include "IrAddQ.h"
#include <sstream>

void IrAddQ::renderX86(ostream &o) const {
    o << "    addq    $" << stackSize << ", %rsp" << endl;
}

void IrAddQ::assignMemory() {

}
