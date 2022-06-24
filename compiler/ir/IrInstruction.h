//
// Created by pauls on 16/06/2022.
//

#ifndef LIBANTLR4_IRINSTRUCTION_H
#define LIBANTLR4_IRINSTRUCTION_H


#include <set>
#include "IrElement.h"

class IrScope;

class IrInstruction : IrElement {
public:
    /**
     * Initialized when added to a Block.
     */
    IrScope *owner = nullptr;

    bool alwaysReturn = false;
    bool conditionalReturn = false;

    explicit IrInstruction();

    /**
     * Set of the variables used.
     */
    virtual set<string*>* use() = 0;

    /**
     * Set of the variables defined.
     */
    virtual set<string*>* def() = 0;

    virtual void affect(IrScope *owner) = 0;

    virtual void setOwner(IrScope *owner);

    void renderX86(ostream &o) const override = 0;
};

class Empty : IrInstruction {
public:
    explicit Empty();

    void affect(IrScope *owner) override;

    void renderX86(ostream &o) const override;

    set<string*>* use() override;

    set<string*>* def() override;
};


#endif //LIBANTLR4_IRINSTRUCTION_H
