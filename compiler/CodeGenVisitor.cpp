#include "CodeGenVisitor.h"
#include "ir/Prog.h"
#include "ir/Declaration.h"
#include "ir/Expression.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitAxiom(ifccParser::AxiomContext *ctx) {
    return visitProg(ctx->prog());
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    Prog *prog = new Prog("main");

    for (auto f: ctx->function()) {
        prog->addFunction(any_cast<Function *>(visit(f)));
    }

    return prog;
}

antlrcpp::Any CodeGenVisitor::visitFunction(ifccParser::FunctionContext *ctx) {
    //TODO HANDLE INVALID FUN TYPE
    IrType *returnType;
    string rawReturnType = ctx->TYPE()->getText();
    try {
        returnType = (IrType *) PrimaryType::parse(rawReturnType);
    } catch (const InvalidType &e) {
        if (rawReturnType == "void") {
            returnType = (IrType *) new Void();
        } else {
            //TODO REPLACE BY COMPILATION EXCEPTION
            cerr << e.what() << " at line " << ctx->start->getLine() << endl;
        }
    }

    auto *fun = new Function(ctx->VAR()->getText(), returnType);
    auto block = visitBlock(ctx->block());
    fun->setBlock(any_cast<Block *>(block));
    return fun;
}

/**
 *
 * @param ctx
 * @return Whether or not the block "stop" the function via a return.
 */
antlrcpp::Any CodeGenVisitor::visitBlock(ifccParser::BlockContext *ctx) {
    auto *block = new Block();
    for (auto statement: ctx->statement()) {
        auto *instruction = any_cast<IrInstruction *>(
                visitStatement(statement));
        block->addInstruction(instruction);
        bool stop = instruction->alwaysReturn;
        if (stop) break;
    }
    return block;
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

/**
 *
 * @param ctx
 * @return Whether or not the statement "stop" the function via a return.
 */
antlrcpp::Any
CodeGenVisitor::visitStatement(ifccParser::StatementContext *ctx) {
    auto t = visitChildren(ctx);
    auto *instruction = any_cast<IrInstruction *>(t);
    return instruction;
}

antlrcpp::Any
CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    string type = ctx->TYPE()->getText();
    try {
        auto *declaration = new Declaration(PrimaryType::parse(type));
        for (auto &rawDeclaration: ctx->rawDeclaration()) {
            auto *rd = any_cast<RawDeclaration *>(
                    visitRawDeclaration(rawDeclaration));
            declaration->addRawDeclaration(rd);
        }
        return (IrInstruction *) declaration;
    } catch (InvalidType &e) {
        //TODO
        throw e;
    }
}

antlrcpp::Any
CodeGenVisitor::visitRawDeclaration(ifccParser::RawDeclarationContext *ctx) {
    auto *name = new string(ctx->VAR()->getText());
    if (ctx->expression() != nullptr) { // Init is optional
        auto *expr = any_cast<IrInstruction *>(visit(ctx->expression()));
        return new RawDeclaration(name, (Expression *) expr);
    } else return new RawDeclaration(name, (Expression *) nullptr);
}

antlrcpp::Any
CodeGenVisitor::visitAssignment(ifccParser::AssignmentContext *ctx) {
    return (IrInstruction *) new Assignment(ctx->VAR()->getText(),
                                            (Expression *) any_cast<IrInstruction *>(
                                                    visit(ctx->expression())));
}

antlrcpp::Any CodeGenVisitor::visitConstant(ifccParser::ConstantContext *ctx) {
    try {
        return (IrInstruction *) new Constant(stoi(ctx->CONST()->getText()));
    } catch (exception &e) {
        throw e;//TODO
    }
}

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx) {
    return (IrInstruction *) new Variable(ctx->VAR()->getText());
}

antlrcpp::Any CodeGenVisitor::visitVarExpr(ifccParser::VarExprContext *ctx) {
    return (IrInstruction *) new Assignment(ctx->VAR()->getText(),
                                            (Expression *) any_cast<IrInstruction *>(
                                                    visit(ctx->expression())));
}

antlrcpp::Any CodeGenVisitor::visitRet(ifccParser::RetContext *ctx) {
    auto result = visit(ctx->expression());
    auto *expression = (Expression *) any_cast<IrInstruction *>(result);
    return (IrInstruction *) new Return(expression);
}

antlrcpp::Any CodeGenVisitor::visitAddSub(ifccParser::AddSubContext *ctx) {
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

antlrcpp::Any
CodeGenVisitor::visitTimesDivModulo(ifccParser::TimesDivModuloContext *ctx) {
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
CodeGenVisitor::visitBitwiseAnd(ifccParser::BitwiseAndContext *ctx) {
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
CodeGenVisitor::visitBitwiseXor(ifccParser::BitwiseXorContext *ctx) {
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
CodeGenVisitor::visitBitwiseOr(ifccParser::BitwiseOrContext *ctx) {
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
CodeGenVisitor::visitLogicalAnd(ifccParser::LogicalAndContext *ctx) {
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
CodeGenVisitor::visitLogicalOr(ifccParser::LogicalOrContext *ctx) {
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

