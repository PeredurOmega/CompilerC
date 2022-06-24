#include "OpIrInstruction.h"

#include <sstream>

using namespace std;

void AddIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %edx" << left->comment("Add") << endl;
    o << "    movl    " << right << ", %eax" << right->comment("Add") << endl;
    o << "    addl    %edx, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("Add") << endl;
}

void SubIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("Sub") << endl;
    o << "    subl    " << right << ", %eax" << right->comment("Sub") << endl;
    o << "    movl    %eax, " << to << to->comment("Sub") << endl;
}

void TimesIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %edx" << left->comment("Times") << endl;
    o << "    movl    " << right << ", %eax" << right->comment("Times") << endl;
    o << "    imull    %edx, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("Times") << endl;
}

void DivIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("Div") << endl;
    o << "    cltd" << endl;
    o << "    idivl    " << right << right->comment("Div") << endl;
    o << "    movl    %eax, " << to << to->comment("Div") << endl;
}

void ModuloIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("Mod") << endl;
    o << "    cltd" << endl;
    o << "    idivl    " << right << right->comment("Mod") << endl;
    o << "    movl    %edx, " << to << to->comment("Mod") << endl;
}

void ShiftRightIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %edx" << left->comment("ShiftRight") << endl;
    o << "    movl    " << right << ", %eax" << right->comment("ShiftRight") << endl;
    o << "    movl    %eax, %ecx" << endl;
    o << "    sarl    %cl, %edx" << endl;
    o << "    movl    %edx, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("ShiftRight") << endl;
}

void ShiftLeftIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %edx" << left->comment("ShiftLeft") << endl;
    o << "    movl    " << right << ", %eax" << right->comment("ShiftLeft") << endl;
    o << "    movl    %eax, %ecx" << endl;
    o << "    sall    %cl, %edx" << endl;
    o << "    movl    %edx, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("ShiftLeft") << endl;
}

void LessCompareIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("LessCompare") << endl;
    o << "    cmpl    " << right << ", %eax" << right->comment("LessCompare") << endl;
    o << "    setl    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("LessCompare") << endl;
}

void LessEqualCompareIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("LessEqualCompare") << endl;
    o << "    cmpl    " << right << ", %eax" << right->comment("LessEqualCompare") << endl;
    o << "    setle    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("LessEqualCompare") << endl;
}

void GreatCompareIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("GreatCompare") << endl;
    o << "    cmpl    " << right << ", %eax" << right->comment("GreatCompare") << endl;
    o << "    setg    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("GreatCompare") << endl;
}

void GreatEqualCompareIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("GreatEqualCompare") << endl;
    o << "    cmpl    " << right << ", %eax" << right->comment("GreatEqualCompare") << endl;
    o << "    setge    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("GreatEqualCompare") << endl;
}

void EqualCompareIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("EqualCompare") << endl;
    o << "    cmpl    " << right << ", %eax" << right->comment("EqualCompare") << endl;
    o << "    sete    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("EqualCompare") << endl;
}

void NotEqualCompareIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("NotEqualCompare") << endl;
    o << "    cmpl    " << right << ", %eax" << right->comment("NotEqualCompare") << endl;
    o << "    setne    %al" << endl;
    o << "    movzbl  %al, %eax" << endl;
    o << "    movl    %eax, " << to << to->comment("NotEqualCompare") << endl;
}

void BitwiseAndIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("BitwiseAnd") << endl;
    o << "    andl    " << right << ", %eax" << right->comment("BitwiseAnd") << endl;
    o << "    movl    %eax, " << to << to->comment("BitwiseAnd") << endl;
}

void BitwiseXorIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("BitwiseXor") << endl;
    o << "    xorl    " << right << ", %eax" << right->comment("BitwiseXor") << endl;
    o << "    movl    %eax, " << to << to->comment("BitwiseXor") << endl;
}

void BitwiseOrIrInstruction::renderX86(ostream &o) const {
    o << "    movl    " << left << ", %eax" << left->comment("BitwiseOr") << endl;
    o << "    orl    " << right << ", %eax" << right->comment("BitwiseOr") << endl;
    o << "    movl    %eax, " << to << to->comment("BitwiseOr") << endl;
}