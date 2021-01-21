#include <iostream>

#include "ExprLexer.cpp"
#include "ExprParser.cpp"
#include "antlr4-runtime.h"

#include "ExprBuildASTVisitor.h"

#include "SemanticCheckVisitor.h"
#include "IRVisitor.h"


using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[])
{
    std::ifstream stream;

    cout << "Processing input file " << argv[1] << endl;
    stream.open(argv[1]);

    ANTLRInputStream input(stream);

    ExprLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);

    ExprParser::ProgContext* ctx = parser.prog();

    SymbolTable *symbolTable = new SymbolTable();

    ExprVisitor* visitor = new ExprBuildASTVisitor();

    ASTProg* program_root = visitor->visitProg(ctx);

    SemanticCheckVisitor* scv = new SemanticCheckVisitor(symbolTable);
    scv->visit(*program_root);
 
    cout << "======================= IR ==================" << endl;

    IRVisitor *irv = new IRVisitor();
    irv->visit(*program_root);
    TheModule->print(llvm::errs(), nullptr);
    
    return 0;
}
