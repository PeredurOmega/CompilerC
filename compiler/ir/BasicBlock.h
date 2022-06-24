//
// Created by pauls on 24/06/2022.
//

#ifndef LIBANTLR4_BASICBLOCK_H
#define LIBANTLR4_BASICBLOCK_H

#include <string>
#include <vector>
#include "IrInstruction.h"

using namespace std;


class BasicBlock {
public:
    string *label;
    vector<IrInstruction *> *instructions;
    BasicBlock *nextTrue;
    BasicBlock *nextFalse;
};


#endif //LIBANTLR4_BASICBLOCK_H
