#include "CodeGenVisitor.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    cout << ".globl	main" << endl;

    for (auto function: ctx->function()) {
        visitFunction(function);
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitFunction(ifccParser::FunctionContext *ctx) {
    cout << " " << ctx->VAR()->getText() << ":" << endl
         << "    pushq   %rbp" << endl
         << "    movq    %rsp, %rbp" << endl;
    visitBlock(ctx->block());
    if (!hasReturn) {
        if (ctx->VAR()->getText() == "main" &&
            ctx->TYPE()->getText() == "int") {
            cout << "    movl    $0, %eax" << endl;
        } else {
            cout << "    nop" << endl;
        }
    }
    cout << "    popq %rbp" << endl
         << "    ret" << endl;
    return 0;
}

/**
 *
 * @param ctx
 * @return Whether or not the block "stop" the function via a return.
 */
antlrcpp::Any CodeGenVisitor::visitBlock(ifccParser::BlockContext *ctx) {
    for (auto statement: ctx->statement()) {
        bool stop = any_cast<bool>(visitStatement(statement));
        if (stop) return true;
    }
    return false;
}

antlrcpp::Any CodeGenVisitor::visitIfBlock(ifccParser::IfBlockContext *ctx) {
    currentVariable = "";
    jumpOffset++;
    bool finish = finalJump == 0;
    if (finish) {
        finalJump = jumpOffset;
    }
    int offset = any_cast<int>(visit(ctx->expression()));
    cout << "    cmpl    $0, " << offset << "(%rbp)" << endl;
    int jOffset;
    if (ctx->elseBlock() != nullptr) jOffset = jumpOffset + 1;
    else jOffset = finalJump;
    cout << "    je      .L" << jOffset << endl;

    int temp = finalJump;
    finalJump = 0;
    bool stop = any_cast<bool>(visitStatement(ctx->statement()));

    finalJump = temp;

    if (ctx->elseBlock() != nullptr) {
        cout << "    jmp      .L" << finalJump << endl;
        stop = any_cast<bool>(visitElseBlock(ctx->elseBlock())) && stop;
    }

    if (finish) {
        cout << ".L" << finalJump << ":" << endl;
        finalJump = 0;
    }
    return stop;
}

antlrcpp::Any
CodeGenVisitor::visitElseBlock(ifccParser::ElseBlockContext *ctx) {
    jumpOffset++;
    cout << ".L" << jumpOffset << ":" << endl;
    return visitStatement(ctx->statement());
}


antlrcpp::Any CodeGenVisitor::visitWhileBlock(ifccParser::WhileBlockContext *ctx) {
    int offset;
    currentVariable = "";
    jumpOffset++;
    cout << "    jmp      .L" << jumpOffset << endl;
    int temp = jumpOffset;

    jumpOffset++;
    cout << ".L" << jumpOffset << ":" << endl;
    bool stop = any_cast<bool>(visitStatement(ctx->statement()));
    jumpOffset = temp;

    cout << ".L" << jumpOffset << ":" << endl;
    offset = any_cast<int>(visit(ctx->expression()));
    cout << "    cmpl    $0, " << offset << "(%rbp)" << endl;
    cout << "    je      .L" << ++jumpOffset << endl;

    return 0;
}

/**
 *
 * @param ctx
 * @return Whether or not the statement "stop" the function via a return.
 */
antlrcpp::Any
CodeGenVisitor::visitStatement(ifccParser::StatementContext *ctx) {
    antlrcpp::Any result = visitChildren(ctx);
    if (ctx->block() != nullptr) {
        return any_cast<bool>(result);
    } else if (ctx->ret() != nullptr) {
        hasReturn = true;
        return true;
    } else {
        return false;
    }
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
    if (ctx->op->getText() == "+") {
        int offset = any_cast<int>(visit(ctx->expression()));
        return offset;
    } else {
        if (ctx->op->getText() == "-") {
            int offset = any_cast<int>(visit(ctx->expression()));
            cout << "    negl    " << offset << "(%rbp)" << endl;
            return offset;
        } else if (ctx->op->getText() == "~") {
            int offset = any_cast<int>(visit(ctx->expression()));
            cout << "    notl    " << offset << "(%rbp)" << endl;
            return offset;
        } else if (ctx->op->getText() == "!") {
            string temp = currentVariable;
            currentVariable = "";
            int roffset = any_cast<int>(visit(ctx->expression()));
            cout << "    cmpl    $0, " << roffset << "(%rbp)" << endl;
            cout << "    sete    %al" << endl;
            cout << "    movzbl  %al, %eax" << endl;
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
    }
}

antlrcpp::Any CodeGenVisitor::visitCompare(ifccParser::CompareContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    string op = ctx->op->getText();
    cout << "    movl    " << loffset << "(%rbp), %eax" << endl;
    cout << "    cmpl    " << roffset << "(%rbp), %eax" << endl;
    string instruction;
    if (op == "<") {
        instruction = "setl";
    } else if (op == "<=") {
        instruction = "setle";
    } else if (op == ">=") {
        instruction = "setge";
    } else if (op == ">") {
        instruction = "setg";
    }
    cout << "    " << instruction << " %al" << endl;
    cout << "    movzbl  %al, %eax" << endl;
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

antlrcpp::Any CodeGenVisitor::visitEqual(ifccParser::EqualContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    string op = ctx->op->getText();
    cout << "    movl    " << loffset << "(%rbp), %eax" << endl;
    cout << "    cmpl    " << roffset << "(%rbp), %eax" << endl;
    string instruction;
    if (op == "==") {
        instruction = "sete";
    } else if (op == "!=") {
        instruction = "setne";
    }
    cout << "    " << instruction << " %al" << endl;
    cout << "    movzbl  %al, %eax" << endl;
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

antlrcpp::Any
CodeGenVisitor::visitBitwiseand(ifccParser::BitwiseandContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    cout << "    movl    " << loffset << "(%rbp), %eax" << endl;
    string op = ctx->op->getText();
    string instruction;
    if (op == "&") {
        instruction = "andl";
    }
    cout << "    " << instruction << "    " << roffset << "(%rbp), %eax"
         << endl;
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

antlrcpp::Any
CodeGenVisitor::visitBitwisexor(ifccParser::BitwisexorContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    cout << "    movl    " << loffset << "(%rbp), %eax" << endl;
    string op = ctx->op->getText();
    string instruction;
    if (op == "^") {
        instruction = "xorl";
    }
    cout << "    " << instruction << "    " << roffset << "(%rbp), %eax"
         << endl;
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

antlrcpp::Any
CodeGenVisitor::visitBitwiseor(ifccParser::BitwiseorContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    cout << "    movl    " << loffset << "(%rbp), %eax" << endl;
    string op = ctx->op->getText();
    string instruction;
    if (op == "|") {
        instruction = "orl";
    }
    cout << "    " << instruction << "    " << roffset << "(%rbp), %eax"
         << endl;
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

antlrcpp::Any CodeGenVisitor::visitShift(ifccParser::ShiftContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    cout << "    movl    " << roffset << "(%rbp), %eax" << endl;
    cout << "    movl    " << loffset << "(%rbp), %edx" << endl;
    cout << "    movl    %eax, %ecx" << endl;
    string op = ctx->op->getText();
    string instruction;
    if (op == "<<") {
        instruction = "sall";
    } else if (op == ">>") {
        instruction = "sarl";
    }
    cout << "    " << instruction << "    %cl, %edx" << endl;
    cout << "    movl    %edx, %eax" << endl;
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

antlrcpp::Any
CodeGenVisitor::visitLogicaland(ifccParser::LogicalandContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    cout << "    cmpl    $0, " << loffset << "(%rbp)" << endl;
    jumpOffset++;
    cout << "    jne      .L" << jumpOffset << endl;
    cout << "    cmpl    $0, " << roffset << "(%rbp)" << endl;
    cout << "    je      .L" << jumpOffset << endl;
    cout << "    movl    $1, %eax" << endl;
    jumpOffset++;
    cout << "    jmp     .L" << jumpOffset << endl;
    cout << " .L" << jumpOffset - 1 << ":" << endl;
    cout << "    movl    $0, %eax" << endl;
    cout << " .L" << jumpOffset << ":" << endl;
    cout << "    movzbl  %al, %eax" << endl;
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

antlrcpp::Any
CodeGenVisitor::visitLogicalor(ifccParser::LogicalorContext *ctx) {
    string temp = currentVariable;
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    ifccParser::ExpressionContext *lexpr = expr[0];
    ifccParser::ExpressionContext *rexpr = expr[1];
    currentVariable = "";
    int loffset = any_cast<int>(visit(lexpr));
    int roffset = any_cast<int>(visit(rexpr));
    cout << "    cmpl    $0, " << loffset << "(%rbp)" << endl;
    jumpOffset++;
    cout << "    jne     .L" << jumpOffset << endl;
    cout << "    cmpl    $0, " << roffset << "(%rbp)" << endl;
    jumpOffset++;
    cout << "    je      .L" << jumpOffset << endl;
    cout << " .L" << jumpOffset - 1 << ":" << endl;
    cout << "    movl    $1, %eax" << endl;
    jumpOffset++;
    cout << "    jmp     .L" << jumpOffset << endl;
    cout << " .L" << jumpOffset - 1 << ":" << endl;
    cout << "    movl    $0, %eax" << endl;
    cout << " .L" << jumpOffset << ":" << endl;
    cout << "    movzbl  %al, %eax" << endl;
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

