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
    explicit Block();

    void addInstruction(Instruction *instruction);

    void renderX86(ostream &o) const override;

    void attachTo(Block *block);

    int conditionalJump() override;

private:
    vector<Instruction *> instructions;
};


#endif //LIBANTLR4_BLOCK_H