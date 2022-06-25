//
// Created by pauls on 24/06/2022.
//

#include "IrCopy.h"
#include <sstream>

void IrCopy::renderX86(ostream &o) const {
    if (dynamic_cast<IrRegister *>(from) != nullptr) {
        o << "    movl    " << from << ", " << to << to->comment("CopyFromRegister") << endl;
    } else if (dynamic_cast<IrRegister *>(to) != nullptr) {
        o << "    movl    " << from << ", " << to << from->comment("CopyToRegister") << endl;
    } else {
        o << "    movl    " << from << ",  %eax" << from->comment("Copy") << endl;
        o << "    movl    %eax, " << to << to->comment("Copy") << endl;
    }
}
