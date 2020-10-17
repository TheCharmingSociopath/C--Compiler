//#include "ast.h"
#include <iostream>
using namespace std;
#include "constants.h"

class PostFixVisitor : public ASTvisitor
{

    map<string, Symbol> *SymbolTable;
public:

    PostFixVisitor(map<string, Symbol> *SymbolTable) : SymbolTable(SymbolTable) {}

    virtual void visit(ASTProg &node)
    {
        cout << "PostFixVisit traversal invoked" << endl;
        int i = 1;
        for (auto statement : node.statementList)
        {
            cout << "line " << i << " : ";
            statement->accept(*this);
            cout << endl;
            i = i + 1;
        }
    }

    virtual void visit(ASTBlock &node)
    {
        cout << "In visitASTBlock function. Block statements: " << endl;
        for (auto statement : node.statementList)
        {
            cout << ">>>>> ";
            statement->accept(*this);
            cout << endl;
        }
    }

    virtual void visit(ASTIfElse &node)
    {
        cout << "ASTIfElse" << endl;
        node.getExpr()->accept(*this);
        node.getIfBlock()->accept(*this);
        if (node.getElseBlock())
            node.getElseBlock()->accept(*this);
    }

    virtual void visit(ASTWhile &node) {
        cout << "ASTWhile" << endl;
        node.getExpr()->accept(*this);
        node.getBlock()->accept(*this);
    }

    virtual void visit(ASTTernary &node) {
        cout << "ASTTernary" << endl;
        node.getExpr()->accept(*this);
        node.getStat1()->accept(*this);
        node.getStat2()->accept(*this);
    }

    virtual void visit(ASTFor &node) {
        cout << "ASTFor" << endl;
        // for (auto expr : node.initialExprList) {
        //     expr->accept(*this);
        // }
        // node.conditionExpr->accept(*this);
        // for (auto expr : node.incrementExprList) {
        //     expr->accept(*this);
        // }
        // node.block->accept(*this);
        node.getBlock()->accept(*this);
        node.getInitExpr()->accept(*this);
        node.getIncrementExpr()->accept(*this);
        node.getConditionExpr()->accept(*this);
    }

    virtual void visit(ASTStatExpr &node)
    {
        cout << "ASTStatExpr" << endl;
        node.expr->accept(*this);
    }

    virtual void visit(ASTStatAssignExpr &node)
    {
        cout << node.id;
        cout << " = ";
        node.expr->accept(*this);
    }

    virtual void visit(ASTLocationIdentifier &node)
    {
        cout << "ASTLocationIdentifier visit function" << endl;
    }

    virtual void visit(ASTLocationIdentifierArray &node)
    {
        cout << "ASTLocationIdentifierArray visit function" << endl;
    }

    virtual void visit(ASTLocationIdentifierDoubleArray &node)
    {
        cout << "ASTLocationIdentifierDoubleArray visit function" << endl;
    }

    virtual void visit(ASTExpr &node)
    {
        cout << "ASTExpr visit function" << endl;
    }

    virtual void visit(ASTExprUnaryOp &node)
    {
        cout << " " + node.getUnary_operator();
        node.getExpr()->accept(*this);
    }

    virtual void visit(ASTVariableList &node)
    {
        ASTType *type = node.getType();
        type->accept(*this);
        vector<ASTDeclare*> identifierList = node.getIdentifierList();
        for(auto identifier : identifierList)
        {
            identifier->accept(*this);
        }
    }

    virtual void visit(ASTDeclare &node)
    {
        cout << " " << node.getIdentifier();
        if(node.getVal() != nullptr)
        {
            node.getVal()->accept(*this);
            cout << " " << node.getOp();
        }
    }
    virtual void visit(ASTType &node)
    {
        cout << " " << node.getType();
    }

    virtual void visit(ASTControl &node)
    {
        ASTExpr *expr = node.getExpr();
        if (expr != nullptr)
            expr->accept(*this);
        cout << " " + node.getCommand();
    }

    virtual void visit(ASTExprBinary &node)
    {
        ASTExpr *left = node.getLeft();
        ASTExpr *right = node.getRight();

        left->accept(*this);
        right->accept(*this);
        cout << " " + node.getBin_operator();
    }

    virtual void visit(ASTExprTernary &node)
    {
        ASTExpr *first = node.getFirst();
        ASTExpr *second = node.getSecond();
        ASTExpr *third = node.getThird();

        first->accept(*this);
        second->accept(*this);
        third->accept(*this);

        // visit(node.getFirst());
        // visit(node.getSecond());
        // visit(node.getThird());
        cout << " ?:";
    }

    virtual void visit(ASTExprIdentifier &node)
    {
        cout << " " << node.getIdentifier();
    }

    virtual void visit(ASTLiteral &node)
    {
        cout << "literal" << endl;
    }
    virtual void visit(ASTLiteralInt &node)
    {
        cout << " " << node.getIntLit();
    }    
        virtual void visit(ASTLiteralFloat &node)
    {
        float temp = node.getFloatLit();
        cout << " " << temp;
    }   
        virtual void visit(ASTLiteralString &node)
    {
        cout << " " << node.getStringLit();
    }   
        virtual void visit(ASTLiteralChar &node)
    {
        cout << " " << node.getCharLit();
    }   
        virtual void visit(ASTLiteralBool &node)
    {
        cout << " " << node.getBoolLit();
    }   
};