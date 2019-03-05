
// Generated from Asl.g4 by ANTLR 4.7.1


#include "AslListener.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

void AslParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AslParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(22);
      function();
      setState(25); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(27);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

std::vector<AslParser::Variable_declContext *> AslParser::FunctionContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::FunctionContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

void AslParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void AslParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(AslParser::FUNC);
    setState(30);
    match(AslParser::ID);
    setState(31);
    match(AslParser::T__0);

    setState(37);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(32);
        variable_decl();
        setState(33);
        match(AslParser::T__1); 
      }
      setState(39);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(40);
    variable_decl();
    setState(42);
    match(AslParser::T__2);
    setState(43);
    declarations();
    setState(44);
    statements();
    setState(45);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

void AslParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void AslParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(47);
      variable_decl();
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

tree::TerminalNode* AslParser::Variable_declContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

AslParser::ExprContext* AslParser::Variable_declContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

void AslParser::Variable_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_decl(this);
}

void AslParser::Variable_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_decl(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleVariable_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(53);
      match(AslParser::VAR);
      setState(54);
      match(AslParser::ID);
      setState(55);
      match(AslParser::T__3);
      setState(56);
      type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(57);
      match(AslParser::VAR);
      setState(58);
      match(AslParser::ID);
      setState(59);
      match(AslParser::T__3);
      setState(60);
      match(AslParser::T__4);
      setState(61);
      match(AslParser::T__5);
      setState(62);
      expr(0);
      setState(63);
      match(AslParser::T__6);
      setState(64);
      match(AslParser::T__7);
      setState(65);
      type();
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

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::TypeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::TypeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::TypeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::TypeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

void AslParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void AslParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::CHAR))) != 0))) {
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

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

void AslParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void AslParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(71);
      statement();
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ProcCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcCall(this);
}
void AslParser::ProcCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcCall(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteExpr(this);
}
void AslParser::WriteExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteExpr(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void AslParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ReadStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadStmt(this);
}
void AslParser::ReadStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadStmt(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void AslParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteString(this);
}
void AslParser::WriteStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteString(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(77);
      left_expr();
      setState(78);
      match(AslParser::ASSIGN);
      setState(79);
      expr(0);
      setState(80);
      match(AslParser::T__8);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(82);
      match(AslParser::IF);
      setState(83);
      expr(0);
      setState(84);
      match(AslParser::THEN);
      setState(85);
      statements();
      setState(86);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(88);
      ident();
      setState(89);
      match(AslParser::T__0);
      setState(90);
      match(AslParser::T__2);
      setState(91);
      match(AslParser::T__8);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(93);
      match(AslParser::READ);
      setState(94);
      left_expr();
      setState(95);
      match(AslParser::T__8);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(97);
      match(AslParser::WRITE);
      setState(98);
      expr(0);
      setState(99);
      match(AslParser::T__8);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(101);
      match(AslParser::WRITE);
      setState(102);
      match(AslParser::STRING);
      setState(103);
      match(AslParser::T__8);
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

//----------------- ReturnFunctionContext ------------------------------------------------------------------

AslParser::ReturnFunctionContext::ReturnFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ReturnFunctionContext::getRuleIndex() const {
  return AslParser::RuleReturnFunction;
}

void AslParser::ReturnFunctionContext::copyFrom(ReturnFunctionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnStmtContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnStmtContext::ReturnStmtContext(ReturnFunctionContext *ctx) { copyFrom(ctx); }

void AslParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}
void AslParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}
AslParser::ReturnFunctionContext* AslParser::returnFunction() {
  ReturnFunctionContext *_localctx = _tracker.createInstance<ReturnFunctionContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleReturnFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ReturnFunctionContext *>(_tracker.createInstance<AslParser::ReturnStmtContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(AslParser::RETURN);
    setState(107);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

void AslParser::Left_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeft_expr(this);
}

void AslParser::Left_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeft_expr(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    ident();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BooleanContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BooleanContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BooleanContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BooleanContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::BooleanContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::BooleanContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::BooleanContext::BooleanContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}
void AslParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}
//----------------- IndexArrayContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::IndexArrayContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::IndexArrayContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::IndexArrayContext::IndexArrayContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::IndexArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexArray(this);
}
void AslParser::IndexArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexArray(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ArithmeticContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic(this);
}
void AslParser::ArithmeticContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ExprIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIdent(this);
}
void AslParser::ExprIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIdent(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::DIFF() {
  return getToken(AslParser::DIFF, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GTU() {
  return getToken(AslParser::GTU, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LTU() {
  return getToken(AslParser::LTU, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::RelationalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational(this);
}
void AslParser::RelationalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}
void AslParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, AslParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<IndexArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(112);
      ident();
      setState(113);
      match(AslParser::T__5);
      setState(114);
      expr(0);
      setState(115);
      match(AslParser::T__6);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BooleanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(117);
      dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::NOT);
      setState(118);
      expr(10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ArithmeticContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(119);
      dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::PLUS);
      setState(120);
      expr(9);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ArithmeticContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::SUB);
      setState(122);
      expr(8);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(123);
      match(AslParser::INTVAL);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(124);
      ident();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(158);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(156);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(127);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(131);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AslParser::MUL: {
              setState(128);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::MUL);
              break;
            }

            case AslParser::DIV: {
              setState(129);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::DIV);
              break;
            }

            case AslParser::MOD: {
              setState(130);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::MOD);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(133);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(134);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(137);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AslParser::PLUS: {
              setState(135);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::PLUS);
              break;
            }

            case AslParser::SUB: {
              setState(136);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::SUB);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(139);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(140);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(147);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AslParser::EQUAL: {
              setState(141);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::EQUAL);
              break;
            }

            case AslParser::DIFF: {
              setState(142);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::DIFF);
              break;
            }

            case AslParser::GTU: {
              setState(143);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::GTU);
              setState(144);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::GT);
              break;
            }

            case AslParser::LT: {
              setState(145);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::LT);
              break;
            }

            case AslParser::LTU: {
              setState(146);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::LTU);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(149);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(150);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(151);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::AND);
          setState(152);
          expr(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(153);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(154);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::OR);
          setState(155);
          expr(4);
          break;
        }

        } 
      }
      setState(160);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}

