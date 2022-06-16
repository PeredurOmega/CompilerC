
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ifccParser.
 */
class  ifccListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAxiom(ifccParser::AxiomContext *ctx) = 0;
  virtual void exitAxiom(ifccParser::AxiomContext *ctx) = 0;

  virtual void enterProg(ifccParser::ProgContext *ctx) = 0;
  virtual void exitProg(ifccParser::ProgContext *ctx) = 0;

  virtual void enterFunction(ifccParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(ifccParser::FunctionContext *ctx) = 0;

  virtual void enterParameters(ifccParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(ifccParser::ParametersContext *ctx) = 0;

  virtual void enterParameter(ifccParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(ifccParser::ParameterContext *ctx) = 0;

  virtual void enterBlock(ifccParser::BlockContext *ctx) = 0;
  virtual void exitBlock(ifccParser::BlockContext *ctx) = 0;

  virtual void enterStatement(ifccParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ifccParser::StatementContext *ctx) = 0;

  virtual void enterIfBlock(ifccParser::IfBlockContext *ctx) = 0;
  virtual void exitIfBlock(ifccParser::IfBlockContext *ctx) = 0;

  virtual void enterElseBlock(ifccParser::ElseBlockContext *ctx) = 0;
  virtual void exitElseBlock(ifccParser::ElseBlockContext *ctx) = 0;

  virtual void enterRet(ifccParser::RetContext *ctx) = 0;
  virtual void exitRet(ifccParser::RetContext *ctx) = 0;

  virtual void enterDeclaration(ifccParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(ifccParser::DeclarationContext *ctx) = 0;

  virtual void enterRawDeclaration(ifccParser::RawDeclarationContext *ctx) = 0;
  virtual void exitRawDeclaration(ifccParser::RawDeclarationContext *ctx) = 0;

  virtual void enterAssignment(ifccParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(ifccParser::AssignmentContext *ctx) = 0;

  virtual void enterCompare(ifccParser::CompareContext *ctx) = 0;
  virtual void exitCompare(ifccParser::CompareContext *ctx) = 0;

  virtual void enterConstant(ifccParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(ifccParser::ConstantContext *ctx) = 0;

  virtual void enterShift(ifccParser::ShiftContext *ctx) = 0;
  virtual void exitShift(ifccParser::ShiftContext *ctx) = 0;

  virtual void enterBitwiseXor(ifccParser::BitwiseXorContext *ctx) = 0;
  virtual void exitBitwiseXor(ifccParser::BitwiseXorContext *ctx) = 0;

  virtual void enterLogicalAnd(ifccParser::LogicalAndContext *ctx) = 0;
  virtual void exitLogicalAnd(ifccParser::LogicalAndContext *ctx) = 0;

  virtual void enterAddSub(ifccParser::AddSubContext *ctx) = 0;
  virtual void exitAddSub(ifccParser::AddSubContext *ctx) = 0;

  virtual void enterUnary(ifccParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(ifccParser::UnaryContext *ctx) = 0;

  virtual void enterBitwiseAnd(ifccParser::BitwiseAndContext *ctx) = 0;
  virtual void exitBitwiseAnd(ifccParser::BitwiseAndContext *ctx) = 0;

  virtual void enterParenthesis(ifccParser::ParenthesisContext *ctx) = 0;
  virtual void exitParenthesis(ifccParser::ParenthesisContext *ctx) = 0;

  virtual void enterTimesDivModulo(ifccParser::TimesDivModuloContext *ctx) = 0;
  virtual void exitTimesDivModulo(ifccParser::TimesDivModuloContext *ctx) = 0;

  virtual void enterEqual(ifccParser::EqualContext *ctx) = 0;
  virtual void exitEqual(ifccParser::EqualContext *ctx) = 0;

  virtual void enterVarExpr(ifccParser::VarExprContext *ctx) = 0;
  virtual void exitVarExpr(ifccParser::VarExprContext *ctx) = 0;

  virtual void enterVariable(ifccParser::VariableContext *ctx) = 0;
  virtual void exitVariable(ifccParser::VariableContext *ctx) = 0;

  virtual void enterBitwiseOr(ifccParser::BitwiseOrContext *ctx) = 0;
  virtual void exitBitwiseOr(ifccParser::BitwiseOrContext *ctx) = 0;

  virtual void enterLogicalOr(ifccParser::LogicalOrContext *ctx) = 0;
  virtual void exitLogicalOr(ifccParser::LogicalOrContext *ctx) = 0;


};

