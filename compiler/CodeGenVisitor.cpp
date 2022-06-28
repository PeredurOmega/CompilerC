#include "CodeGenVisitor.h"
#include "ast/Prog.h"
#include "ast/Declaration.h"
#include "ast/Expression.h"
#include "ast/OpExpression.h"
#include "ast/IfElse.h"
#include "ast/UnaryOp.h"
#include "ast/While.h"
#include "ast/Return.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitAxiom(ifccParser::AxiomContext *ctx) {
    return visitProg(ctx->prog());
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    auto *prog = new Prog("main");

    for (auto *f: ctx->function()) {
        prog->addFunction(any_cast<Function *>(visit(f)));
    }

    for (auto *var: ctx->staticVariable()) {
        prog->declareStaticVariable((StaticDeclaration *) any_cast<Instruction *>(visit(var)));
    }

    return prog;
}

antlrcpp::Any CodeGenVisitor::visitFunction(ifccParser::FunctionContext *ctx) {
    //TODO HANDLE INVALID FUN TYPE
    IrType *returnType;
    if (ctx->TYPE() != nullptr) {
        string rawReturnType = ctx->TYPE()->getText();
        try {
            returnType = (IrType *) PrimaryType::parse(rawReturnType);
        } catch (const InvalidType &e) {
            cerr << e.what() << " at line " << ctx->start->getLine() << endl;
        }
    } else {
        returnType = (IrType *) new Void();
    }

    auto *parameters = new vector<Parameter *>;
    if (ctx->parameters() != nullptr) {
        parameters = any_cast<vector<Parameter *> *>(visitParameters(ctx->parameters()));
    }
    auto *fun = new Function(ctx->VAR()->getText(), returnType, *parameters);
    auto block = visitBlock(ctx->block());
    fun->setBlock((Block *) any_cast<Instruction *>(block));
    return fun;
}

antlrcpp::Any CodeGenVisitor::visitFunctionDeclaration(ifccParser::FunctionDeclarationContext *ctx) {
    return (Instruction *) new Empty();
}

antlrcpp::Any CodeGenVisitor::visitProcedureCall(ifccParser::ProcedureCallContext *ctx) {
    auto *arguments = new vector<Expression *>;
    if (ctx->arguments() != nullptr) {
        arguments = any_cast<vector<Expression *> *>(visitArguments(ctx->arguments()));
    }

    return (Instruction *) new FunctionCall(ctx->VAR()->getText(), arguments);
}

antlrcpp::Any CodeGenVisitor::visitFunctionCall(ifccParser::FunctionCallContext *ctx) {
    auto *arguments = new vector<Expression *>;
    if (ctx->arguments() != nullptr) {
        arguments = any_cast<vector<Expression *> *>(visitArguments(ctx->arguments()));
    }

    return (Instruction *) new FunctionCall(ctx->VAR()->getText(), arguments);
}

antlrcpp::Any CodeGenVisitor::visitParameters(ifccParser::ParametersContext *ctx) {
    auto *parameters = new vector<Parameter *>();
    for (auto parameter: ctx->parameter()) {
        parameters->push_back(any_cast<Parameter *>(visitParameter(parameter)));
    }
    return parameters;
}

antlrcpp::Any CodeGenVisitor::visitParameter(ifccParser::ParameterContext *ctx) {
    PrimaryType *type;
    string rawType = ctx->TYPE()->getText();
    try {
        type = PrimaryType::parse(rawType);
    } catch (const InvalidType &e) {
        //TODO REPLACE BY COMPILATION EXCEPTION
        cerr << e.what() << " at line " << ctx->start->getLine() << endl;
    }
    return new Parameter(type, ctx->VAR()->getText());
}

antlrcpp::Any CodeGenVisitor::visitArguments(ifccParser::ArgumentsContext *ctx) {
    auto *arguments = new vector<Expression *>();
    for (auto argument: ctx->argument()) {
        arguments->push_back(any_cast<Expression *>(visitArgument(argument)));
    }
    return arguments;
}

antlrcpp::Any CodeGenVisitor::visitArgument(ifccParser::ArgumentContext *ctx) {
    auto *expr = (Expression *) any_cast<Instruction *>(visit(ctx->expression()));
    return expr;
}

antlrcpp::Any CodeGenVisitor::visitBlock(ifccParser::BlockContext *ctx) {
    auto *block = new Block();
    for (auto statement: ctx->statement()) {
        auto *instruction = any_cast<Instruction *>(visitStatement(statement));
        block->addInstruction(instruction);
        if (instruction->alwaysReturn) break;
    }
    return (Instruction *) block;
}

