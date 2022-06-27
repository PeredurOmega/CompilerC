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
    auto argsAsVar = vector<IrVariable *>();
    argsAsVar.reserve(6);
    for (int i = (int) arguments->size() - 1; i >= 0; --i) {
        auto *expr = (*arguments)[i];
        expr->linearize(fun);
        if (i < 6) {
            auto *tempVar = new IrTempVariable(expr->var->type);
            argsAsVar[i] = tempVar;
            fun->append(new IrCopy(expr->var, tempVar));
        } else {
            fun->append(new IrPushq(expr->var));
        }
    }

    for (int i = min((int) arguments->size() - 1, 5); i >= 0; --i) {
        fun->append(new IrCopy(argsAsVar[i], getRegisterToUse(i, argsAsVar[i]->type)));
    }

    fun->append(new IrCall(name));
    if ((int) arguments->size() - 6 > 0) fun->append(new IrAddQ(8 * ((int) arguments->size() - 6)));
    auto *returnType = owner->getFunctionType(name);
    if (assignTo != nullptr) {
        if (*returnType == IrType::VOID) {
            throw new InvalidReturnType();
        } else {
            auto *rType = (PrimaryType *) returnType;
            var = owner->getIrVariable(assignTo);
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
    var = owner->getIrVariable(&name);
    if (assignTo != nullptr) {
        fun->append(new IrCopy(var, owner->getIrVariable(assignTo)));
    }
}

void Constant::linearize(IrFunction *fun) {
    if (assignTo != nullptr) {
        var = owner->getIrVariable(assignTo);
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
        auto *to = owner->getIrVariable(varNames[i]);
        auto *copy = new IrCopy(prevVar, to);
        prevVar = to;
        fun->append(copy);
    }
    var = owner->getIrVariable(lastVar);
}

void VarExpr::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    expression->setOwner(owner);
}
