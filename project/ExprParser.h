
// Generated from Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  ExprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, IF = 18, ELSE = 19, WHILE = 20, 
    FOR = 21, RETURN = 22, BREAK = 23, CONTINUE = 24, MUL_OP = 25, DIV_OP = 26, 
    MOD_OP = 27, ADD_OP = 28, SUB_OP = 29, ASSIGN = 30, UNARY_OP = 31, EQUALITY_OP = 32, 
    RELATIONAL_OP = 33, ASSIGN_OP = 34, BOOL_OP = 35, CONDITIONAL_OP = 36, 
    INT = 37, IDENTIFIER = 38, FLOAT = 39, STRING = 40, CHAR = 41, BOOL = 42, 
    DOUBLE_QUOTE = 43, COMMENT = 44, WS = 45
  };

  enum {
    RuleProg = 0, RuleBlock = 1, RuleStatement = 2, RuleVariable = 3, RuleDeclare = 4, 
    RuleControl = 5, RuleExpr = 6, RuleLocation = 7, RuleType = 8, RuleLiteral = 9
  };

  ExprParser(antlr4::TokenStream *input);
  ~ExprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class BlockContext;
  class StatementContext;
  class VariableContext;
  class DeclareContext;
  class ControlContext;
  class ExprContext;
  class LocationContext;
  class TypeContext;
  class LiteralContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StatBlockContext : public StatementContext {
  public:
    StatBlockContext(StatementContext *ctx);

    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatWhileContext : public StatementContext {
  public:
    StatWhileContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    ExprContext *expr();
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatVariableContext : public StatementContext {
  public:
    StatVariableContext(StatementContext *ctx);

    VariableContext *variable();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatAssignExprContext : public StatementContext {
  public:
    StatAssignExprContext(StatementContext *ctx);

    LocationContext *location();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementControlContext : public StatementContext {
  public:
    StatementControlContext(StatementContext *ctx);

    ControlContext *control();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatForContext : public StatementContext {
  public:
    StatForContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatIfElseContext : public StatementContext {
  public:
    StatIfElseContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *IF();
    ExprContext *expr();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatTernaryContext : public StatementContext {
  public:
    StatTernaryContext(StatementContext *ctx);

    ExprContext *expr();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<DeclareContext *> declare();
    DeclareContext* declare(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  DeclareContext : public antlr4::ParserRuleContext {
  public:
    DeclareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclareContext() = default;
    void copyFrom(DeclareContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DeclareLocationContext : public DeclareContext {
  public:
    DeclareLocationContext(DeclareContext *ctx);

    LocationContext *location();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclareIdentifierAssignContext : public DeclareContext {
  public:
    DeclareIdentifierAssignContext(DeclareContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclareContext* declare();

  class  ControlContext : public antlr4::ParserRuleContext {
  public:
    ControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ControlContext() = default;
    void copyFrom(ControlContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ControlReturnContext : public ControlContext {
  public:
    ControlReturnContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ControlBreakContext : public ControlContext {
  public:
    ControlBreakContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *BREAK();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ControlContinueContext : public ControlContext {
  public:
    ControlContinueContext(ControlContext *ctx);

    antlr4::tree::TerminalNode *CONTINUE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ControlContext* control();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprRelationalOpContext : public ExprContext {
  public:
    ExprRelationalOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *RELATIONAL_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprAssignOpContext : public ExprContext {
  public:
    ExprAssignOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprBoolOpContext : public ExprContext {
  public:
    ExprBoolOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *BOOL_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprIdentifierContext : public ExprContext {
  public:
    ExprIdentifierContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprAddSubOpContext : public ExprContext {
  public:
    ExprAddSubOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ADD_OP();
    antlr4::tree::TerminalNode *SUB_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprConditionalOpContext : public ExprContext {
  public:
    ExprConditionalOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *CONDITIONAL_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprUnaryOpContext : public ExprContext {
  public:
    ExprUnaryOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    ExprContext *expr();
    antlr4::tree::TerminalNode *UNARY_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprParenthesisContext : public ExprContext {
  public:
    ExprParenthesisContext(ExprContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprMulDivModOpContext : public ExprContext {
  public:
    ExprMulDivModOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MUL_OP();
    antlr4::tree::TerminalNode *DIV_OP();
    antlr4::tree::TerminalNode *MOD_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprEqualityOpContext : public ExprContext {
  public:
    ExprEqualityOpContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *EQUALITY_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprLiteralContext : public ExprContext {
  public:
    ExprLiteralContext(ExprContext *ctx);

    LiteralContext *literal();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  LocationContext : public antlr4::ParserRuleContext {
  public:
    LocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LocationContext() = default;
    void copyFrom(LocationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LocationIdentifierArrayContext : public LocationContext {
  public:
    LocationIdentifierArrayContext(LocationContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LocationIdentifierDoubleArrayContext : public LocationContext {
  public:
    LocationIdentifierDoubleArrayContext(LocationContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LocationIdentifierContext : public LocationContext {
  public:
    LocationIdentifierContext(LocationContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LocationContext* location();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LiteralContext() = default;
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LiteralStringContext : public LiteralContext {
  public:
    LiteralStringContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralCharContext : public LiteralContext {
  public:
    LiteralCharContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *CHAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralBoolContext : public LiteralContext {
  public:
    LiteralBoolContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *BOOL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralIntContext : public LiteralContext {
  public:
    LiteralIntContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralFloatContext : public LiteralContext {
  public:
    LiteralFloatContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext* literal();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