antlrcpp::Any CodeGenVisitor::visitIfBlock(ifccParser::IfBlockContext *ctx) {
    Instruction *compare;
    if (ctx->statementWithoutDeclaration() != nullptr) {
        compare = any_cast<Instruction *>(visit(ctx->exp()));
    } else {
        compare = any_cast<Instruction *>(visit(ctx->expAssignment()));
    }

    auto *content = any_cast<Instruction *>(
            visit(ctx->statementWithoutDeclaration()));

    bool alwaysReturn = content->alwaysReturn;
    bool conditionalReturn = content->conditionalReturn;
    ElseStatement *elseStatement = nullptr;
    if (ctx->elseBlock() != nullptr) {
        elseStatement = (ElseStatement *) any_cast<Instruction *>(visitElseBlock(ctx->elseBlock()));
        conditionalReturn =
                (alwaysReturn != elseStatement->alwaysReturn && (alwaysReturn || elseStatement->alwaysReturn)) ||
                conditionalReturn || elseStatement->conditionalReturn;
        alwaysReturn = alwaysReturn && elseStatement->alwaysReturn;
    } else if (alwaysReturn || conditionalReturn) {
        conditionalReturn = true;
        alwaysReturn = false;
    }

    auto *ifBlock = new IfStatement((Expression *) compare, content, elseStatement);
    ifBlock->alwaysReturn = alwaysReturn;
    ifBlock->conditionalReturn = conditionalReturn;
    return (Instruction *) ifBlock;
}

antlrcpp::Any CodeGenVisitor::visitElseBlock(ifccParser::ElseBlockContext *ctx) {
    auto *statement = any_cast<Instruction *>(visitStatement(ctx->statement()));
    auto *elseStatement = new ElseStatement(statement);
    elseStatement->alwaysReturn = statement->alwaysReturn;
    elseStatement->alwaysReturn = statement->alwaysReturn;
    elseStatement->conditionalReturn = statement->conditionalReturn;
    return (Instruction *) elseStatement;
}

antlrcpp::Any CodeGenVisitor::visitStatement(ifccParser::StatementContext *ctx) {
    auto t = visitChildren(ctx);
    auto *instruction = any_cast<Instruction *>(t);
    return instruction;
}

antlrcpp::Any CodeGenVisitor::visitStatementWithoutDeclaration(ifccParser::StatementWithoutDeclarationContext *ctx) {
    auto t = visitChildren(ctx);
    auto *instruction = any_cast<Instruction *>(t);
    return instruction;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    string type = ctx->TYPE()->getText();
    try {
        auto *declaration = new Declaration(PrimaryType::parse(type));
        for (auto &rawDeclaration: ctx->rawDeclaration()) {
            auto *rd = any_cast<Instruction *>(visitRawDeclaration(rawDeclaration));
            declaration->addRawDeclaration((RawDeclaration *) rd);
        }
        return (Instruction *) declaration;
    } catch (InvalidType &e) {
        //TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitRawDeclaration(ifccParser::RawDeclarationContext *ctx) {
    auto var = ctx->VAR();
    auto varNames = new vector<string *>();
    for (auto v: var) {
        auto *name = new string(v->getText());
        varNames->push_back(name);
    }
    if (ctx->exp() != nullptr) { // Init is optional
        auto *expr = (Expression *) any_cast<Instruction *>(visit(ctx->exp()));
        expr->assignTo = varNames->back();
        if (varNames->size() > 1) {
            auto *rawDec = new RawDeclaration(varNames->front(), new VarExpr(varNames, expr));
            return (Instruction *) rawDec;
        } else {
            return (Instruction *) new RawDeclaration(varNames->back(), expr);
        }
    } else
        return (Instruction *) new RawDeclaration(varNames->back(), (Expression *) nullptr);
}

antlrcpp::Any CodeGenVisitor::visitAssignment(ifccParser::AssignmentContext *ctx) {
    return visitExpAssignment(ctx->expAssignment());
}

antlrcpp::Any CodeGenVisitor::visitConstant(ifccParser::ConstantContext *ctx) {
    try {
        if (ctx->CHAR_CONST() != nullptr) {
            auto constant = new Constant((int) ctx->CHAR_CONST()->getText()[1]);
            return (Instruction *) constant;
        } else if (ctx->INT_CONST() != nullptr) {
            auto constant = new Constant(stoi(ctx->INT_CONST()->getText()));
            return (Instruction *) constant;
        } else {
            throw InvalidType();
        }
    } catch (exception &e) {
        throw e;//TODO
    }
}

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx) {
    return (Instruction *) new Variable(ctx->VAR()->getText());
}

antlrcpp::Any CodeGenVisitor::visitRet(ifccParser::RetContext *ctx) {
    any result;
    if (ctx->exp() != nullptr) {
        result = visit(ctx->exp());
    } else {
        result = visit(ctx->expAssignment());
    }
    auto *expression = (Expression *) any_cast<Instruction *>(result);
    return (Instruction *) new Return(expression);
}

