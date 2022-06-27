//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_BASICBLOCK_H
#define LIBANTLR4_BASICBLOCK_H

#include <string>
#include <vector>
#include "IrInstruction.h"

using namespace std;

class IrInstruction;

class BasicBlock {
public:
    explicit BasicBlock(string *label) : label(label) {};

    string *label;
    vector<IrInstruction *> *instr = new std::vector<IrInstruction *>();

    BasicBlock *nextTrue;
    BasicBlock *nextFalse;
};

#endif //LIBANTLR4_BASICBLOCK_H
