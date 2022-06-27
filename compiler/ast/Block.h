//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_BLOCK_H
#define LIBANTLR4_BLOCK_H

#include "../ir/IrFunction.h"
#include <vector>
#include "Scope.h"
#include "Instruction.h"

class Block : public Scope {
public:
    using Scope::Scope;

    void addInstruction(Instruction *instruction);

    void setOwner(Scope *owner) override;

    void linearize(IrFunction *fun) override;

    void attachTo(Block *block);

    virtual int conditionalJump() override;

private:
    vector<Instruction *> instructions;
};


#endif //LIBANTLR4_BLOCK_H
