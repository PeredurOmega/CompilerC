//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_INSTRUCTION_H
#define LIBANTLR4_INSTRUCTION_H


#include <vector>
#include "../ir/IrElement.h"
#include "../ir/IrInstruction.h"
#include "../ir/IrFunction.h"

class Scope;

class Instruction {
public:
    /**
     * Initialized when added to a Block.
     */
    Scope *owner = nullptr;

    bool alwaysReturn = false;

    bool conditionalReturn = false;

    Instruction() = default;

    virtual void setOwner(Scope *owner);

    virtual void linearize(IrFunction *fun) = 0;
};

class Empty : Instruction {
public:
    using Instruction::Instruction;

    void linearize(IrFunction* fun) override;
};


#endif //LIBANTLR4_INSTRUCTION_H
