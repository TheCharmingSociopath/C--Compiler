#include "ExprVisitor.h"
#include "SymbolTable.h"
#include "ast.h"
#include <iostream>
#include <vector>

using namespace std;

class ExprBuildASTVisitor : public ExprVisitor {
public:
    /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext* context)
    {
        // // cout << "In visitProg" << endl;
        ASTProg* node = new ASTProg();
        ASTMethodDecl* methodNode;
        for (auto method : context->methodDecl()) {
            methodNode = visit(method);
            if (methodNode != nullptr) {
                node->methodList.push_back(methodNode);
            }
        }
        return (ASTProg*)node;
    }

    // virtual antlrcpp::Any visitStatExpr(ExprParser::StatExprContext *context)
    // {
    //     // cout << "In visitStatExpr" << endl;
    //     ASTStatExpr *node = new ASTStatExpr();
    //     node->expr = visit(context->expr());
    //     return (ASTStat *) node;
    // }

    virtual antlrcpp::Any visitMethodCall(ExprParser::MethodCallContext* context)
    {
        // cout << "In visitMethodCall method" << endl;
        std::vector<ASTExpr*> exprList;
        for (auto expr : context->expr()) {
            ASTExpr* temp = visit(expr);
            if (temp)
                exprList.push_back(temp);
        }

        ASTMethodCall* node = new ASTMethodCall(context->STRING()->getText(), exprList);
        return (ASTMethodCall*)node;
    }

    virtual antlrcpp::Any visitStatMethodCall(ExprParser::StatMethodCallContext* context)
    {
        // cout << "In visitStatMethodCall method" << endl;
        ASTMethodCall* node = visit(context->methodCall());
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitMethodArg(ExprParser::MethodArgContext* context)
    {
        // cout << "In visitMethodArg method" << endl;
        ASTMethodArg* node = new ASTMethodArg(visit(context->type()), context->IDENTIFIER()->getText(), nullptr, nullptr);
        return (ASTMethodArg*)node;
    }

    virtual antlrcpp::Any visitMethodArg1D(ExprParser::MethodArg1DContext* context)
    {
        // cout << "In visitMethodArg1D method" << endl;
        
        ASTMethodArg* node = new ASTMethodArg(visit(context->type()), context->IDENTIFIER()->getText(), visit(context->expr()), nullptr);
        return (ASTMethodArg*)node;
    }

    virtual antlrcpp::Any visitMethodArg2D(ExprParser::MethodArg2DContext* context)
    {
        // cout << "In visitMethodArg2D method" << endl;
        ASTMethodArg* node = new ASTMethodArg(visit(context->type()), context->IDENTIFIER()->getText(), visit(context->expr(0)), visit(context->expr(1)));
        return (ASTMethodArg*)node;
    }

    virtual antlrcpp::Any visitMethodDecl(ExprParser::MethodDeclContext* context)
    {
        // cout << "In visitMethodDecl" << endl;
        std::vector<ASTMethodArg*> argsList;
        ASTMethodArg* temp;
        for (auto arg : context->methodArg1()) {
            temp = visit(arg);
            if (temp)
                argsList.push_back(temp);
        }

        ASTBlock* block = visit(context->block());
        ASTType *Type = new ASTType("void");
        if (context->type() != nullptr) {
            Type = visit(context->type());
        }
        ASTMethodDecl* node = new ASTMethodDecl(Type, context->IDENTIFIER()->getText(), argsList, block);
        // // cout << "ping" << endl;
        return (ASTMethodDecl*)node;
    }

    virtual antlrcpp::Any visitExprMethodCall(ExprParser::ExprMethodCallContext* context)
    {
        ASTMethodCall* node = visit(context->methodCall());
        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitBlock(ExprParser::BlockContext* context)
    {
        // cout << "In visitBlock" << endl;
        ASTBlock* node = new ASTBlock();
        ASTStat* statNode;
        for (auto statement : context->statement()) {
            statNode = visit(statement);
            if (statNode != nullptr) {
                node->statementList.push_back(statNode);
            }
        }
        // // cout << "PING" << endl;
        return (ASTBlock*)node;
    }

    virtual antlrcpp::Any visitStatFor(ExprParser::StatForContext* context)
    {
        // cout << "In visitStatFor method" << endl;
        // ASTFor *node = new ASTFor();
        // ASTExpr *exprNode;
        // for (auto expression : context->expr(0)) {
        //     exprNode = visit(expression);
        //     if (exprNode != nullptr)
        //         node->initialExprList.push_back(exprNode);
        // }
        // node->conditionExpr = visit(context->expr(1));
        // for (auto expr : context->expr(2)) {
        //     ASTExpr *temp = visit(expr);
        //     if (temp)
        //         node->incrementExprList.push_back(temp);
        // }
        // node->block = visit(context->block());
        ASTFor* node = new ASTFor(visit(context->expr(0)), visit(context->expr(1)), visit(context->expr(2)), visit(context->block()));
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitStatBlock(ExprParser::StatBlockContext* context)
    {
        // cout << "In visitStatBlock" << endl;
        ASTBlock* node = visit(context->block());
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitStatIfElse(ExprParser::StatIfElseContext* context)
    {
        // cout << "In visitStatIfElse method" << endl;
        ASTExpr* expr = visit(context->expr());
        ASTBlock *ifBlock = visit(context->block(0)), *elseBlock = nullptr;
        if (context->block(1) != nullptr) {
            elseBlock = visit(context->block(1));
        }
        ASTIfElse* node = new ASTIfElse(expr, ifBlock, elseBlock);
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitStatWhile(ExprParser::StatWhileContext* context)
    {
        // cout << "In visitStatWhile method" << endl;
        ASTExpr* expr = visit(context->expr());
        ASTBlock* block = visit(context->block());
        ASTWhile* node = new ASTWhile(expr, block);
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitStatTernary(ExprParser::StatTernaryContext* context)
    {
        // cout << "In visitStatTernary method" << endl;
        ASTExpr* expr = visit(context->expr());
        ASTStat *stat1 = visit(context->statement(0)), *stat2 = visit(context->statement(1));
        ASTTernary* node = new ASTTernary(expr, stat1, stat2);
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitStatVariable(ExprParser::StatVariableContext* context)
    {
        // cout << "In visitStatVariable" << endl;
        ASTVariableList* node = visit(context->variable());
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitStatAssignExpr(ExprParser::StatAssignExprContext* context)
    {
        // cout << "In visitStatAssignExpr" << endl;
        ASTExpr* left = visit(context->location());
        string op = context->ASSIGN_OP()->getText();
        ASTExpr* right = visit(context->expr());
        ASTExprBinary* node = new ASTExprBinary(op, left, right);
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitStatementControl(ExprParser::StatementControlContext* context)
    {
        // cout << "In visitStatementControl" << endl;

        ASTControl* control = visit(context->control());
        return (ASTStat*)control;
    }

    // virtual antlrcpp::Any visitStatNewLine(ExprParser::StatNewLineContext *context)
    // {
    //     // cout << "In visitStatNewLine" << endl;

    //     return (ASTStat *) nullptr;
    // }

    virtual antlrcpp::Any visitExprLiteral(ExprParser::ExprLiteralContext* context)
    {
        // cout << "In visitExprLiteral" << endl;
        ASTLiteral* node = visit(context->literal());
        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprMulDivModOp(ExprParser::ExprMulDivModOpContext* context)
    {
        // cout << "In visitExprMulDivModOp method" << endl;
        ASTExpr* left;
        ASTExpr* right;

        ASTExprBinary* node;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        if (op[0] == '*')
            node = new ASTExprBinary("*", left, right);
        else if (op[0] == '/')
            node = new ASTExprBinary("/", left, right);
        else
            node = new ASTExprBinary("%", left, right);

        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprAddSubOp(ExprParser::ExprAddSubOpContext* context)
    {
        // cout << "In visitExprAddSubOp method" << endl;
        ASTExprBinary* node;
        ASTExpr *left, *right;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        if (op[0] == '+')
            node = new ASTExprBinary("+", left, right);
        else
            node = new ASTExprBinary("-", left, right);

        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprRelationalOp(ExprParser::ExprRelationalOpContext* context)
    {
        // cout << "In visitExprRelationalOp method" << endl;
        ASTExprBinary* node;
        ASTExpr *left, *right;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        node = new ASTExprBinary(op, left, right);

        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprEqualityOp(ExprParser::ExprEqualityOpContext* context)
    {
        // cout << "In visitExprEqualityOp method" << endl;
        ASTExprBinary* node;
        ASTExpr *left, *right;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        node = new ASTExprBinary(op, left, right);

        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprBoolOp(ExprParser::ExprBoolOpContext* context)
    {
        // cout << "In visitExprBoolOp method" << endl;
        ASTExprBinary* node;
        ASTExpr *left, *right;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        node = new ASTExprBinary(op, left, right);

        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprConditionalOp(ExprParser::ExprConditionalOpContext* context)
    {
        // cout << "In visitExprConditionalOp method" << endl;
        ASTExprBinary* node;
        ASTExpr *left, *right;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        node = new ASTExprBinary(op, left, right);

        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprAssignOp(ExprParser::ExprAssignOpContext* context)
    {
        // cout << "In visitExprAssignOp method" << endl;
        ASTExprBinary* node;
        ASTExpr *left, *right;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->ASSIGN_OP()->getText();

        node = new ASTExprBinary(op, left, right);

        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExprUnaryOp(ExprParser::ExprUnaryOpContext* context)
    {
        // cout << "In visitExprUnaryOp method" << endl;
        ASTExprUnaryOp* node;
        ASTExpr* expr;

        expr = visit(context->expr());

        string op = context->op->getText();

        node = new ASTExprUnaryOp(op, expr);

        return (ASTExpr*)node;
    }

    // virtual antlrcpp::Any visitExprIdentifier(ExprParser::ExprIdentifierContext* context)
    // {
    //     // cout << "In visitExprIdentifier" << endl;
    //     string id = context->IDENTIFIER()->getText();

    //     ASTExprIdentifier* node = new ASTExprIdentifier(id);

    //     return (ASTExpr*)node;
    // }

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext* context)
    {
        // cout << "In visitExprParenthesis" << endl;
        return visit(context->expr());
    }

    virtual antlrcpp::Any visitExprLocation(ExprParser::ExprLocationContext *context) 
    {
        // cout << "In visitExprLocation" << endl;
        ASTExpr* next = visit(context->location());
        return next;
    }

    virtual antlrcpp::Any visitControlReturn(ExprParser::ControlReturnContext* context)
    {
        // cout << "In visitControlReturn" << endl;
        ASTExpr* ret = nullptr;
        if (context->expr() != nullptr)
            ret = visit(context->expr());
        ASTControl* node = new ASTControl("return", ret);
        return (ASTControl*)node;
    }

    virtual antlrcpp::Any visitControlBreak(ExprParser::ControlBreakContext* context)
    {
        // cout << "In visitControlBreak" << endl;
        ASTControl* node = new ASTControl("break", nullptr);
        return (ASTControl*)node;
    }

    virtual antlrcpp::Any visitControlContinue(ExprParser::ControlContinueContext* context)
    {
        // cout << "In visitControlContinue" << endl;
        ASTControl* node = new ASTControl("continue", nullptr);
        return (ASTControl*)node;
    }

    virtual antlrcpp::Any visitType(ExprParser::TypeContext* context)
    {
        // cout << "In visitType" << endl;
        string Type = context->getText();

        ASTType* node = new ASTType(Type);
        return (ASTType*) node;
    }

    virtual antlrcpp::Any visitVariable(ExprParser::VariableContext* context)
    {
        // cout << "In visitVariable method" << endl;
        ASTType* type = visit(context->type());
        vector<ASTDeclare*> variableList;
        for (auto declaration : context->declare()) {
            ASTDeclare* vis = visit(declaration);
            if (vis != nullptr) {
                variableList.push_back(vis);
            }
        }
        ASTVariableList* node = new ASTVariableList(type, variableList);
        return (ASTVariableList*)node;
    }

    // virtual antlrcpp::Any visitDeclareLocation(ExprParser::DeclareLocationContext* context)
    // {
    //     // cout << "In visitDeclareLocation method" << endl;
    //     string identifier = context->location()->getText();
    //     ASTDeclare* node = new ASTDeclare(identifier, "", nullptr);
    //     return (ASTDeclare*) node;
    // }

    virtual antlrcpp::Any visitDeclareId(ExprParser::DeclareIdContext *context)
    {
        string id = context->IDENTIFIER()->getText();
        ASTDeclare *node = new ASTDeclare(id,"",nullptr);
        return (ASTDeclare *) node;
    }
    virtual antlrcpp::Any visitDeclareId1D(ExprParser::DeclareId1DContext *context)
    {
        string id = context->IDENTIFIER()->getText();
        ASTExpr *expr = visit(context->expr());
        ASTDeclareArray *node = new ASTDeclareArray(id, expr);
        return (ASTDeclare *) node;
    }
    virtual antlrcpp::Any visitDeclareId2D(ExprParser::DeclareId2DContext *context)
    {
        string id = context->IDENTIFIER()->getText();
        ASTExpr *expr1 = visit(context->expr(0));
        ASTExpr *expr2 = visit(context->expr(1));
        ASTDeclareDoubleArray *node = new ASTDeclareDoubleArray(id, expr1, expr2);
        return (ASTDeclare *) node;
    }

    virtual antlrcpp::Any visitDeclareIdentifierAssign(ExprParser::DeclareIdentifierAssignContext* context)
    {
        // cout << "In visitDeclareIdentifierAssign" << endl;
        ASTDeclare* node = new ASTDeclare(context->IDENTIFIER()->getText(), context->ASSIGN_OP()->getText(), visit(context->expr()));
        return (ASTDeclare*)node;
    }

    virtual antlrcpp::Any visitLocationIdentifier(ExprParser::LocationIdentifierContext* context)
    {
        // cout << "In visitLocationIdentifier" << endl;
        ASTLocationIdentifier* node = new ASTLocationIdentifier(context->IDENTIFIER()->getText());
        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitLocationIdentifierArray(ExprParser::LocationIdentifierArrayContext* context)
    {
        // cout << "In visitLocationIdentifierArray" << endl;
        ASTLocationIdentifierArray* node = new ASTLocationIdentifierArray(context->IDENTIFIER()->getText(), visit(context->expr()));
        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitLocationIdentifierDoubleArray(ExprParser::LocationIdentifierDoubleArrayContext* context)
    {
        // cout << "In visitLocationIdentifierDoubleArray" << endl;
        ASTLocationIdentifierDoubleArray* node = new ASTLocationIdentifierDoubleArray(context->IDENTIFIER()->getText(), visit(context->expr(0)), visit(context->expr(1)));
        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitLiteralInt(ExprParser::LiteralIntContext* context)
    {
        // cout << "In visitLiteralInt" << endl;
        ASTLiteralInt* node = new ASTLiteralInt(stoi(context->INT()->getText()));

        return (ASTLiteral*)node;
    }

    virtual antlrcpp::Any visitLiteralFloat(ExprParser::LiteralFloatContext* context)
    {
        // cout << "In visitLiteralFloat" << endl;
        ASTLiteralFloat* node = new ASTLiteralFloat(stof(context->FLOAT()->getText()));

        return (ASTLiteral*)node;
    }

    virtual antlrcpp::Any visitLiteralString(ExprParser::LiteralStringContext* context)
    {
        // cout << "In visitLiteralString" << endl;
        ASTLiteralString* node = new ASTLiteralString(context->STRING()->getText());
        return (ASTLiteral*)node;
    }

    virtual antlrcpp::Any visitLiteralChar(ExprParser::LiteralCharContext* context)
    {
        // cout << "In visitLiteralChar" << endl;
        ASTLiteralChar* node = new ASTLiteralChar(context->CHAR()->getText()[1]);

        return (ASTLiteral*)node;
    }

    virtual antlrcpp::Any visitLiteralBool(ExprParser::LiteralBoolContext* context)
    {
        // cout << "In visitLiteralBool" << endl;
        string ret = context->BOOL->getText();
        bool param = false;
        if (ret == "true") {
            param = true;
        }
        ASTLiteralBool* node = new ASTLiteralBool(param);

        return (ASTLiteral*)node;
    }
};