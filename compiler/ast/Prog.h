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
        globalScope = this;
        usedFunction = new unordered_map<string, bool>();
    };

    void linearize(IrFunction *fun) override;

    void renderX86(ostream &o);

    void addFunction(Function *function);

    void setOwner(Scope *owner) override;

    IrVariable *getStaticIrVariable(string *varName);

    PrimaryType *declareStaticVariable(StaticDeclaration *sDeclaration) override;

    int conditionalJump() override;

    const IrType *getFunctionType(string name) override;

protected:
    void warnAboutUnusedVariables() override;

private:
    string entry;
    vector<Function *> functions;
    unordered_map<string, bool> *usedFunction;
    unordered_map<string, StaticDeclaration *> staticVarTable;

    void warnAboutUnusedFunctions();
};

class UndefinedFunction : exception {
public:
    explicit UndefinedFunction() = default;

    [[nodiscard]] const char *what() const noexcept override {
        return "Undefined function";
    }
};

#endif //LIBANTLR4_PROG_H
