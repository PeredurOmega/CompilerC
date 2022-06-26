//
// Created by mathis on 26/06/22.
//

#ifndef LIBANTLR4_IRFUNCTION_H
#define LIBANTLR4_IRFUNCTION_H


#include "IrInstruction.h"
#include "../ast/Function.h"

#include <utility>

class IrFunction : public IrInstruction {
public:
    explicit IrFunction(vector<Parameter *> parameters) : IrInstruction(), parameters(std::move(parameters)) {};

    void renderX86(ostream &o) const override;

    vector<Parameter *> parameters;
};


#endif //LIBANTLR4_IRFUNCTION_H
