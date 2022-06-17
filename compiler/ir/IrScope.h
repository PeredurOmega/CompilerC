//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_IRSCOPE_H
#define LIBANTLR4_IRSCOPE_H

#include <unordered_map>
#include "IrElement.h"

using namespace std;

class IrScope : IrElement {
public:
    int currentOffset = 0;

    void insertInitializedVariable(string &varName);

    void insertDeclaration(string &varName);

    int insertTempVariable();

    int getOffset(string &varName);

    int getNewLabel();

    void setOwner(IrScope *owner);

protected:
    int* label;
    IrScope *owner;
    unordered_map<string, int> symbolTable;
};


class UndefinedVariable : exception {
public:
    explicit UndefinedVariable() {
    }

    [[nodiscard]] const char *what() const noexcept override {
        return "Undefined variable";
    }
};

class BadOperation : exception {
public:
    explicit BadOperation() {
    }

    [[nodiscard]] const char *what() const noexcept override {
        return "Bad operation";
    }
};

#endif //LIBANTLR4_IRSCOPE_H
