#include <iostream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"

#include "CodeGenVisitor.h"
#include "ir/Prog.h"
#include "opt/LiveRangeAnalyzer.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv) {
    stringstream in;
    if (argn == 2) {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
    } else {
        cerr << "usage: ifcc path/to/file.c" << endl;
        exit(1);
    }

    ANTLRInputStream input(in.str());

    ifccLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();

    ifccParser parser(&tokens);
    tree::ParseTree *tree = parser.axiom();

    if (parser.getNumberOfSyntaxErrors() != 0) {
        cerr << "error: syntax error during parsing" << endl;
        exit(1);
    }


    CodeGenVisitor v;
    Prog *prog = any_cast<Prog *>(v.visit(tree));
    auto *lra = new LiveRangeAnalyzer(prog->functions[0]);
    lra->launch();
    prog->affect();
    prog->renderX86(cout);

    return 0;
}
