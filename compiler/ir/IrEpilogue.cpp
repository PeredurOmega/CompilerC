//
// Created by pauls on 25/06/2022.
//

#include "IrEpilogue.h"
#include <sstream>

void IrEpilogue::renderX86(ostream &o) const {
    o << "    addq    $" << stackSize << ", %rsp" << endl
      << "    popq    %rbp" << endl
      << "    ret" << endl;
}
