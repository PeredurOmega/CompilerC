#include "UnaryOpIrInstruction.h"

#include <sstream>

using namespace std;

void MinusUnaryIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << right << ", %eax" << right->comment("MinusUnary") << endl;
    o << "    negl    " << "%eax" << right->comment("MinusUnary") << endl;
    o << "    movl    %eax, " << to << to->comment("MinusUnary") << endl;
}

void NotUnaryIrInstruction::renderX86(ostream &o) const {
    o << "    cmpl    $0, " << right << right->comment("NotUnary") << endl;
    o << "    sete    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("NotUnary") << endl;
}

void BitwiseNotUnaryIrInstruction::renderX86(ostream &o) const {
    o << "    notl    " << right << right->comment("BitwiseNotUnary") << endl;
    o << "    movl    " << right << ", %eax" << right->comment("BitwiseNotUnary") << endl;
    o << "    movl    %eax, " << to << to->comment("BitwiseNotUnary") << endl;
}

void UnaryOpIrInstruction::assignMemory() {
    right->assignMemory(scope);
    to->assignMemory(scope);
    if (dynamic_cast<IrTempVariable *>(to) != nullptr && dynamic_cast<IrTempVariable *>(right) != nullptr) {
        to->offset = right->offset;
    } else {
        to->assignMemory(scope);
    }
}
