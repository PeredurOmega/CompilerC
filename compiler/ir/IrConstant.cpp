//
// Created by pauls on 24/06/2022.
//

#include "IrConstant.h"
#include <sstream>

using namespace std;

void IrConstant::renderX86(ostream &o) const {
    o << "    movl    $" << value << ", " << to << to->comment("Constant") << endl;
}
