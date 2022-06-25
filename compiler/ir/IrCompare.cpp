//
// Created by pauls on 25/06/2022.
//

#include "IrCompare.h"
#include <sstream>

void IrCompare::renderX86(ostream &o) const {
    o << "    cmpl    $0, " << toCompareTo0 << endl;
}
