//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_IRSCOPE_H
#define LIBANTLR4_IRSCOPE_H

#include <unordered_map>
#include "IrElement.h"
#include "Instruction.h"

using namespace std;

class IrScope : public Instruction {
public:
    explicit IrScope();

    int currentOffset = 0;

    int insertInitializedVariable(string &varName);

    void insertDeclaration(string &varName);

    int insertTempVariable();

    int getOffset(string *varName);

    int getNewLabel();

    BasicBlock* basicBlock();

    void setOwner(IrScope *owner) override;

    /**
     * If there is a need for conditional jump, jump label is returned, otherwise -1 is return.
     */
    virtual int conditionalJump() = 0;

    void insertParameter(string &varName, int offset);

protected:
    int *label;
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
