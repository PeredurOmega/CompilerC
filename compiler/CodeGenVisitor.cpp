#include "CodeGenVisitor.h"
#include "ir/Prog.h"
#include "ir/Declaration.h"
#include "ir/Expression.h"
#include "ir/OpExpression.h"
#include "ir/IfElse.h"
#include "ir/UnaryOp.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitAxiom(ifccParser::AxiomContext *ctx) {
    return visitProg(ctx->prog());
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    Prog *prog = new Prog("main");

    for (auto f: ctx->function()) {
        prog->addFunction(any_cast<Function *>(visit(f)));
    }

    prog->affect();
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
            returnType = (IrType *)
                    new Void();
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
    IrInstruction *compare;
    if (ctx->statementWithoutAssignment() != nullptr) {
        compare = any_cast<IrInstruction *>(visit(ctx->expression()));
    } else {
        compare = any_cast<IrInstruction *>(visit(ctx->expAssignment()));
    }

    auto *content = any_cast<IrInstruction *>(
            visit(ctx->statementWithoutAssignment()));

    bool alwaysReturn = content->alwaysReturn;
    ElseStatement *elseStatement = nullptr;
    if (ctx->elseBlock() != nullptr) {
        elseStatement = (ElseStatement *) any_cast<IrInstruction *>(
                visitElseBlock(ctx->elseBlock()));
        alwaysReturn = alwaysReturn & elseStatement->alwaysReturn;
    }

    auto *ifBlock = new IfStatement((Expression *) compare, content,
                                    elseStatement);
    ifBlock->alwaysReturn = alwaysReturn;
    return (IrInstruction *) ifBlock;
}

antlrcpp::Any
CodeGenVisitor::visitElseBlock(ifccParser::ElseBlockContext *ctx) {
    auto *statement = any_cast<IrInstruction *>(
            visitStatement(ctx->statement()));
    auto *elseStatement = new ElseStatement(statement);
    elseStatement->alwaysReturn = statement->alwaysReturn;
    return (IrInstruction *) elseStatement;
}

antlrcpp::Any
CodeGenVisitor::visitStatement(ifccParser::StatementContext *ctx) {
    auto t = visitChildren(ctx);
    auto *instruction = any_cast<IrInstruction *>(t);
    return instruction;
}

antlrcpp::Any
CodeGenVisitor::visitStatementWithoutAssignment(
        ifccParser::StatementWithoutAssignmentContext *ctx) {
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
            auto *rd = any_cast<IrInstruction *>(
                    visitRawDeclaration(rawDeclaration));
            declaration->addRawDeclaration((RawDeclaration *) rd);
        }
        return (IrInstruction *) declaration;
    } catch (InvalidType &e) {
        //TODO
        throw e;
    }
}

antlrcpp::Any
CodeGenVisitor::visitRawDeclaration(ifccParser::RawDeclarationContext *ctx) {
    auto var = ctx->VAR();
    auto varNames = new vector<string *>();
    for (auto v: var) {
        auto *name = new string(v->getText());
        varNames->push_back(name);
    }
    if (ctx->expression() != nullptr) { // Init is optional
        auto *expr = (Expression *) any_cast<IrInstruction *>(
                visit(ctx->expression()));
        expr->assignTo = varNames->back();
        if (varNames->size() > 1) {
            auto *rawDec = new RawDeclaration(varNames->front(),
                                              new VarExpr(varNames, expr));
            return (IrInstruction *) rawDec;
        } else {
            return (IrInstruction *) new RawDeclaration(varNames->back(), expr);
        }
    } else
        return (IrInstruction *) new RawDeclaration(varNames->back(),
                                                    (Expression *) nullptr);
}

antlrcpp::Any
CodeGenVisitor::visitAssignment(ifccParser::AssignmentContext *ctx) {
    return visitExpAssignment(ctx->expAssignment());
}

