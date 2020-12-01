
// Generated from Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitMethodDecl(ExprParser::MethodDeclContext *context) = 0;

    virtual antlrcpp::Any visitMethodArg(ExprParser::MethodArgContext *context) = 0;

    virtual antlrcpp::Any visitMethodArg1D(ExprParser::MethodArg1DContext *context) = 0;

    virtual antlrcpp::Any visitMethodArg2D(ExprParser::MethodArg2DContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall(ExprParser::MethodCallContext *context) = 0;

    virtual antlrcpp::Any visitBlock(ExprParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatIfElse(ExprParser::StatIfElseContext *context) = 0;

    virtual antlrcpp::Any visitStatWhile(ExprParser::StatWhileContext *context) = 0;

    virtual antlrcpp::Any visitStatTernary(ExprParser::StatTernaryContext *context) = 0;

    virtual antlrcpp::Any visitStatFor(ExprParser::StatForContext *context) = 0;

    virtual antlrcpp::Any visitStatAssignExpr(ExprParser::StatAssignExprContext *context) = 0;

    virtual antlrcpp::Any visitStatementControl(ExprParser::StatementControlContext *context) = 0;

    virtual antlrcpp::Any visitStatVariable(ExprParser::StatVariableContext *context) = 0;

    virtual antlrcpp::Any visitStatBlock(ExprParser::StatBlockContext *context) = 0;

    virtual antlrcpp::Any visitStatMethodCall(ExprParser::StatMethodCallContext *context) = 0;

    virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitDeclareId(ExprParser::DeclareIdContext *context) = 0;

    virtual antlrcpp::Any visitDeclareIdentifierAssign(ExprParser::DeclareIdentifierAssignContext *context) = 0;

    virtual antlrcpp::Any visitDeclareId1D(ExprParser::DeclareId1DContext *context) = 0;

    virtual antlrcpp::Any visitDeclareId2D(ExprParser::DeclareId2DContext *context) = 0;

    virtual antlrcpp::Any visitControlReturn(ExprParser::ControlReturnContext *context) = 0;

    virtual antlrcpp::Any visitControlBreak(ExprParser::ControlBreakContext *context) = 0;

    virtual antlrcpp::Any visitControlContinue(ExprParser::ControlContinueContext *context) = 0;

    virtual antlrcpp::Any visitExprRelationalOp(ExprParser::ExprRelationalOpContext *context) = 0;

    virtual antlrcpp::Any visitExprLocation(ExprParser::ExprLocationContext *context) = 0;

    virtual antlrcpp::Any visitExprAssignOp(ExprParser::ExprAssignOpContext *context) = 0;

    virtual antlrcpp::Any visitExprBoolOp(ExprParser::ExprBoolOpContext *context) = 0;

    virtual antlrcpp::Any visitExprAddSubOp(ExprParser::ExprAddSubOpContext *context) = 0;

    virtual antlrcpp::Any visitExprMethodCall(ExprParser::ExprMethodCallContext *context) = 0;

    virtual antlrcpp::Any visitExprConditionalOp(ExprParser::ExprConditionalOpContext *context) = 0;

    virtual antlrcpp::Any visitExprUnaryOp(ExprParser::ExprUnaryOpContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitExprMulDivModOp(ExprParser::ExprMulDivModOpContext *context) = 0;

    virtual antlrcpp::Any visitExprEqualityOp(ExprParser::ExprEqualityOpContext *context) = 0;

    virtual antlrcpp::Any visitExprLiteral(ExprParser::ExprLiteralContext *context) = 0;

    virtual antlrcpp::Any visitLocationIdentifier(ExprParser::LocationIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitLocationIdentifierArray(ExprParser::LocationIdentifierArrayContext *context) = 0;

    virtual antlrcpp::Any visitLocationIdentifierDoubleArray(ExprParser::LocationIdentifierDoubleArrayContext *context) = 0;

    virtual antlrcpp::Any visitType(ExprParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitLiteralInt(ExprParser::LiteralIntContext *context) = 0;

    virtual antlrcpp::Any visitLiteralFloat(ExprParser::LiteralFloatContext *context) = 0;

    virtual antlrcpp::Any visitLiteralBool(ExprParser::LiteralBoolContext *context) = 0;

    virtual antlrcpp::Any visitLiteralChar(ExprParser::LiteralCharContext *context) = 0;

    virtual antlrcpp::Any visitLiteralString(ExprParser::LiteralStringContext *context) = 0;


};

