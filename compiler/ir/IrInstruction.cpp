//
// Created by pauls on 24/06/2022.
//

#include "IrInstruction.h"
#include <sstream>

using namespace std;

ostream &Variable::operator<<(ostream &o) const {
    o << offset << "(%rbp)";
    return o;
}

string Variable::comment(const string &opType) const {
    if (name == nullptr) {
        return " # Temp " + opType;
    } else {
        return " # " + *name + opType;
    }
}

void AddIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %edx" << left->comment("Add") << endl;
    o << "    movl    " << right << ", %eax" << right->comment("Add") << endl;
    o << "    addl    %edx, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("Add") << endl;
}
