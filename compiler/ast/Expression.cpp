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


const vector<IrRegister *> FunctionCall::registers = { // NOLINT(cert-err58-cpp)
        new IrRegister(nullptr, new string("edi")),
        new IrRegister(nullptr, new string("esi")),
        new IrRegister(nullptr, new string("edx")),
        new IrRegister(nullptr, new string("ecx")),
        new IrRegister(nullptr, new string("r8d")),
        new IrRegister(nullptr, new string("r9d"))
};

vector<IrInstruction *> *FunctionCall::linearize() {
    auto *instructions = new vector<IrInstruction *>();
    for (int i = (int) arguments->size() - 1; i >= 0; --i) {
        auto *expr = (*arguments)[i];
        auto *instr = expr->linearize();
        instructions->insert(instructions->end(), instr->begin(), instr->end());
        if (i < 6) {
            instructions->push_back(new IrCopy(expr->var, registers[i]));
        } else {
            instructions->push_back(new IrPushq(expr->var));
        }
    }
    instructions->push_back(new IrCall(name));
    if ((int) arguments->size() - 6 > 0) instructions->push_back(new IrAddQ(8 * ((int) arguments->size() - 6)));
    var = new IrVariable(assignTo, owner->getOffset(assignTo));
    instructions->push_back(new IrCopy(new IrRegister(nullptr, new string("eax")), var));
    return instructions;
}

void FunctionCall::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    for (auto *argument: *arguments) {
        argument->setOwner(owner);
    }
}

vector<IrInstruction *> *Variable::linearize() {
    var = new IrVariable(&name, owner->getOffset(&name));
    return new vector<IrInstruction *>();
}

vector<IrInstruction *> *Constant::linearize() {
    auto *inst = new vector<IrInstruction *>();
    var = new IrVariable(assignTo, owner->getOffset(assignTo));
    auto *c = new IrConstant(value, var);
    inst->push_back(c);
    return inst;
}

vector<IrInstruction *> *Return::linearize() {
    auto *inst = expression->linearize();
    inst->push_back(new IrReturn(expression->var));
    int conditionalJump = owner->conditionalJump();
    if (conditionalJump != -1) {
        inst->push_back(new IrJump(conditionalJump));
    }
    return inst;
}

void Return::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    expression->setOwner(owner);
}

vector<IrInstruction *> *VarExpr::linearize() {
    auto *inst = expression->linearize();
    auto lastVar = varNames.front();
    auto *prevVar = expression->var;
    for (int i = (int) varNames.size() - 1; i >= 0; i--) {
        auto *to = new IrVariable(varNames[i], owner->getOffset(varNames[i]));
        auto *copy = new IrCopy(prevVar, to);
        prevVar = to;
        inst->push_back(copy);
    }
    var = new IrVariable(lastVar, owner->getOffset(lastVar));
    return inst;
}

void VarExpr::setOwner(Scope *owner) {
    Instruction::setOwner(owner);
    expression->setOwner(owner);
}
