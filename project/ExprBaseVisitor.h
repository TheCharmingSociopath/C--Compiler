
// Generated from Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDecl(ExprParser::MethodDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodArg(ExprParser::MethodArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodCall(ExprParser::MethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(ExprParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatIfElse(ExprParser::StatIfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatWhile(ExprParser::StatWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatTernary(ExprParser::StatTernaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatFor(ExprParser::StatForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatAssignExpr(ExprParser::StatAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementControl(ExprParser::StatementControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatVariable(ExprParser::StatVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatBlock(ExprParser::StatBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatMethodCall(ExprParser::StatMethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareLocation(ExprParser::DeclareLocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareIdentifierAssign(ExprParser::DeclareIdentifierAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlReturn(ExprParser::ControlReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlBreak(ExprParser::ControlBreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlContinue(ExprParser::ControlContinueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprRelationalOp(ExprParser::ExprRelationalOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAssignOp(ExprParser::ExprAssignOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprBoolOp(ExprParser::ExprBoolOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprIdentifier(ExprParser::ExprIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAddSubOp(ExprParser::ExprAddSubOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMethodCall(ExprParser::ExprMethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprConditionalOp(ExprParser::ExprConditionalOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprUnaryOp(ExprParser::ExprUnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMulDivModOp(ExprParser::ExprMulDivModOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprEqualityOp(ExprParser::ExprEqualityOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprLiteral(ExprParser::ExprLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocationIdentifier(ExprParser::LocationIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocationIdentifierArray(ExprParser::LocationIdentifierArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocationIdentifierDoubleArray(ExprParser::LocationIdentifierDoubleArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(ExprParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralInt(ExprParser::LiteralIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralFloat(ExprParser::LiteralFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralBool(ExprParser::LiteralBoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralChar(ExprParser::LiteralCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralString(ExprParser::LiteralStringContext *ctx) override {
    return visitChildren(ctx);
  }


};

