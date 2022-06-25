//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_INSTRUCTION_H
#define LIBANTLR4_INSTRUCTION_H


#include <vector>
#include "../ir/IrElement.h"
#include "../ir/IrInstruction.h"

class IrScope;

class Instruction {
public:
    /**
     * Initialized when added to a Block.
     */
    IrScope *owner = nullptr;

    bool alwaysReturn = false;
    bool conditionalReturn = false;

    explicit Instruction() {};

    virtual void setOwner(IrScope *owner);

    virtual vector<IrInstruction *> *linearize() = 0;
};

class Empty : Instruction {
public:
    using Instruction::Instruction;

    vector<IrInstruction *> *linearize() override;
};


#endif //LIBANTLR4_INSTRUCTION_H
