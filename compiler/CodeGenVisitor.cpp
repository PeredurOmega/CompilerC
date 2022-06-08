#include "CodeGenVisitor.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    cout<<  ".globl	main\n"
            " main: \n"
            "     pushq   %rbp\n"
            "     movq    %rsp, %rbp\n";
    int retval = stoi(ctx->CONST()->getText());
    for(auto statement : ctx->statement()){
        visitStatement(statement);
    }

   cout <<  "     movl	$"<<retval<<", %eax\n"
            "     popq %rbp\n"
            "     ret\n";

    for(auto pair : symbolTable){
        cout << pair.first << " -> " << pair.second << endl;
    }
    return 0;

}

antlrcpp::Any CodeGenVisitor::visitStatement(ifccParser::StatementContext *ctx){
    return visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    string type = ctx->TYPE()->getText();
    for(auto &var : ctx->VAR()){
        currentOffset += 4;
        symbolTable[var->getText()] = -currentOffset;
    }
    for(auto &initCtx : ctx->init()){
        visitInit(initCtx);
    }
    return ctx->VAR();
}

antlrcpp::Any CodeGenVisitor::visitInit(ifccParser::InitContext *ctx) {
    string variable = ctx->VAR()->getText();
    currentOffset += 4;
    symbolTable[variable] = -currentOffset;
    currentVariable = variable;
    visitChildren(ctx);

    return ctx->VAR();
}

antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {
    currentVariable = ctx->VAR()->getText();
    visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitConstant(ifccParser::ConstantContext *ctx) {
    int offset = symbolTable[currentVariable];
    cout << "    movl    $"<<ctx->CONST()->getText()<<", "<<offset<<"(%rbp)"<<endl;
    return ctx->CONST();
}

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx) {
    int loffset = symbolTable[currentVariable];
    int roffset = symbolTable[ctx->VAR()->getText()];
    cout << "    movl    "<<roffset<<"(%rbp), %eax"<<endl;
    cout << "    movl    %eax, "<<loffset<<"(%rbp)"<<endl;
    return ctx->VAR();
}

antlrcpp::Any CodeGenVisitor::visitVarexpr(ifccParser::VarexprContext *ctx) {
    string temp = currentVariable;
    currentVariable = ctx->VAR()->getText();
    visitChildren(ctx);
    int loffset = symbolTable[temp];
    int roffset = symbolTable[ctx->VAR()->getText()];
    cout << "    movl    "<<roffset<<"(%rbp), %eax"<<endl;
    cout << "    movl    %eax, "<<loffset<<"(%rbp)"<<endl;

    return ctx->VAR()->getText();
}
