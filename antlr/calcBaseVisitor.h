
// Generated from calc.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "calcVisitor.h"


/**
 * This class provides an empty implementation of calcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  calcBaseVisitor : public calcVisitor {
public:

  virtual antlrcpp::Any visitProg(calcParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAditya(calcParser::AdityaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatAssignExpr(calcParser::StatAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatNewLine(calcParser::StatNewLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprINT(calcParser::ExprINTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAddSub(calcParser::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprID(calcParser::ExprIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParenthesis(calcParser::ExprParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMulDiv(calcParser::ExprMulDivContext *ctx) override {
    return visitChildren(ctx);
  }


};

