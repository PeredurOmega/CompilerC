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
    int offset;
    if (currentVariable.empty()) {
        currentOffset += 4;
        offset = -currentOffset;
    } else {
        offset = symbolTable[currentVariable];
    }
    cout << "    movl    $" << ctx->CONST()->getText() << ", " << offset
         << "(%rbp) #v" << currentVariable << endl;
    return offset;
}

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx) {
    if (currentVariable.empty()) {
        return symbolTable[ctx->VAR()->getText()];
    }
    int loffset = symbolTable[currentVariable];
    int roffset = symbolTable[ctx->VAR()->getText()];
    cout << "    movl    " << roffset << "(%rbp), %eax #"
         << ctx->VAR()->getText() << endl;
    cout << "    movl    %eax, " << loffset << "(%rbp) #" << currentVariable
         << endl;
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
        cout << "    movl    " << roffset << "(%rbp), %eax #"
             << ctx->VAR()->getText() << endl;
        cout << "    movl    %eax, " << loffset << "(%rbp) #" << temp << endl;
    }

    return loffset;
}

antlrcpp::Any CodeGenVisitor::visitRet(ifccParser::RetContext *ctx) {
    currentVariable = "";
    int offset = any_cast<int>(visit(ctx->expression()));
    cout << "    movl    " << offset << "(%rbp), %eax" << endl;
    return offset;
}

antlrcpp::Any CodeGenVisitor::visitAddsub(ifccParser::AddsubContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    string op = ctx->op->getText();
    if (op == "+") {
        cout << "    movl    " << loffset << "(%rbp), %edx" << endl;
        cout << "    movl    " << roffset << "(%rbp), %eax" << endl;
        cout << "    addl    %edx, %eax" << endl;
    } else if (op == "-") {
        cout << "    movl    " << loffset << "(%rbp), %eax" << endl;
        cout << "    subl    " << roffset << "(%rbp), %eax" << endl;
    }
    currentVariable = temp;
    int offset;
    if (currentVariable.empty()) {
        currentOffset += 4;
        offset = -currentOffset;
    } else {
        offset = symbolTable[currentVariable];
    }
    cout << "    movl    %eax, " << offset
         << "(%rbp) #v" << currentVariable << endl;
    return offset;
}

antlrcpp::Any CodeGenVisitor::visitTimes(ifccParser::TimesContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    string op = ctx->op->getText();
    if (op == "*") {
        cout << "    movl    " << loffset << "(%rbp), %edx" << endl;
        cout << "    movl    " << roffset << "(%rbp), %eax" << endl;
        cout << "    imull    %edx, %eax" << endl;
    } else if (op == "/" || op == "%") {
        cout << "    movl    " << loffset << "(%rbp), %eax" << endl;
        cout << "    cltd" << endl;
        cout << "    idivl    " << roffset << "(%rbp)" << endl;
    }
    string res;
    if (op == "%") res = "edx";
    else res = "eax";
    currentVariable = temp;
    int offset;
    if (currentVariable.empty()) {
        currentOffset += 4;
        offset = -currentOffset;
    } else {
        offset = symbolTable[currentVariable];
    }
    cout << "    movl    %" << res << ", " << offset
         << "(%rbp) #v" << currentVariable << endl;
    return offset;
}

antlrcpp::Any
CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx) {
    return visit(ctx->expression());
}

antlrcpp::Any CodeGenVisitor::visitUnary(ifccParser::UnaryContext *ctx) {
    int offset = any_cast<int>(visit(ctx->expression()));
    if (ctx->op->getText() == "-") {
        cout << "    negl    " << offset << "(%rbp)" << endl;
    }
    return offset;
}
