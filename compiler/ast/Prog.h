//
// Created by pauls on 15/06/2022.
//

#ifndef LIBANTLR4_PROG_H
#define LIBANTLR4_PROG_H

#include <utility>
#include <vector>
#include "unordered_map"
#include "Scope.h"
#include "Function.h"
#include "Any.h"

using namespace std;

class Prog : public Scope {
public:
    explicit Prog(string entry)
            : Scope(), entry(std::move(entry)) {
        label = new int(0);
        staticVarTable = new unordered_map<string, StaticDeclaration *>();
    };

    void linearize(IrFunction *fun) override;

    void renderX86(ostream &o);

    void addFunction(Function *function);

    void setOwner(Scope *owner) override;

    int conditionalJump() override;

    const IrType *getFunctionType(string name) override;

private:
    string entry;
    vector<Function *> functions;
    int jumpOffset = 0;
    int finalJump = 0;
};

class UndefinedFunction : exception {
public:
    explicit UndefinedFunction() = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Undefined function";
    }
};

#endif //LIBANTLR4_PROG_H
