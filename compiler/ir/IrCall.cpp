//
// Created by pauls on 25/06/2022.
//

#include "IrCall.h"
#include <sstream>

void IrCall::renderX86(ostream &o) const {
    o << "    call    " << label << endl;
}
