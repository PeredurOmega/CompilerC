//
// Created by pauls on 25/06/2022.
//

#include "IrPushq.h"
#include <sstream>

void IrPushq::renderX86(ostream &o) const {
    o << "    pushq    " << var << endl;
}
