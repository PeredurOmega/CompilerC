//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_FUNCTION_H
#define LIBANTLR4_FUNCTION_H


#include <vector>
#include "../ir/IrElement.h"
#include "TypeSymbol.h"
#include "Block.h"

class IrFunction;
class StaticDeclaration;

class Parameter {
public:
    explicit Parameter(PrimaryType *type, string name);

    PrimaryType *type;
    string name;
};

class Function : public Block {
public:
    string name;

    const IrType *returnType;

    explicit Function(string name, const IrType *returnType, const vector<Parameter *> &parameters)
            : Block(), name(std::move(name)), returnType(returnType), parameters(parameters) {};

    IrFunction *linearize();

    void setBlock(Block *block);

    int conditionalJump() override;

private:
    const string MAIN = "main";
    int endLabel = -1;
    vector<Parameter *> parameters;
    vector<tuple<string, string, int>> registers;
};

class InvalidReturnType : exception {
public:
    explicit InvalidReturnType() = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Invalid return type";
    }
};

#endif //LIBANTLR4_FUNCTION_H
