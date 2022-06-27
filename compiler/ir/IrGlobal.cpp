//
// Created by pauls on 25/06/2022.
//

#include "IrGlobal.h"
#include <sstream>

void IrGlobal::renderX86(ostream &o) const {
    o << ".globl " << entry << endl;
}

void IrGlobal::assignMemory() {

}
