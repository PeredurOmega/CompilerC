#include "CodeGenVisitor.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    int retval = stoi(ctx->CONST()->getText());
    std::cout<<".globl	main\n"
               " main: \n"
               "   pushq   %rbp\n"
               "   movq    %rsp, %rbp\n"

               " 	movl	$"<<retval<<", %eax\n"
                                         "   popq %rbp\n"
                                         " 	ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitStatement(ifccParser::StatementContext *ctx){
    return visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    string type = ctx->TYPE();
}

antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx) {

}