antlrcpp::Any CodeGenVisitor::visitConstant(ifccParser::ConstantContext *ctx) {
    try {
        auto constant = new Constant(stoi(ctx->CONST()->getText()));
        return (IrInstruction *) constant;
    } catch (exception &e) {
        throw e;//TODO
    }
}

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx) {
    return (IrInstruction *)
            new Variable(ctx->VAR()->getText());
}

antlrcpp::Any CodeGenVisitor::visitRet(ifccParser::RetContext *ctx) {
    any result;
    if (ctx->expression() != nullptr) {
        result = visit(ctx->expression());
    } else {
        result = visit(ctx->expAssignment());
    }
    auto *expression = (Expression *) any_cast<IrInstruction *>(result);
    return (IrInstruction *) new Return(expression);
}

antlrcpp::Any CodeGenVisitor::visitAddSub(ifccParser::AddSubContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == "-") {
        return (IrInstruction *) new SubOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "+") {
        return (IrInstruction *) new AddOperation(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any
CodeGenVisitor::visitTimesDivModulo(ifccParser::TimesDivModuloContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == "*") {
        return (IrInstruction *) new TimesOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "/") {
        return (IrInstruction *) new DivOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "%") {
        return (IrInstruction *) new ModuloOperation(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitShift(ifccParser::ShiftContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == ">>") {
        return (IrInstruction *) new ShiftRightOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "<<") {
        return (IrInstruction *) new ShiftLeftOperation(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitCompare(ifccParser::CompareContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == ">") {
        return (IrInstruction *) new GreatCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == ">=") {
        return (IrInstruction *) new GreatEqualCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == "<") {
        return (IrInstruction *) new LessCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == "<=") {
        return (IrInstruction *) new LessEqualCompare(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitEqual(ifccParser::EqualContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == "==") {
        return (IrInstruction *) new EqualCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == "!=") {
        return (IrInstruction *) new NotEqualCompare(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any
CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx) {
    if (ctx->expression() != nullptr) {
        auto *expr = (Expression *) any_cast<IrInstruction *>(
                visit(ctx->expression()));
        return (IrInstruction *) expr;
    } else {
        return visitExpAssignment(ctx->expAssignment());
    }
}

antlrcpp::Any
CodeGenVisitor::visitBitwiseAnd(ifccParser::BitwiseAndContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == "&") {
        return (IrInstruction *) new BitwiseAnd(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any
CodeGenVisitor::visitBitwiseXor(ifccParser::BitwiseXorContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == "^") {
        return (IrInstruction *) new BitwiseXor(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any
CodeGenVisitor::visitBitwiseOr(ifccParser::BitwiseOrContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(visit(expr[1]));
    if (ctx->op->getText() == "|") {
        return (IrInstruction *) new BitwiseOr(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitUnary(ifccParser::UnaryContext *ctx) {
    auto *rExpr = (Expression *) any_cast<IrInstruction *>(
            visit(ctx->expression()));
    if (ctx->op->getText() == "-") {
        return (IrInstruction *) new MinusUnary(rExpr);
    } else if (ctx->op->getText() == "~") {
        return (IrInstruction *) new BitwiseNotUnary(rExpr);
    } else if (ctx->op->getText() == "!") {
        return (IrInstruction *) new NotUnary(rExpr);
    } else if (ctx->op->getText() == "+") {
        return (IrInstruction *) new PlusUnary(rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
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


antlrcpp::Any
CodeGenVisitor::visitExpAssignment(ifccParser::ExpAssignmentContext *ctx) {
    auto var = ctx->VAR();
    auto varNames = new vector<string *>();
    for (auto v: var) {
        auto *name = new string(v->getText());
        varNames->push_back(name);
    }
    auto *expr = (Expression *) any_cast<IrInstruction *>(
            visit(ctx->expression()));
    expr->assignTo = varNames->back();
    if (varNames->size() > 1) {
        return (IrInstruction *) new VarExpr(varNames, expr);
    } else {
        return (IrInstruction *) expr;
    }
}

