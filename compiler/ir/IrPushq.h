//
// Created by pauls on 25/06/2022.
//

#ifndef LIBANTLR4_IRPUSHQ_H
#define LIBANTLR4_IRPUSHQ_H


#include "IrInstruction.h"

class IrPushq : public IrInstruction {
public:
    explicit IrPushq(IrVariable *var) : IrInstruction(), var(var) {};

    void renderX86(ostream &o) const override;

    IrVariable *var;
};

#endif //LIBANTLR4_IRPUSHQ_H
