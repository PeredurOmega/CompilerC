
// Generated from C:/Users/pauls/CLionProjects/CompilerC/compiler\ifcc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccListener.h"


/**
 * This class provides an empty implementation of ifccListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ifccBaseListener : public ifccListener {
public:

  virtual void enterAxiom(ifccParser::AxiomContext * /*ctx*/) override { }
  virtual void exitAxiom(ifccParser::AxiomContext * /*ctx*/) override { }

  virtual void enterProg(ifccParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(ifccParser::ProgContext * /*ctx*/) override { }

  virtual void enterFunction(ifccParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(ifccParser::FunctionContext * /*ctx*/) override { }

  virtual void enterParameters(ifccParser::ParametersContext * /*ctx*/) override { }
  virtual void exitParameters(ifccParser::ParametersContext * /*ctx*/) override { }

  virtual void enterParameter(ifccParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(ifccParser::ParameterContext * /*ctx*/) override { }

  virtual void enterBlock(ifccParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(ifccParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(ifccParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ifccParser::StatementContext * /*ctx*/) override { }

  virtual void enterStatementWithoutDeclaration(ifccParser::StatementWithoutDeclarationContext * /*ctx*/) override { }
  virtual void exitStatementWithoutDeclaration(ifccParser::StatementWithoutDeclarationContext * /*ctx*/) override { }

  virtual void enterEmpty(ifccParser::EmptyContext * /*ctx*/) override { }
  virtual void exitEmpty(ifccParser::EmptyContext * /*ctx*/) override { }

  virtual void enterIfBlock(ifccParser::IfBlockContext * /*ctx*/) override { }
  virtual void exitIfBlock(ifccParser::IfBlockContext * /*ctx*/) override { }

  virtual void enterElseBlock(ifccParser::ElseBlockContext * /*ctx*/) override { }
  virtual void exitElseBlock(ifccParser::ElseBlockContext * /*ctx*/) override { }

  virtual void enterWhileBlock(ifccParser::WhileBlockContext * /*ctx*/) override { }
  virtual void exitWhileBlock(ifccParser::WhileBlockContext * /*ctx*/) override { }

  virtual void enterRet(ifccParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(ifccParser::RetContext * /*ctx*/) override { }

  virtual void enterDeclaration(ifccParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(ifccParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterRawDeclaration(ifccParser::RawDeclarationContext * /*ctx*/) override { }
  virtual void exitRawDeclaration(ifccParser::RawDeclarationContext * /*ctx*/) override { }

  virtual void enterExpAssignment(ifccParser::ExpAssignmentContext * /*ctx*/) override { }
  virtual void exitExpAssignment(ifccParser::ExpAssignmentContext * /*ctx*/) override { }

  virtual void enterAssignment(ifccParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(ifccParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterCompare(ifccParser::CompareContext * /*ctx*/) override { }
  virtual void exitCompare(ifccParser::CompareContext * /*ctx*/) override { }

  virtual void enterConstant(ifccParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(ifccParser::ConstantContext * /*ctx*/) override { }

  virtual void enterShift(ifccParser::ShiftContext * /*ctx*/) override { }
  virtual void exitShift(ifccParser::ShiftContext * /*ctx*/) override { }

  virtual void enterBitwiseXor(ifccParser::BitwiseXorContext * /*ctx*/) override { }
  virtual void exitBitwiseXor(ifccParser::BitwiseXorContext * /*ctx*/) override { }

  virtual void enterLogicalAnd(ifccParser::LogicalAndContext * /*ctx*/) override { }
  virtual void exitLogicalAnd(ifccParser::LogicalAndContext * /*ctx*/) override { }

  virtual void enterAddSub(ifccParser::AddSubContext * /*ctx*/) override { }
  virtual void exitAddSub(ifccParser::AddSubContext * /*ctx*/) override { }

  virtual void enterUnary(ifccParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(ifccParser::UnaryContext * /*ctx*/) override { }

  virtual void enterBitwiseAnd(ifccParser::BitwiseAndContext * /*ctx*/) override { }
  virtual void exitBitwiseAnd(ifccParser::BitwiseAndContext * /*ctx*/) override { }

  virtual void enterParenthesis(ifccParser::ParenthesisContext * /*ctx*/) override { }
  virtual void exitParenthesis(ifccParser::ParenthesisContext * /*ctx*/) override { }

  virtual void enterTimesDivModulo(ifccParser::TimesDivModuloContext * /*ctx*/) override { }
  virtual void exitTimesDivModulo(ifccParser::TimesDivModuloContext * /*ctx*/) override { }

  virtual void enterEqual(ifccParser::EqualContext * /*ctx*/) override { }
  virtual void exitEqual(ifccParser::EqualContext * /*ctx*/) override { }

  virtual void enterFunctionCall(ifccParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(ifccParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterVariable(ifccParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(ifccParser::VariableContext * /*ctx*/) override { }

  virtual void enterBitwiseOr(ifccParser::BitwiseOrContext * /*ctx*/) override { }
  virtual void exitBitwiseOr(ifccParser::BitwiseOrContext * /*ctx*/) override { }

  virtual void enterLogicalOr(ifccParser::LogicalOrContext * /*ctx*/) override { }
  virtual void exitLogicalOr(ifccParser::LogicalOrContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

