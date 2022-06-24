//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_INSTRUCTION_H
#define LIBANTLR4_INSTRUCTION_H


#include <vector>
#include "IrElement.h"
#include "../ir/IrInstruction.h"

class IrScope;

class Instruction : IrElement {
public:
    /**
     * Initialized when added to a Block.
     */
    IrScope *owner = nullptr;

    bool alwaysReturn = false;
    bool conditionalReturn = false;

    explicit Instruction();

    virtual void setOwner(IrScope *owner);

    vector<IrInstruction *> linearize() const override = 0;
};

class Empty : Instruction {
public:
    explicit Empty();

    void affect(IrScope *owner) override;

    void renderX86(ostream &o) const override;
};


#endif //LIBANTLR4_INSTRUCTION_H
