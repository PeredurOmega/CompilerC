//
// Created by pauls on 25/06/2022.
//

#include "IrMovzbl.h"
#include <sstream>

void IrMobzbl::renderX86(ostream &o) const {
    o << "    movzbl  " << from << ", " << to << endl;
}