void AslParser::IdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdent(this);
}

void AslParser::IdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdent(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "declarations", "variable_decl", "type", "statements", 
  "statement", "returnFunction", "left_expr", "expr", "ident"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "'('", "','", "')'", "':'", "'array'", "'['", "']'", "'of'", "';'", 
  "'not'", "'and'", "'or'", "'='", "'=='", "'!='", "'>'", "'<'", "'>='", 
  "'<='", "'+'", "'-'", "'*'", "'/'", "'%'", "'var'", "'int'", "'float'", 
  "'bool'", "'char'", "'if'", "'then'", "'else'", "'endif'", "'func'", "'endfunc'", 
  "'read'", "'write'", "'return'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "NOT", "AND", "OR", "ASSIGN", 
  "EQUAL", "DIFF", "GT", "LT", "GTE", "LTE", "PLUS", "SUB", "MUL", "DIV", 
  "MOD", "VAR", "INT", "FLOAT", "BOOL", "CHAR", "IF", "THEN", "ELSE", "ENDIF", 
  "FUNC", "ENDFUNC", "READ", "WRITE", "RETURN", "ID", "INTVAL", "STRING", 
  "COMMENT", "WS", "GTU", "LTU"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
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
    0x3, 0x2f, 0xa6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x6, 0x2, 0x1a, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0x1b, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x26, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x29, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x7, 0x4, 0x33, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x36, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x46, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x7, 0x7, 0x4b, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x4e, 0xb, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6b, 0xa, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x80, 
    0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x86, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x8c, 0xa, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0x96, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x9f, 0xa, 0xb, 0xc, 0xb, 
    0xe, 0xb, 0xa2, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x2, 0x3, 0x14, 
    0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 
    0x3, 0x3, 0x2, 0x1c, 0x1f, 0x2, 0xb5, 0x2, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x34, 0x3, 0x2, 0x2, 0x2, 0x8, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x47, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x2, 0x2, 0x3, 0x1e, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x1f, 0x20, 0x7, 0x24, 0x2, 0x2, 0x20, 0x21, 0x7, 0x29, 0x2, 
    0x2, 0x21, 0x27, 0x7, 0x3, 0x2, 0x2, 0x22, 0x23, 0x5, 0x8, 0x5, 0x2, 
    0x23, 0x24, 0x7, 0x4, 0x2, 0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x22, 0x3, 0x2, 0x2, 0x2, 0x26, 0x29, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x5, 0x8, 
    0x5, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x5, 0x2, 
    0x2, 0x2d, 0x2e, 0x5, 0x6, 0x4, 0x2, 0x2e, 0x2f, 0x5, 0xc, 0x7, 0x2, 
    0x2f, 0x30, 0x7, 0x25, 0x2, 0x2, 0x30, 0x5, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x33, 0x5, 0x8, 0x5, 0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x7, 0x1b, 0x2, 0x2, 0x38, 0x39, 0x7, 0x29, 0x2, 
    0x2, 0x39, 0x3a, 0x7, 0x6, 0x2, 0x2, 0x3a, 0x46, 0x5, 0xa, 0x6, 0x2, 
    0x3b, 0x3c, 0x7, 0x1b, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x29, 0x2, 0x2, 0x3d, 
    0x3e, 0x7, 0x6, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x7, 0x2, 0x2, 0x3f, 0x40, 
    0x7, 0x8, 0x2, 0x2, 0x40, 0x41, 0x5, 0x14, 0xb, 0x2, 0x41, 0x42, 0x7, 
    0x9, 0x2, 0x2, 0x42, 0x43, 0x7, 0xa, 0x2, 0x2, 0x43, 0x44, 0x5, 0xa, 
    0x6, 0x2, 0x44, 0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x46, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x48, 0x9, 0x2, 0x2, 0x2, 0x48, 0xb, 0x3, 0x2, 0x2, 0x2, 0x49, 
    0x4b, 0x5, 0xe, 0x8, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x50, 0x5, 0x12, 0xa, 0x2, 0x50, 0x51, 0x7, 0xf, 0x2, 
    0x2, 0x51, 0x52, 0x5, 0x14, 0xb, 0x2, 0x52, 0x53, 0x7, 0xb, 0x2, 0x2, 
    0x53, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x20, 0x2, 0x2, 0x55, 
    0x56, 0x5, 0x14, 0xb, 0x2, 0x56, 0x57, 0x7, 0x21, 0x2, 0x2, 0x57, 0x58, 
    0x5, 0xc, 0x7, 0x2, 0x58, 0x59, 0x7, 0x23, 0x2, 0x2, 0x59, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0x16, 0xc, 0x2, 0x5b, 0x5c, 0x7, 0x3, 
    0x2, 0x2, 0x5c, 0x5d, 0x7, 0x5, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0xb, 0x2, 
    0x2, 0x5e, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x26, 0x2, 0x2, 
    0x60, 0x61, 0x5, 0x12, 0xa, 0x2, 0x61, 0x62, 0x7, 0xb, 0x2, 0x2, 0x62, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x27, 0x2, 0x2, 0x64, 0x65, 
    0x5, 0x14, 0xb, 0x2, 0x65, 0x66, 0x7, 0xb, 0x2, 0x2, 0x66, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x27, 0x2, 0x2, 0x68, 0x69, 0x7, 0x2b, 
    0x2, 0x2, 0x69, 0x6b, 0x7, 0xb, 0x2, 0x2, 0x6a, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x54, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x5a, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x6b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 
    0x7, 0x28, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x14, 0xb, 0x2, 0x6e, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x16, 0xc, 0x2, 0x70, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x72, 0x8, 0xb, 0x1, 0x2, 0x72, 0x73, 0x5, 0x16, 0xc, 
    0x2, 0x73, 0x74, 0x7, 0x8, 0x2, 0x2, 0x74, 0x75, 0x5, 0x14, 0xb, 0x2, 
    0x75, 0x76, 0x7, 0x9, 0x2, 0x2, 0x76, 0x80, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x78, 0x7, 0xc, 0x2, 0x2, 0x78, 0x80, 0x5, 0x14, 0xb, 0xc, 0x79, 0x7a, 
    0x7, 0x16, 0x2, 0x2, 0x7a, 0x80, 0x5, 0x14, 0xb, 0xb, 0x7b, 0x7c, 0x7, 
    0x17, 0x2, 0x2, 0x7c, 0x80, 0x5, 0x14, 0xb, 0xa, 0x7d, 0x80, 0x7, 0x2a, 
    0x2, 0x2, 0x7e, 0x80, 0x5, 0x16, 0xc, 0x2, 0x7f, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x81, 0x85, 
    0xc, 0x9, 0x2, 0x2, 0x82, 0x86, 0x7, 0x18, 0x2, 0x2, 0x83, 0x86, 0x7, 
    0x19, 0x2, 0x2, 0x84, 0x86, 0x7, 0x1a, 0x2, 0x2, 0x85, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x9f, 0x5, 0x14, 0xb, 0xa, 
    0x88, 0x8b, 0xc, 0x8, 0x2, 0x2, 0x89, 0x8c, 0x7, 0x16, 0x2, 0x2, 0x8a, 
    0x8c, 0x7, 0x17, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x9f, 0x5, 
    0x14, 0xb, 0x9, 0x8e, 0x95, 0xc, 0x7, 0x2, 0x2, 0x8f, 0x96, 0x7, 0x10, 
    0x2, 0x2, 0x90, 0x96, 0x7, 0x11, 0x2, 0x2, 0x91, 0x92, 0x7, 0x2e, 0x2, 
    0x2, 0x92, 0x96, 0x7, 0x12, 0x2, 0x2, 0x93, 0x96, 0x7, 0x13, 0x2, 0x2, 
    0x94, 0x96, 0x7, 0x2f, 0x2, 0x2, 0x95, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x95, 0x91, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x9f, 0x5, 0x14, 0xb, 0x8, 0x98, 0x99, 0xc, 0x6, 
    0x2, 0x2, 0x99, 0x9a, 0x7, 0xd, 0x2, 0x2, 0x9a, 0x9f, 0x5, 0x14, 0xb, 
    0x7, 0x9b, 0x9c, 0xc, 0x5, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0xe, 0x2, 0x2, 
    0x9d, 0x9f, 0x5, 0x14, 0xb, 0x6, 0x9e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0xa4, 0x7, 0x29, 0x2, 0x2, 0xa4, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x1b, 0x27, 0x34, 0x45, 0x4c, 0x6a, 0x7f, 0x85, 0x8b, 0x95, 0x9e, 
    0xa0, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
