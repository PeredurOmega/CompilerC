//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_BLOCK_H
#define LIBANTLR4_BLOCK_H


#include <vector>
#include "IrScope.h"
#include "Instruction.h"

class Block : public IrScope {
public:
    using IrScope::IrScope;

    void addInstruction(Instruction *instruction);

    void setOwner(IrScope *owner) override;

    vector<IrInstruction *> *linearize() override;

    void attachTo(Block *block);

    int conditionalJump() override;

private:
    vector<Instruction *> instructions;
};


#endif //LIBANTLR4_BLOCK_H
