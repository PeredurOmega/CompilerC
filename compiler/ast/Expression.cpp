//
// Created by pauls on 16/06/2022.
//

#include "Expression.h"
#include "../ir/IrConstant.h"
#include "../ir/IrReturn.h"
#include "../ir/IrJump.h"
#include "../ir/IrCopy.h"
#include "../ir/IrPushq.h"
#include "../ir/IrCall.h"
#include "../ir/IrAddQ.h"
#include <iostream>


const vector<string *> FunctionCall::registers = { // NOLINT(cert-err58-cpp)
        new string("edi"),
        new string("esi"),
        new string("edx"),
        new string("ecx"),
        new string("r8d"),
        new string("r9d")
};

void FunctionCall::linearize(IrFunction *fun) {
    for (int i = (int) arguments->size() - 1; i >= 0; --i) {
        auto *expr = (*arguments)[i];
        expr->linearize(fun);
        if (i < 6) {
            fun->append(new IrCopy(expr->var, getRegisterToUse(i, expr->var->type)));
        } else {
            fun->append(new IrPushq(expr->var));
        }
    }
    fun->append(new IrCall(name));
    if ((int) arguments->size() - 6 > 0) fun->append(new IrAddQ(8 * ((int) arguments->size() - 6)));
    auto *returnType = owner->getFunctionType(name);
    if (assignTo != nullptr) {
        if (*returnType == IrType::VOID) {
            throw new InvalidReturnType();
        } else {
            auto *rType = (PrimaryType *) returnType;
            var = new IrVariable(assignTo, rType);
            fun->append(new IrCopy(new IrRegister(nullptr, new string("eax"), rType), var));
        }
    } else {
        auto *rType = (PrimaryType *) returnType;
        var = new IrTempVariable(rType);
        fun->append(new IrCopy(new IrRegister(nullptr, new string("eax"), rType), var));
    }
}

void FunctionCall::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    for (auto *argument: *arguments) {
        argument->setOwner(owner);
    }
}

IrRegister *FunctionCall::getRegisterToUse(int position, PrimaryType *type) {
    return new IrRegister(nullptr, registers[position], type);
}

void Variable::linearize(IrFunction *fun) {
    var = new IrVariable(&name, owner->getType(&name));
    if(assignTo != nullptr) {
        fun->append(new IrCopy(var, new IrVariable(assignTo, owner->getType(assignTo))));
    }
}

void Constant::linearize(IrFunction *fun) {
    if (assignTo != nullptr) {
        var = new IrVariable(assignTo, new IntType());
    } else {
        var = new IrTempVariable(new IntType());
    }
    fun->append(new IrConstant(value, var));
}

void Return::linearize(IrFunction *fun) {
    expression->linearize(fun);
    fun->append(new IrReturn(expression->var));
    int conditionalJump = owner->conditionalJump();
    if (conditionalJump != -1) {
        fun->append(new IrJump(conditionalJump));
    }
}

void Return::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    expression->setOwner(owner);
}

void VarExpr::linearize(IrFunction *fun) {
    expression->linearize(fun);
    auto *lastVar = varNames.front();
    auto *prevVar = expression->var;
    for (int i = (int) varNames.size() - 1; i >= 0; i--) {
        auto *to = new IrVariable(varNames[i], owner->getType(varNames[i]));
        auto *copy = new IrCopy(prevVar, to);
        prevVar = to;
        fun->append(copy);
    }
    var = new IrVariable(lastVar, owner->getType(lastVar));
}

void VarExpr::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    expression->setOwner(owner);
}
