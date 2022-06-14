
// Generated from /home/bmayouddup/CLionProjects/CompilerC/compiler/ifcc.g4 by ANTLR 4.10.1

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

    virtual std::any visitStatement(ifccParser::StatementContext *context) = 0;

    virtual std::any visitRet(ifccParser::RetContext *context) = 0;

    virtual std::any visitDeclaration(ifccParser::DeclarationContext *context) = 0;

    virtual std::any visitInit(ifccParser::InitContext *context) = 0;

    virtual std::any visitAffectation(ifccParser::AffectationContext *context) = 0;

    virtual std::any visitTimes(ifccParser::TimesContext *context) = 0;

    virtual std::any visitConstant(ifccParser::ConstantContext *context) = 0;

    virtual std::any visitVarexpr(ifccParser::VarexprContext *context) = 0;

    virtual std::any visitVariable(ifccParser::VariableContext *context) = 0;

    virtual std::any visitAddsub(ifccParser::AddsubContext *context) = 0;

    virtual std::any visitParenthesis(ifccParser::ParenthesisContext *context) = 0;


};

