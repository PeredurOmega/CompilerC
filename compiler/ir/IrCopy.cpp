//
// Created by pauls on 24/06/2022.
//

#include "IrCopy.h"
#include <sstream>

void IrCopy::renderX86(ostream &o) const {
    o << "    movl    " << from << ", %eax" << from->comment("Copy") << endl;
    o << "    movl    %eax, " << to << "(%rbp)" << to->comment("Copy") << endl;
}
