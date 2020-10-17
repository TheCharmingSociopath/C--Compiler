
// Generated from calc.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "calcParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by calcParser.
 */
class  calcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by calcParser.
   */
    virtual antlrcpp::Any visitProg(calcParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitAditya(calcParser::AdityaContext *context) = 0;

    virtual antlrcpp::Any visitStatAssignExpr(calcParser::StatAssignExprContext *context) = 0;

    virtual antlrcpp::Any visitStatNewLine(calcParser::StatNewLineContext *context) = 0;

    virtual antlrcpp::Any visitExprINT(calcParser::ExprINTContext *context) = 0;

    virtual antlrcpp::Any visitExprAddSub(calcParser::ExprAddSubContext *context) = 0;

    virtual antlrcpp::Any visitExprID(calcParser::ExprIDContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(calcParser::ExprParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitExprMulDiv(calcParser::ExprMulDivContext *context) = 0;


};

