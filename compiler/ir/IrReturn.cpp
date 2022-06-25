//
// Created by pauls on 24/06/2022.
//

#include "IrReturn.h"
#include <sstream>

void IrReturn::renderX86(ostream &o) const {
    o << "    movl    " << from << ", %eax" << from->comment("Return") << endl;
}
