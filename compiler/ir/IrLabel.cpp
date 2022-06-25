//
// Created by pauls on 25/06/2022.
//

#include "IrLabel.h"
#include <sstream>

void IrLabel::renderX86(ostream &o) const {
    o << label << ":" << endl;
}
