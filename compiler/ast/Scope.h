//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_SCOPE_H
#define LIBANTLR4_SCOPE_H

#include <unordered_map>
#include "../ir/IrElement.h"
#include "Instruction.h"
#include "TypeSymbol.h"

using namespace std;

class Scope : public Instruction {
public:

    using Instruction::Instruction;

    int getNewLabel();

    void setOwner(Scope *owner) override;

    PrimaryType* getType(string *varName);

    PrimaryType* declareVariable(string *varName, PrimaryType* type);

    /**
     * If there is a need for conditional jump, jump label is returned, otherwise -1 is return.
     */
    virtual int conditionalJump() = 0;

protected:
    int *label;
    unordered_map<string, PrimaryType*> varTable;
};

class UndefinedVariable : exception {
public:
    explicit UndefinedVariable() = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Undefined variable";
    }
};

class AlreadyDeclaredVariable : exception {
public:
    explicit AlreadyDeclaredVariable() = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Already declared variable";
    }
};

class BadOperation : exception {
public:
    explicit BadOperation() = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Bad operation";
    }
};

#endif //LIBANTLR4_SCOPE_H
