
// Generated from Expr.g4 by ANTLR 4.8


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ProgContext::EOF() {
  return getToken(ExprParser::EOF, 0);
}

std::vector<ExprParser::MethodDeclContext *> ExprParser::ProgContext::methodDecl() {
  return getRuleContexts<ExprParser::MethodDeclContext>();
}

ExprParser::MethodDeclContext* ExprParser::ProgContext::methodDecl(size_t i) {
  return getRuleContext<ExprParser::MethodDeclContext>(i);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}


antlrcpp::Any ExprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      methodDecl();
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__0)
      | (1ULL << ExprParser::T__13)
      | (1ULL << ExprParser::T__14)
      | (1ULL << ExprParser::T__15)
      | (1ULL << ExprParser::T__16)
      | (1ULL << ExprParser::T__17)
      | (1ULL << ExprParser::T__18))) != 0));
    setState(31);
    match(ExprParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclContext ------------------------------------------------------------------

ExprParser::MethodDeclContext::MethodDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::MethodDeclContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::BlockContext* ExprParser::MethodDeclContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::TypeContext* ExprParser::MethodDeclContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

std::vector<ExprParser::MethodArg1Context *> ExprParser::MethodDeclContext::methodArg1() {
  return getRuleContexts<ExprParser::MethodArg1Context>();
}

ExprParser::MethodArg1Context* ExprParser::MethodDeclContext::methodArg1(size_t i) {
  return getRuleContext<ExprParser::MethodArg1Context>(i);
}


size_t ExprParser::MethodDeclContext::getRuleIndex() const {
  return ExprParser::RuleMethodDecl;
}


antlrcpp::Any ExprParser::MethodDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMethodDecl(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::MethodDeclContext* ExprParser::methodDecl() {
  MethodDeclContext *_localctx = _tracker.createInstance<MethodDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleMethodDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__13:
      case ExprParser::T__14:
      case ExprParser::T__15:
      case ExprParser::T__16:
      case ExprParser::T__17:
      case ExprParser::T__18: {
        setState(33);
        type();
        break;
      }

      case ExprParser::T__0: {
        setState(34);
        match(ExprParser::T__0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(37);
    match(ExprParser::IDENTIFIER);
    setState(38);
    match(ExprParser::T__1);
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__13)
      | (1ULL << ExprParser::T__14)
      | (1ULL << ExprParser::T__15)
      | (1ULL << ExprParser::T__16)
      | (1ULL << ExprParser::T__17)
      | (1ULL << ExprParser::T__18))) != 0)) {
      setState(39);
      methodArg1();
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__2) {
        setState(40);
        match(ExprParser::T__2);
        setState(41);
        methodArg1();
        setState(46);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(49);
    match(ExprParser::T__3);
    setState(50);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodArg1Context ------------------------------------------------------------------

ExprParser::MethodArg1Context::MethodArg1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::MethodArg1Context::getRuleIndex() const {
  return ExprParser::RuleMethodArg1;
}

void ExprParser::MethodArg1Context::copyFrom(MethodArg1Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MethodArg2DContext ------------------------------------------------------------------

ExprParser::TypeContext* ExprParser::MethodArg2DContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

tree::TerminalNode* ExprParser::MethodArg2DContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::MethodArg2DContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::MethodArg2DContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::MethodArg2DContext::MethodArg2DContext(MethodArg1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::MethodArg2DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMethodArg2D(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodArgContext ------------------------------------------------------------------

ExprParser::TypeContext* ExprParser::MethodArgContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

tree::TerminalNode* ExprParser::MethodArgContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::MethodArgContext::MethodArgContext(MethodArg1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::MethodArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMethodArg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodArg1DContext ------------------------------------------------------------------

ExprParser::TypeContext* ExprParser::MethodArg1DContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

tree::TerminalNode* ExprParser::MethodArg1DContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::ExprContext* ExprParser::MethodArg1DContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::MethodArg1DContext::MethodArg1DContext(MethodArg1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::MethodArg1DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMethodArg1D(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::MethodArg1Context* ExprParser::methodArg1() {
  MethodArg1Context *_localctx = _tracker.createInstance<MethodArg1Context>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleMethodArg1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(70);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<MethodArg1Context *>(_tracker.createInstance<ExprParser::MethodArgContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(52);
      type();
      setState(53);
      match(ExprParser::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<MethodArg1Context *>(_tracker.createInstance<ExprParser::MethodArg1DContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(55);
      type();
      setState(56);
      match(ExprParser::IDENTIFIER);
      setState(57);
      match(ExprParser::T__4);
      setState(58);
      expr(0);
      setState(59);
      match(ExprParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<MethodArg1Context *>(_tracker.createInstance<ExprParser::MethodArg2DContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(61);
      type();
      setState(62);
      match(ExprParser::IDENTIFIER);
      setState(63);
      match(ExprParser::T__4);
      setState(64);
      expr(0);
      setState(65);
      match(ExprParser::T__5);
      setState(66);
      match(ExprParser::T__4);
      setState(67);
      expr(0);
      setState(68);
      match(ExprParser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodCallContext ------------------------------------------------------------------

ExprParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::MethodCallContext::STRING() {
  return getToken(ExprParser::STRING, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::MethodCallContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::MethodCallContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}


size_t ExprParser::MethodCallContext::getRuleIndex() const {
  return ExprParser::RuleMethodCall;
}


antlrcpp::Any ExprParser::MethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMethodCall(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::MethodCallContext* ExprParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleMethodCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(ExprParser::T__6);
    setState(73);
    match(ExprParser::T__1);
    setState(82);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::STRING) {
      setState(74);
      match(ExprParser::STRING);
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__2) {
        setState(75);
        match(ExprParser::T__2);
        setState(76);
        expr(0);
        setState(81);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(84);
    match(ExprParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ExprParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::StatementContext *> ExprParser::BlockContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::BlockContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}


size_t ExprParser::BlockContext::getRuleIndex() const {
  return ExprParser::RuleBlock;
}


antlrcpp::Any ExprParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::BlockContext* ExprParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(ExprParser::T__7);
    setState(88); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(87);
      statement();
      setState(90); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__1)
      | (1ULL << ExprParser::T__6)
      | (1ULL << ExprParser::T__7)
      | (1ULL << ExprParser::T__13)
      | (1ULL << ExprParser::T__14)
      | (1ULL << ExprParser::T__15)
      | (1ULL << ExprParser::T__16)
      | (1ULL << ExprParser::T__17)
      | (1ULL << ExprParser::T__18)
      | (1ULL << ExprParser::T__19)
      | (1ULL << ExprParser::T__20)
      | (1ULL << ExprParser::IF)
      | (1ULL << ExprParser::WHILE)
      | (1ULL << ExprParser::FOR)
      | (1ULL << ExprParser::RETURN)
      | (1ULL << ExprParser::BREAK)
      | (1ULL << ExprParser::CONTINUE)
      | (1ULL << ExprParser::UNARY_OP)
      | (1ULL << ExprParser::INT)
      | (1ULL << ExprParser::IDENTIFIER)
      | (1ULL << ExprParser::FLOAT)
      | (1ULL << ExprParser::STRING)
      | (1ULL << ExprParser::CHAR))) != 0));
    setState(92);
    match(ExprParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ExprParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::StatementContext::getRuleIndex() const {
  return ExprParser::RuleStatement;
}

void ExprParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatBlockContext ------------------------------------------------------------------

ExprParser::BlockContext* ExprParser::StatBlockContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::StatBlockContext::StatBlockContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatMethodCallContext ------------------------------------------------------------------

ExprParser::MethodCallContext* ExprParser::StatMethodCallContext::methodCall() {
  return getRuleContext<ExprParser::MethodCallContext>(0);
}

ExprParser::StatMethodCallContext::StatMethodCallContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatMethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatMethodCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatWhileContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::StatWhileContext::WHILE() {
  return getToken(ExprParser::WHILE, 0);
}

ExprParser::ExprContext* ExprParser::StatWhileContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::BlockContext* ExprParser::StatWhileContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::StatWhileContext::StatWhileContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatVariableContext ------------------------------------------------------------------

ExprParser::VariableContext* ExprParser::StatVariableContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

ExprParser::StatVariableContext::StatVariableContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatAssignExprContext ------------------------------------------------------------------

ExprParser::LocationContext* ExprParser::StatAssignExprContext::location() {
  return getRuleContext<ExprParser::LocationContext>(0);
}

tree::TerminalNode* ExprParser::StatAssignExprContext::ASSIGN() {
  return getToken(ExprParser::ASSIGN, 0);
}

ExprParser::ExprContext* ExprParser::StatAssignExprContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::StatAssignExprContext::StatAssignExprContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementControlContext ------------------------------------------------------------------

ExprParser::ControlContext* ExprParser::StatementControlContext::control() {
  return getRuleContext<ExprParser::ControlContext>(0);
}

ExprParser::StatementControlContext::StatementControlContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatementControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatementControl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatForContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::StatForContext::FOR() {
  return getToken(ExprParser::FOR, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::StatForContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::StatForContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::BlockContext* ExprParser::StatForContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::StatForContext::StatForContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatIfElseContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::StatIfElseContext::IF() {
  return getToken(ExprParser::IF, 0);
}

ExprParser::ExprContext* ExprParser::StatIfElseContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

std::vector<ExprParser::BlockContext *> ExprParser::StatIfElseContext::block() {
  return getRuleContexts<ExprParser::BlockContext>();
}

ExprParser::BlockContext* ExprParser::StatIfElseContext::block(size_t i) {
  return getRuleContext<ExprParser::BlockContext>(i);
}

tree::TerminalNode* ExprParser::StatIfElseContext::ELSE() {
  return getToken(ExprParser::ELSE, 0);
}

ExprParser::StatIfElseContext::StatIfElseContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatIfElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatIfElse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatTernaryContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::StatTernaryContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

std::vector<ExprParser::StatementContext *> ExprParser::StatTernaryContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::StatTernaryContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}

ExprParser::StatTernaryContext::StatTernaryContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatTernaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatTernary(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::StatementContext* ExprParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatIfElseContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(94);
      match(ExprParser::IF);
      setState(95);
      match(ExprParser::T__1);
      setState(96);
      expr(0);
      setState(97);
      match(ExprParser::T__3);
      setState(98);
      block();
      setState(101);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ExprParser::ELSE) {
        setState(99);
        match(ExprParser::ELSE);
        setState(100);
        block();
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatWhileContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(103);
      match(ExprParser::WHILE);
      setState(104);
      match(ExprParser::T__1);
      setState(105);
      expr(0);
      setState(106);
      match(ExprParser::T__3);
      setState(107);
      block();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatTernaryContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(109);
      expr(0);
      setState(110);
      match(ExprParser::T__9);
      setState(111);
      statement();
      setState(112);
      match(ExprParser::T__10);
      setState(113);
      statement();
      setState(114);
      match(ExprParser::T__11);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatForContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(116);
      match(ExprParser::FOR);
      setState(117);
      match(ExprParser::T__1);
      setState(118);
      expr(0);
      setState(119);
      match(ExprParser::T__11);
      setState(120);
      expr(0);
      setState(121);
      match(ExprParser::T__11);
      setState(122);
      expr(0);
      setState(123);
      match(ExprParser::T__3);
      setState(124);
      block();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatAssignExprContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(126);
      location();
      setState(127);
      match(ExprParser::ASSIGN);
      setState(128);
      expr(0);
      setState(129);
      match(ExprParser::T__11);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatementControlContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(131);
      control();
      setState(132);
      match(ExprParser::T__11);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatVariableContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(134);
      variable();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatBlockContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(135);
      block();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatMethodCallContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(136);
      methodCall();
      setState(137);
      match(ExprParser::T__11);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

ExprParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::TypeContext* ExprParser::VariableContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

std::vector<ExprParser::DeclareContext *> ExprParser::VariableContext::declare() {
  return getRuleContexts<ExprParser::DeclareContext>();
}

ExprParser::DeclareContext* ExprParser::VariableContext::declare(size_t i) {
  return getRuleContext<ExprParser::DeclareContext>(i);
}


size_t ExprParser::VariableContext::getRuleIndex() const {
  return ExprParser::RuleVariable;
}


antlrcpp::Any ExprParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariableContext* ExprParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    type();
    setState(142);
    declare();
    setState(147);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__2) {
      setState(143);
      match(ExprParser::T__2);
      setState(144);
      declare();
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(150);
    match(ExprParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareContext ------------------------------------------------------------------

ExprParser::DeclareContext::DeclareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::DeclareContext::getRuleIndex() const {
  return ExprParser::RuleDeclare;
}

void ExprParser::DeclareContext::copyFrom(DeclareContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclareId1DContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::DeclareId1DContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::ExprContext* ExprParser::DeclareId1DContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::DeclareId1DContext::DeclareId1DContext(DeclareContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DeclareId1DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDeclareId1D(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclareIdContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::DeclareIdContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::DeclareIdContext::DeclareIdContext(DeclareContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DeclareIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDeclareId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclareIdentifierAssignContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::DeclareIdentifierAssignContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExprParser::DeclareIdentifierAssignContext::ASSIGN() {
  return getToken(ExprParser::ASSIGN, 0);
}

ExprParser::ExprContext* ExprParser::DeclareIdentifierAssignContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::DeclareIdentifierAssignContext::DeclareIdentifierAssignContext(DeclareContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DeclareIdentifierAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDeclareIdentifierAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclareId2DContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::DeclareId2DContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::DeclareId2DContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::DeclareId2DContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::DeclareId2DContext::DeclareId2DContext(DeclareContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DeclareId2DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDeclareId2D(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::DeclareContext* ExprParser::declare() {
  DeclareContext *_localctx = _tracker.createInstance<DeclareContext>(_ctx, getState());
  enterRule(_localctx, 14, ExprParser::RuleDeclare);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclareContext *>(_tracker.createInstance<ExprParser::DeclareIdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(152);
      match(ExprParser::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclareContext *>(_tracker.createInstance<ExprParser::DeclareId1DContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(153);
      match(ExprParser::IDENTIFIER);
      setState(154);
      match(ExprParser::T__4);
      setState(155);
      expr(0);
      setState(156);
      match(ExprParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<DeclareContext *>(_tracker.createInstance<ExprParser::DeclareId2DContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(158);
      match(ExprParser::IDENTIFIER);
      setState(159);
      match(ExprParser::T__4);
      setState(160);
      expr(0);
      setState(161);
      match(ExprParser::T__12);
      setState(162);
      expr(0);
      setState(163);
      match(ExprParser::T__5);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<DeclareContext *>(_tracker.createInstance<ExprParser::DeclareIdentifierAssignContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(165);
      match(ExprParser::IDENTIFIER);
      setState(166);
      match(ExprParser::ASSIGN);
      setState(167);
      expr(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlContext ------------------------------------------------------------------

ExprParser::ControlContext::ControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ControlContext::getRuleIndex() const {
  return ExprParser::RuleControl;
}

void ExprParser::ControlContext::copyFrom(ControlContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ControlReturnContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ControlReturnContext::RETURN() {
  return getToken(ExprParser::RETURN, 0);
}

ExprParser::ExprContext* ExprParser::ControlReturnContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ControlReturnContext::ControlReturnContext(ControlContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ControlReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitControlReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ControlBreakContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ControlBreakContext::BREAK() {
  return getToken(ExprParser::BREAK, 0);
}

ExprParser::ControlBreakContext::ControlBreakContext(ControlContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ControlBreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitControlBreak(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ControlContinueContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ControlContinueContext::CONTINUE() {
  return getToken(ExprParser::CONTINUE, 0);
}

ExprParser::ControlContinueContext::ControlContinueContext(ControlContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ControlContinueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitControlContinue(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::ControlContext* ExprParser::control() {
  ControlContext *_localctx = _tracker.createInstance<ControlContext>(_ctx, getState());
  enterRule(_localctx, 16, ExprParser::RuleControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(176);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::RETURN: {
        _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<ExprParser::ControlReturnContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(170);
        match(ExprParser::RETURN);
        setState(172);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ExprParser::T__1)
          | (1ULL << ExprParser::T__6)
          | (1ULL << ExprParser::T__19)
          | (1ULL << ExprParser::T__20)
          | (1ULL << ExprParser::UNARY_OP)
          | (1ULL << ExprParser::INT)
          | (1ULL << ExprParser::IDENTIFIER)
          | (1ULL << ExprParser::FLOAT)
          | (1ULL << ExprParser::STRING)
          | (1ULL << ExprParser::CHAR))) != 0)) {
          setState(171);
          expr(0);
        }
        break;
      }

      case ExprParser::BREAK: {
        _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<ExprParser::ControlBreakContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(174);
        match(ExprParser::BREAK);
        break;
      }

      case ExprParser::CONTINUE: {
        _localctx = dynamic_cast<ControlContext *>(_tracker.createInstance<ExprParser::ControlContinueContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(175);
        match(ExprParser::CONTINUE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprRelationalOpContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprRelationalOpContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprRelationalOpContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprRelationalOpContext::RELATIONAL_OP() {
  return getToken(ExprParser::RELATIONAL_OP, 0);
}

ExprParser::ExprRelationalOpContext::ExprRelationalOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprRelationalOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprRelationalOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLocationContext ------------------------------------------------------------------

ExprParser::LocationContext* ExprParser::ExprLocationContext::location() {
  return getRuleContext<ExprParser::LocationContext>(0);
}

ExprParser::ExprLocationContext::ExprLocationContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprLocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprLocation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAssignOpContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprAssignOpContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprAssignOpContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprAssignOpContext::ASSIGN() {
  return getToken(ExprParser::ASSIGN, 0);
}

ExprParser::ExprAssignOpContext::ExprAssignOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprAssignOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprAssignOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBoolOpContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprBoolOpContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprBoolOpContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprBoolOpContext::BOOL_OP() {
  return getToken(ExprParser::BOOL_OP, 0);
}

ExprParser::ExprBoolOpContext::ExprBoolOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprBoolOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprBoolOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubOpContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprAddSubOpContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprAddSubOpContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprAddSubOpContext::ADD_OP() {
  return getToken(ExprParser::ADD_OP, 0);
}

tree::TerminalNode* ExprParser::ExprAddSubOpContext::SUB_OP() {
  return getToken(ExprParser::SUB_OP, 0);
}

ExprParser::ExprAddSubOpContext::ExprAddSubOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprAddSubOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprAddSubOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMethodCallContext ------------------------------------------------------------------

ExprParser::MethodCallContext* ExprParser::ExprMethodCallContext::methodCall() {
  return getRuleContext<ExprParser::MethodCallContext>(0);
}

ExprParser::ExprMethodCallContext::ExprMethodCallContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprMethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprMethodCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprConditionalOpContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprConditionalOpContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprConditionalOpContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprConditionalOpContext::CONDITIONAL_OP() {
  return getToken(ExprParser::CONDITIONAL_OP, 0);
}

ExprParser::ExprConditionalOpContext::ExprConditionalOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprConditionalOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprConditionalOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprUnaryOpContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ExprUnaryOpContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

tree::TerminalNode* ExprParser::ExprUnaryOpContext::UNARY_OP() {
  return getToken(ExprParser::UNARY_OP, 0);
}

ExprParser::ExprUnaryOpContext::ExprUnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprUnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprUnaryOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenthesisContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ExprParenthesisContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ExprParenthesisContext::ExprParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMulDivModOpContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprMulDivModOpContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprMulDivModOpContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprMulDivModOpContext::MUL_OP() {
  return getToken(ExprParser::MUL_OP, 0);
}

tree::TerminalNode* ExprParser::ExprMulDivModOpContext::DIV_OP() {
  return getToken(ExprParser::DIV_OP, 0);
}

tree::TerminalNode* ExprParser::ExprMulDivModOpContext::MOD_OP() {
  return getToken(ExprParser::MOD_OP, 0);
}

ExprParser::ExprMulDivModOpContext::ExprMulDivModOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprMulDivModOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprMulDivModOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprEqualityOpContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprEqualityOpContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprEqualityOpContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

tree::TerminalNode* ExprParser::ExprEqualityOpContext::EQUALITY_OP() {
  return getToken(ExprParser::EQUALITY_OP, 0);
}

ExprParser::ExprEqualityOpContext::ExprEqualityOpContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprEqualityOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprEqualityOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLiteralContext ------------------------------------------------------------------

ExprParser::LiteralContext* ExprParser::ExprLiteralContext::literal() {
  return getRuleContext<ExprParser::LiteralContext>(0);
}

ExprParser::ExprLiteralContext::ExprLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprLiteral(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, ExprParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<ExprLocationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(179);
        location();
        break;
      }

      case ExprParser::T__19:
      case ExprParser::T__20:
      case ExprParser::INT:
      case ExprParser::FLOAT:
      case ExprParser::STRING:
      case ExprParser::CHAR: {
        _localctx = _tracker.createInstance<ExprLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(180);
        literal();
        break;
      }

      case ExprParser::T__6: {
        _localctx = _tracker.createInstance<ExprMethodCallContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(181);
        methodCall();
        break;
      }

      case ExprParser::T__1: {
        _localctx = _tracker.createInstance<ExprParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(182);
        match(ExprParser::T__1);
        setState(183);
        expr(0);
        setState(184);
        match(ExprParser::T__3);
        break;
      }

      case ExprParser::UNARY_OP: {
        _localctx = _tracker.createInstance<ExprUnaryOpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(186);
        dynamic_cast<ExprUnaryOpContext *>(_localctx)->op = match(ExprParser::UNARY_OP);
        setState(187);
        expr(1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(213);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(211);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMulDivModOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(190);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(191);
          dynamic_cast<ExprMulDivModOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ExprParser::MUL_OP)
            | (1ULL << ExprParser::DIV_OP)
            | (1ULL << ExprParser::MOD_OP))) != 0))) {
            dynamic_cast<ExprMulDivModOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(192);
          expr(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddSubOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(193);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(194);
          dynamic_cast<ExprAddSubOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::ADD_OP

          || _la == ExprParser::SUB_OP)) {
            dynamic_cast<ExprAddSubOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(195);
          expr(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprRelationalOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(196);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(197);
          dynamic_cast<ExprRelationalOpContext *>(_localctx)->op = match(ExprParser::RELATIONAL_OP);
          setState(198);
          expr(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprEqualityOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(199);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(200);
          dynamic_cast<ExprEqualityOpContext *>(_localctx)->op = match(ExprParser::EQUALITY_OP);
          setState(201);
          expr(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprBoolOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(203);
          dynamic_cast<ExprBoolOpContext *>(_localctx)->op = match(ExprParser::BOOL_OP);
          setState(204);
          expr(5);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprConditionalOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(205);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(206);
          dynamic_cast<ExprConditionalOpContext *>(_localctx)->op = match(ExprParser::CONDITIONAL_OP);
          setState(207);
          expr(4);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprAssignOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(208);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(209);
          dynamic_cast<ExprAssignOpContext *>(_localctx)->op = match(ExprParser::ASSIGN);
          setState(210);
          expr(3);
          break;
        }

        } 
      }
      setState(215);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LocationContext ------------------------------------------------------------------

ExprParser::LocationContext::LocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::LocationContext::getRuleIndex() const {
  return ExprParser::RuleLocation;
}

void ExprParser::LocationContext::copyFrom(LocationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LocationIdentifierArrayContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LocationIdentifierArrayContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::ExprContext* ExprParser::LocationIdentifierArrayContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::LocationIdentifierArrayContext::LocationIdentifierArrayContext(LocationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LocationIdentifierArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLocationIdentifierArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LocationIdentifierDoubleArrayContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LocationIdentifierDoubleArrayContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::LocationIdentifierDoubleArrayContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::LocationIdentifierDoubleArrayContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::LocationIdentifierDoubleArrayContext::LocationIdentifierDoubleArrayContext(LocationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LocationIdentifierDoubleArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLocationIdentifierDoubleArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LocationIdentifierContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LocationIdentifierContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::LocationIdentifierContext::LocationIdentifierContext(LocationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LocationIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLocationIdentifier(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::LocationContext* ExprParser::location() {
  LocationContext *_localctx = _tracker.createInstance<LocationContext>(_ctx, getState());
  enterRule(_localctx, 20, ExprParser::RuleLocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<ExprParser::LocationIdentifierContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(216);
      match(ExprParser::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<ExprParser::LocationIdentifierArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(217);
      match(ExprParser::IDENTIFIER);
      setState(218);
      match(ExprParser::T__4);
      setState(219);
      expr(0);
      setState(220);
      match(ExprParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<ExprParser::LocationIdentifierDoubleArrayContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(222);
      match(ExprParser::IDENTIFIER);
      setState(223);
      match(ExprParser::T__4);
      setState(224);
      expr(0);
      setState(225);
      match(ExprParser::T__12);
      setState(226);
      expr(0);
      setState(227);
      match(ExprParser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

ExprParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::TypeContext::getRuleIndex() const {
  return ExprParser::RuleType;
}


antlrcpp::Any ExprParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TypeContext* ExprParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 22, ExprParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__13)
      | (1ULL << ExprParser::T__14)
      | (1ULL << ExprParser::T__15)
      | (1ULL << ExprParser::T__16)
      | (1ULL << ExprParser::T__17)
      | (1ULL << ExprParser::T__18))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

ExprParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::LiteralContext::getRuleIndex() const {
  return ExprParser::RuleLiteral;
}

void ExprParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LiteralStringContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LiteralStringContext::STRING() {
  return getToken(ExprParser::STRING, 0);
}

ExprParser::LiteralStringContext::LiteralStringContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LiteralStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLiteralString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralCharContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LiteralCharContext::CHAR() {
  return getToken(ExprParser::CHAR, 0);
}

ExprParser::LiteralCharContext::LiteralCharContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LiteralCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLiteralChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralBoolContext ------------------------------------------------------------------

ExprParser::LiteralBoolContext::LiteralBoolContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LiteralBoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLiteralBool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralIntContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LiteralIntContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::LiteralIntContext::LiteralIntContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LiteralIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLiteralInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralFloatContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LiteralFloatContext::FLOAT() {
  return getToken(ExprParser::FLOAT, 0);
}

ExprParser::LiteralFloatContext::LiteralFloatContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LiteralFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLiteralFloat(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::LiteralContext* ExprParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 24, ExprParser::RuleLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(238);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::INT: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<ExprParser::LiteralIntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(233);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::FLOAT: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<ExprParser::LiteralFloatContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(234);
        match(ExprParser::FLOAT);
        break;
      }

      case ExprParser::T__19:
      case ExprParser::T__20: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<ExprParser::LiteralBoolContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(235);
        dynamic_cast<LiteralBoolContext *>(_localctx)->BOOL = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == ExprParser::T__19

        || _la == ExprParser::T__20)) {
          dynamic_cast<LiteralBoolContext *>(_localctx)->BOOL = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case ExprParser::CHAR: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<ExprParser::LiteralCharContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(236);
        match(ExprParser::CHAR);
        break;
      }

      case ExprParser::STRING: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<ExprParser::LiteralStringContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(237);
        match(ExprParser::STRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "prog", "methodDecl", "methodArg1", "methodCall", "block", "statement", 
  "variable", "declare", "control", "expr", "location", "type", "literal"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'void'", "'('", "','", "')'", "'['", "']'", "'callout'", "'{'", "'}'", 
  "'?'", "':'", "';'", "']['", "'int'", "'bool'", "'float'", "'char'", "'string'", 
  "'uint'", "'true'", "'false'", "'if'", "'else'", "'while'", "'for'", "'return'", 
  "'break'", "'continue'", "'*'", "'/'", "'%'", "'+'", "'-'", "'='", "", 
  "", "", "", "", "", "", "", "", "", "", "'\"'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE", 
  "MUL_OP", "DIV_OP", "MOD_OP", "ADD_OP", "SUB_OP", "ASSIGN", "UNARY_OP", 
  "EQUALITY_OP", "RELATIONAL_OP", "ASSIGN_OP", "BOOL_OP", "CONDITIONAL_OP", 
  "INT", "IDENTIFIER", "FLOAT", "STRING", "CHAR", "DOUBLE_QUOTE", "COMMENT", 
  "WS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x32, 0xf3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x6, 0x2, 0x1e, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1f, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x26, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2d, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x30, 0xb, 0x3, 0x5, 0x3, 0x32, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x49, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x50, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0x53, 0xb, 0x5, 0x5, 0x5, 0x55, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x5b, 0xa, 0x6, 0xd, 0x6, 
    0xe, 0x6, 0x5c, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x68, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x8e, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 
    0x8, 0x94, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x97, 0xb, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xab, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0xaf, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xb3, 0xa, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xbf, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xd6, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xd9, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xe8, 0xa, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0xf1, 0xa, 0xe, 0x3, 0xe, 0x2, 0x3, 0x14, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0x6, 0x3, 0x2, 0x1f, 
    0x21, 0x3, 0x2, 0x22, 0x23, 0x3, 0x2, 0x10, 0x15, 0x3, 0x2, 0x16, 0x17, 
    0x2, 0x10f, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x48, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4a, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x12, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x16, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xf0, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 
    0x7, 0x2, 0x2, 0x3, 0x22, 0x3, 0x3, 0x2, 0x2, 0x2, 0x23, 0x26, 0x5, 
    0x18, 0xd, 0x2, 0x24, 0x26, 0x7, 0x3, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x28, 0x7, 0x2c, 0x2, 0x2, 0x28, 0x31, 0x7, 0x4, 0x2, 0x2, 
    0x29, 0x2e, 0x5, 0x6, 0x4, 0x2, 0x2a, 0x2b, 0x7, 0x5, 0x2, 0x2, 0x2b, 
    0x2d, 0x5, 0x6, 0x4, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x29, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x6, 0x2, 0x2, 
    0x34, 0x35, 0x5, 0xa, 0x6, 0x2, 0x35, 0x5, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x37, 0x5, 0x18, 0xd, 0x2, 0x37, 0x38, 0x7, 0x2c, 0x2, 0x2, 0x38, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x18, 0xd, 0x2, 0x3a, 0x3b, 0x7, 
    0x2c, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x7, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x14, 
    0xb, 0x2, 0x3d, 0x3e, 0x7, 0x8, 0x2, 0x2, 0x3e, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x5, 0x18, 0xd, 0x2, 0x40, 0x41, 0x7, 0x2c, 0x2, 0x2, 
    0x41, 0x42, 0x7, 0x7, 0x2, 0x2, 0x42, 0x43, 0x5, 0x14, 0xb, 0x2, 0x43, 
    0x44, 0x7, 0x8, 0x2, 0x2, 0x44, 0x45, 0x7, 0x7, 0x2, 0x2, 0x45, 0x46, 
    0x5, 0x14, 0xb, 0x2, 0x46, 0x47, 0x7, 0x8, 0x2, 0x2, 0x47, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x36, 0x3, 0x2, 0x2, 0x2, 0x48, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x49, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x4b, 0x7, 0x9, 0x2, 0x2, 0x4b, 0x54, 0x7, 0x4, 0x2, 0x2, 
    0x4c, 0x51, 0x7, 0x2e, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x5, 0x2, 0x2, 0x4e, 
    0x50, 0x5, 0x14, 0xb, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x55, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0x6, 0x2, 0x2, 
    0x57, 0x9, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x7, 0xa, 0x2, 0x2, 0x59, 
    0x5b, 0x5, 0xc, 0x7, 0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0xb, 
    0x2, 0x2, 0x5f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x18, 0x2, 
    0x2, 0x61, 0x62, 0x7, 0x4, 0x2, 0x2, 0x62, 0x63, 0x5, 0x14, 0xb, 0x2, 
    0x63, 0x64, 0x7, 0x6, 0x2, 0x2, 0x64, 0x67, 0x5, 0xa, 0x6, 0x2, 0x65, 
    0x66, 0x7, 0x19, 0x2, 0x2, 0x66, 0x68, 0x5, 0xa, 0x6, 0x2, 0x67, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x1a, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x4, 
    0x2, 0x2, 0x6b, 0x6c, 0x5, 0x14, 0xb, 0x2, 0x6c, 0x6d, 0x7, 0x6, 0x2, 
    0x2, 0x6d, 0x6e, 0x5, 0xa, 0x6, 0x2, 0x6e, 0x8e, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x70, 0x5, 0x14, 0xb, 0x2, 0x70, 0x71, 0x7, 0xc, 0x2, 0x2, 0x71, 
    0x72, 0x5, 0xc, 0x7, 0x2, 0x72, 0x73, 0x7, 0xd, 0x2, 0x2, 0x73, 0x74, 
    0x5, 0xc, 0x7, 0x2, 0x74, 0x75, 0x7, 0xe, 0x2, 0x2, 0x75, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x1b, 0x2, 0x2, 0x77, 0x78, 0x7, 0x4, 
    0x2, 0x2, 0x78, 0x79, 0x5, 0x14, 0xb, 0x2, 0x79, 0x7a, 0x7, 0xe, 0x2, 
    0x2, 0x7a, 0x7b, 0x5, 0x14, 0xb, 0x2, 0x7b, 0x7c, 0x7, 0xe, 0x2, 0x2, 
    0x7c, 0x7d, 0x5, 0x14, 0xb, 0x2, 0x7d, 0x7e, 0x7, 0x6, 0x2, 0x2, 0x7e, 
    0x7f, 0x5, 0xa, 0x6, 0x2, 0x7f, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 
    0x5, 0x16, 0xc, 0x2, 0x81, 0x82, 0x7, 0x24, 0x2, 0x2, 0x82, 0x83, 0x5, 
    0x14, 0xb, 0x2, 0x83, 0x84, 0x7, 0xe, 0x2, 0x2, 0x84, 0x8e, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x86, 0x5, 0x12, 0xa, 0x2, 0x86, 0x87, 0x7, 0xe, 0x2, 
    0x2, 0x87, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8e, 0x5, 0xe, 0x8, 0x2, 
    0x89, 0x8e, 0x5, 0xa, 0x6, 0x2, 0x8a, 0x8b, 0x5, 0x8, 0x5, 0x2, 0x8b, 
    0x8c, 0x7, 0xe, 0x2, 0x2, 0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x69, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x76, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x18, 0xd, 0x2, 0x90, 
    0x95, 0x5, 0x10, 0x9, 0x2, 0x91, 0x92, 0x7, 0x5, 0x2, 0x2, 0x92, 0x94, 
    0x5, 0x10, 0x9, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x98, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x99, 0x7, 0xe, 0x2, 0x2, 0x99, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0xab, 0x7, 0x2c, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x2c, 0x2, 0x2, 0x9c, 
    0x9d, 0x7, 0x7, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x14, 0xb, 0x2, 0x9e, 0x9f, 
    0x7, 0x8, 0x2, 0x2, 0x9f, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 
    0x2c, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x7, 0x2, 0x2, 0xa2, 0xa3, 0x5, 0x14, 
    0xb, 0x2, 0xa3, 0xa4, 0x7, 0xf, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x14, 0xb, 
    0x2, 0xa5, 0xa6, 0x7, 0x8, 0x2, 0x2, 0xa6, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0xa8, 0x7, 0x2c, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x24, 0x2, 0x2, 0xa9, 
    0xab, 0x5, 0x14, 0xb, 0x2, 0xaa, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xab, 0x11, 0x3, 0x2, 0x2, 0x2, 0xac, 0xae, 0x7, 0x1c, 
    0x2, 0x2, 0xad, 0xaf, 0x5, 0x14, 0xb, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xb3, 0x7, 0x1d, 0x2, 0x2, 0xb1, 0xb3, 0x7, 0x1e, 0x2, 0x2, 0xb2, 
    0xac, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x8, 
    0xb, 0x1, 0x2, 0xb5, 0xbf, 0x5, 0x16, 0xc, 0x2, 0xb6, 0xbf, 0x5, 0x1a, 
    0xe, 0x2, 0xb7, 0xbf, 0x5, 0x8, 0x5, 0x2, 0xb8, 0xb9, 0x7, 0x4, 0x2, 
    0x2, 0xb9, 0xba, 0x5, 0x14, 0xb, 0x2, 0xba, 0xbb, 0x7, 0x6, 0x2, 0x2, 
    0xbb, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x25, 0x2, 0x2, 0xbd, 
    0xbf, 0x5, 0x14, 0xb, 0x3, 0xbe, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xd7, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc1, 0xc, 0xa, 0x2, 0x2, 0xc1, 0xc2, 0x9, 0x2, 0x2, 
    0x2, 0xc2, 0xd6, 0x5, 0x14, 0xb, 0xb, 0xc3, 0xc4, 0xc, 0x9, 0x2, 0x2, 
    0xc4, 0xc5, 0x9, 0x3, 0x2, 0x2, 0xc5, 0xd6, 0x5, 0x14, 0xb, 0xa, 0xc6, 
    0xc7, 0xc, 0x8, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x27, 0x2, 0x2, 0xc8, 0xd6, 
    0x5, 0x14, 0xb, 0x9, 0xc9, 0xca, 0xc, 0x7, 0x2, 0x2, 0xca, 0xcb, 0x7, 
    0x26, 0x2, 0x2, 0xcb, 0xd6, 0x5, 0x14, 0xb, 0x8, 0xcc, 0xcd, 0xc, 0x6, 
    0x2, 0x2, 0xcd, 0xce, 0x7, 0x29, 0x2, 0x2, 0xce, 0xd6, 0x5, 0x14, 0xb, 
    0x7, 0xcf, 0xd0, 0xc, 0x5, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x2a, 0x2, 0x2, 
    0xd1, 0xd6, 0x5, 0x14, 0xb, 0x6, 0xd2, 0xd3, 0xc, 0x4, 0x2, 0x2, 0xd3, 
    0xd4, 0x7, 0x24, 0x2, 0x2, 0xd4, 0xd6, 0x5, 0x14, 0xb, 0x5, 0xd5, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xcc, 0x3, 0x2, 
    0x2, 0x2, 0xd5, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xe8, 0x7, 0x2c, 0x2, 0x2, 0xdb, 0xdc, 
    0x7, 0x2c, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x7, 0x2, 0x2, 0xdd, 0xde, 0x5, 
    0x14, 0xb, 0x2, 0xde, 0xdf, 0x7, 0x8, 0x2, 0x2, 0xdf, 0xe8, 0x3, 0x2, 
    0x2, 0x2, 0xe0, 0xe1, 0x7, 0x2c, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x7, 0x2, 
    0x2, 0xe2, 0xe3, 0x5, 0x14, 0xb, 0x2, 0xe3, 0xe4, 0x7, 0xf, 0x2, 0x2, 
    0xe4, 0xe5, 0x5, 0x14, 0xb, 0x2, 0xe5, 0xe6, 0x7, 0x8, 0x2, 0x2, 0xe6, 
    0xe8, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xea, 0x9, 0x4, 0x2, 0x2, 0xea, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0xeb, 0xf1, 0x7, 0x2b, 0x2, 0x2, 0xec, 0xf1, 0x7, 0x2d, 0x2, 
    0x2, 0xed, 0xf1, 0x9, 0x5, 0x2, 0x2, 0xee, 0xf1, 0x7, 0x2f, 0x2, 0x2, 
    0xef, 0xf1, 0x7, 0x2e, 0x2, 0x2, 0xf0, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xec, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x15, 0x1f, 0x25, 0x2e, 0x31, 0x48, 0x51, 0x54, 0x5c, 
    0x67, 0x8d, 0x95, 0xaa, 0xae, 0xb2, 0xbe, 0xd5, 0xd7, 0xe7, 0xf0, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
