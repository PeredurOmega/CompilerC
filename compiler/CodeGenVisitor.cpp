#include "CodeGenVisitor.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    cout << ".globl	main\n"
            " main: \n"
            "    pushq   %rbp\n"
            "    movq    %rsp, %rbp\n";
    for (auto statement: ctx->statement()) {
        bool stop = any_cast<bool>(visitStatement(statement));
        if (stop) break;
    }

    cout << "    popq %rbp\n"
            "    ret\n";

    return 0;

}

antlrcpp::Any
CodeGenVisitor::visitStatement(ifccParser::StatementContext *ctx) {
    visitChildren(ctx);
    if (ctx->ret() != nullptr) return true;
    else return false;
}

antlrcpp::Any
CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    string type = ctx->TYPE()->getText();
    for (auto &var: ctx->VAR()) {
        currentOffset += 4;
        symbolTable[var->getText()] = -currentOffset;
    }
    for (auto &initCtx: ctx->init()) {
        visitInit(initCtx);
    }
    return ctx->VAR();
}

antlrcpp::Any CodeGenVisitor::visitInit(ifccParser::InitContext *ctx) {
    string variable = ctx->VAR()->getText();
    currentOffset += 4;
    symbolTable[variable] = -currentOffset;
    currentVariable = variable;
    return visitChildren(ctx);
}

antlrcpp::Any
CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {
    currentVariable = ctx->VAR()->getText();
    return visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitConstant(ifccParser::ConstantContext *ctx) {
    int offset = symbolTable[currentVariable];
    cout << "    movl    $" << ctx->CONST()->getText() << ", " << offset
         << "(%rbp)" << endl;
    return offset;
}

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx) {
    int loffset = symbolTable[currentVariable];
    int roffset = symbolTable[ctx->VAR()->getText()];
    cout << "    movl    " << roffset << "(%rbp), %eax" << endl;
    cout << "    movl    %eax, " << loffset << "(%rbp)" << endl;
    return loffset;
}

antlrcpp::Any CodeGenVisitor::visitVarexpr(ifccParser::VarexprContext *ctx) {
    string temp = currentVariable;
    currentVariable = ctx->VAR()->getText();
    int loffset = any_cast<int>(visitChildren(ctx));

    if (!temp.empty()) {
        // Case when we recursively assign variables
        loffset = symbolTable[temp];
        int roffset = symbolTable[ctx->VAR()->getText()];
        cout << "    movl    " << roffset << "(%rbp), %eax" << endl;
        cout << "    movl    %eax, " << loffset << "(%rbp)" << endl;
    }

    return loffset;
}

antlrcpp::Any CodeGenVisitor::visitRet(ifccParser::RetContext *ctx) {
    currentVariable = "";
    int offset = any_cast<int>(visit(ctx->expression()));
    cout << "    movl    " << offset << "(%rbp), %eax" << endl;
    return offset;
}
