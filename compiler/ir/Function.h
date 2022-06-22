//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_FUNCTION_H
#define LIBANTLR4_FUNCTION_H


#include <vector>
#include "IrElement.h"
#include "Block.h"
#include "TypeSymbol.h"

class Parameter;

class Function : public Block {
public:
    //TODO HANDLE PARAMETERS
    explicit Function(string name, const IrType *returnType, const vector<Parameter *>& parameters);

    void renderX86(ostream &o) const override;

    void setBlock(Block *block);

    int conditionalJump() override;

    void affect(IrScope *owner) override;

private:
    const string MAIN = "main";
    const IrType *returnType;
    string name;
    int endLabel = -1;
    vector<Parameter *> parameters;
};

class Parameter {
public:
    explicit Parameter(PrimaryType *type, string name);
    PrimaryType *type;
    string name;
};

#endif //LIBANTLR4_FUNCTION_H
