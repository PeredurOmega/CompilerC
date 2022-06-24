
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual std::any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual std::any visitProg(ifccParser::ProgContext *context) = 0;

    virtual std::any visitFunction(ifccParser::FunctionContext *context) = 0;

    virtual std::any visitFunctionDeclaration(ifccParser::FunctionDeclarationContext *context) = 0;

    virtual std::any visitParameters(ifccParser::ParametersContext *context) = 0;

    virtual std::any visitParameter(ifccParser::ParameterContext *context) = 0;

    virtual std::any visitArguments(ifccParser::ArgumentsContext *context) = 0;

    virtual std::any visitArgument(ifccParser::ArgumentContext *context) = 0;

    virtual std::any visitBlock(ifccParser::BlockContext *context) = 0;

    virtual std::any visitStatement(ifccParser::StatementContext *context) = 0;

    virtual std::any visitStatementWithoutDeclaration(ifccParser::StatementWithoutDeclarationContext *context) = 0;

    virtual std::any visitEmpty(ifccParser::EmptyContext *context) = 0;

    virtual std::any visitIfBlock(ifccParser::IfBlockContext *context) = 0;

    virtual std::any visitElseBlock(ifccParser::ElseBlockContext *context) = 0;

    virtual std::any visitWhileBlock(ifccParser::WhileBlockContext *context) = 0;

    virtual std::any visitRet(ifccParser::RetContext *context) = 0;

    virtual std::any visitDeclaration(ifccParser::DeclarationContext *context) = 0;

    virtual std::any visitRawDeclaration(ifccParser::RawDeclarationContext *context) = 0;

    virtual std::any visitExpAssignment(ifccParser::ExpAssignmentContext *context) = 0;

    virtual std::any visitAssignment(ifccParser::AssignmentContext *context) = 0;

    virtual std::any visitCompare(ifccParser::CompareContext *context) = 0;

    virtual std::any visitConstant(ifccParser::ConstantContext *context) = 0;

    virtual std::any visitShift(ifccParser::ShiftContext *context) = 0;

    virtual std::any visitBitwiseXor(ifccParser::BitwiseXorContext *context) = 0;

    virtual std::any visitLogicalAnd(ifccParser::LogicalAndContext *context) = 0;

    virtual std::any visitAddSub(ifccParser::AddSubContext *context) = 0;

    virtual std::any visitUnary(ifccParser::UnaryContext *context) = 0;

    virtual std::any visitBitwiseAnd(ifccParser::BitwiseAndContext *context) = 0;

    virtual std::any visitParenthesis(ifccParser::ParenthesisContext *context) = 0;

    virtual std::any visitTimesDivModulo(ifccParser::TimesDivModuloContext *context) = 0;

    virtual std::any visitEqual(ifccParser::EqualContext *context) = 0;

    virtual std::any visitFunctionCall(ifccParser::FunctionCallContext *context) = 0;

    virtual std::any visitVariable(ifccParser::VariableContext *context) = 0;

    virtual std::any visitBitwiseOr(ifccParser::BitwiseOrContext *context) = 0;

    virtual std::any visitLogicalOr(ifccParser::LogicalOrContext *context) = 0;


};