antlrcpp::Any CodeGenVisitor::visitAddSub(ifccParser::AddSubContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "-") {
        return (Instruction *) new SubOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "+") {
        return (Instruction *) new AddOperation(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any
CodeGenVisitor::visitTimesDivModulo(ifccParser::TimesDivModuloContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "*") {
        return (Instruction *) new TimesOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "/") {
        return (Instruction *) new DivOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "%") {
        return (Instruction *) new ModuloOperation(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitShift(ifccParser::ShiftContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == ">>") {
        return (Instruction *) new ShiftRightOperation(lExpr, rExpr);
    } else if (ctx->op->getText() == "<<") {
        return (Instruction *) new ShiftLeftOperation(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitCompare(ifccParser::CompareContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == ">") {
        return (Instruction *) new GreatCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == ">=") {
        return (Instruction *) new GreatEqualCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == "<") {
        return (Instruction *) new LessCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == "<=") {
        return (Instruction *) new LessEqualCompare(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitEqual(ifccParser::EqualContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "==") {
        return (Instruction *) new EqualCompare(lExpr, rExpr);
    } else if (ctx->op->getText() == "!=") {
        return (Instruction *) new NotEqualCompare(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx) {
    if (ctx->expression() != nullptr) {
        auto *expr = (Expression *) any_cast<Instruction *>(visit(ctx->expression()));
        return (Instruction *) expr;
    } else {
        return visitExpAssignment(ctx->expAssignment());
    }
}

antlrcpp::Any CodeGenVisitor::visitBitwiseAnd(ifccParser::BitwiseAndContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "&") {
        return (Instruction *) new BitwiseAnd(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitBitwiseXor(ifccParser::BitwiseXorContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "^") {
        return (Instruction *) new BitwiseXor(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitBitwiseOr(ifccParser::BitwiseOrContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "|") {
        return (Instruction *) new BitwiseOr(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitUnary(ifccParser::UnaryContext *ctx) {
    auto *rExpr = (Expression *) any_cast<Instruction *>(
            visit(ctx->expression()));
    if (ctx->op->getText() == "-") {
        return (Instruction *) new MinusUnary(rExpr);
    } else if (ctx->op->getText() == "~") {
        return (Instruction *) new BitwiseNotUnary(rExpr);
    } else if (ctx->op->getText() == "!") {
        return (Instruction *) new NotUnary(rExpr);
    } else if (ctx->op->getText() == "+") {
        return (Instruction *) new PlusUnary(rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitLogicalAnd(ifccParser::LogicalAndContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "&&") {
        return (Instruction *) new LogicalAnd(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitLogicalOr(ifccParser::LogicalOrContext *ctx) {
    vector<ifccParser::ExpressionContext *> expr = ctx->expression();
    auto *lExpr = (Expression *) any_cast<Instruction *>(visit(expr[0]));
    auto *rExpr = (Expression *) any_cast<Instruction *>(visit(expr[1]));
    if (ctx->op->getText() == "||") {
        return (Instruction *) new LogicalOr(lExpr, rExpr);
    } else {
        BadOperation e = BadOperation();
        cerr << e.what() << " '" << ctx->op->getText() << "'";//TODO
        throw e;
    }
}


antlrcpp::Any CodeGenVisitor::visitExpAssignment(ifccParser::ExpAssignmentContext *ctx) {
    auto var = ctx->VAR();
    auto varNames = new vector<string *>();
    for (auto v: var) {
        auto *name = new string(v->getText());
        varNames->push_back(name);
    }
    auto *expr = (Expression *) any_cast<Instruction *>(visit(ctx->exp()));
    expr->assignTo = varNames->back();
    if (varNames->size() > 1) {
        return (Instruction *) new VarExpr(varNames, expr);
    } else {
        return (Instruction *) expr;
    }
}

antlrcpp::Any CodeGenVisitor::visitEmpty(ifccParser::EmptyContext *ctx) {
    return (Instruction *) new Empty();
}

antlrcpp::Any CodeGenVisitor::visitWhileBlock(ifccParser::WhileBlockContext *ctx) {
    auto *compare = (Expression *) any_cast<Instruction *>(visit(ctx->exp()));
    auto *content = any_cast<Instruction *>(visit(ctx->statementWithoutDeclaration()));
    auto *whileStatement = new WhileStatement(compare, content);
    if (content->alwaysReturn) whileStatement->conditionalReturn = true;
    return (Instruction *) whileStatement;
}

antlrcpp::Any CodeGenVisitor::visitStaticVariable(ifccParser::StaticVariableContext *ctx) {
    string type = ctx->TYPE()->getText();
    try {
        auto *var = new string(ctx->VAR()->getText());
        auto *t = PrimaryType::parse(type);
        try {
            auto initValue = stoi(ctx->CONST()->getText());
            auto *declaration = new StaticDeclaration(t, var, initValue);
            return (Instruction *) declaration;
        } catch (exception &e) {
            throw e;//TODO
        }
    } catch (InvalidType &e) {
        //TODO
        throw e;
    }
}

antlrcpp::Any CodeGenVisitor::visitExp(ifccParser::ExpContext *ctx) {
    auto *expr = (Expression *) any_cast<Instruction *>(visit(ctx->expression()));
    return (Instruction *) expr->propagateConstant();
}
