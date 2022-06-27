//
// Created by pauls on 25/06/2022.
//

#include "IrPrologue.h"
#include <sstream>

void IrPrologue::renderX86(ostream &o) const {
    o << "    pushq   %rbp" << endl
      << "    movq    %rsp, %rbp" << endl
      << "    subq    $" << stackSize << ", %rsp" << endl;
}

void IrPrologue::assignMemory() {

}
