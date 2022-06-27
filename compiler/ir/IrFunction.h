//
// Created by mathis on 26/06/22.
//

#ifndef LIBANTLR4_IRFUNCTION_H
#define LIBANTLR4_IRFUNCTION_H

#include "IrInstruction.h"

class IrScope;
class Parameter;

class IrFunction : public IrInstruction {
public:
    explicit IrFunction(vector<Parameter *> parameters, string name)
            : IrInstruction(), parameters(std::move(parameters)), name(std::move(name)) {};

    void renderX86(ostream &o) const override;

    void append(BasicBlock *block);

    void assignMemory() override;

    void append(IrInstruction *instruction);

    void append(vector<IrInstruction *> *instruction);

    vector<Parameter *> parameters;

    vector<BasicBlock *> *basicBlocks = new vector<BasicBlock *>();
    string name;
    int stackSize;
    BasicBlock *currentBlock;
    IrScope *currentScope = nullptr;
    IrScope *mainScope = nullptr;
};


#endif //LIBANTLR4_IRFUNCTION_H
