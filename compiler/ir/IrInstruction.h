//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_IRINSTRUCTION_H
#define LIBANTLR4_IRINSTRUCTION_H


#include "IrElement.h"

class IrScope;

class IrInstruction : IrElement {
public:
    /**
     * Initialized when added to a Block.
     */
    IrScope *owner = nullptr;

    bool alwaysReturn;

    explicit IrInstruction(bool alwaysReturn);

    virtual void affect(IrScope *owner) = 0;

    virtual void setOwner(IrScope *owner);

    void renderX86(ostream &o) const override = 0;
};


#endif //LIBANTLR4_IRINSTRUCTION_H
