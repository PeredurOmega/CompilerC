//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_SCOPE_H
#define LIBANTLR4_SCOPE_H

#include <unordered_map>
#include "../ir/IrElement.h"
#include "Instruction.h"

using namespace std;

class Scope : public Instruction {
public:

    static int currentOffset;

    using Instruction::Instruction;

    int insertInitializedVariable(string &varName);

    void insertDeclaration(string &varName);

    int insertTempVariable();

    int getOffset(string *varName);

    int getNewLabel();

    void setOwner(Scope *owner) override;

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

#endif //LIBANTLR4_SCOPE_H
