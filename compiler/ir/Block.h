//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_BLOCK_H
#define LIBANTLR4_BLOCK_H


#include <vector>
#include "IrScope.h"
#include "IrInstruction.h"

class Block : public IrScope {
public:
    bool alwaysReturn = false;

    explicit Block();

    void addInstruction(IrInstruction *instruction);

    void renderX86(ostream &o) const override;

    void attachTo(Block *block);

    void affect(IrScope *owner) override;

private:
    vector<IrInstruction *> instructions;
};


#endif //LIBANTLR4_BLOCK_H
