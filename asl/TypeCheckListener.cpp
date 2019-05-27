//////////////////////////////////////////////////////////////////////
//
//    TypeCheckListener - Walk the parser tree to do the semantic
//                        typecheck for the Asl programming language
//
//    Copyright (C) 2018  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "TypeCheckListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
//#define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckListener::TypeCheckListener(TypesMgr       & Types,
				     SymTable       & Symbols,
				     TreeDecoration & Decorations,
				     SemErrors      & Errors) :
  Types{Types},
  Symbols {Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

void TypeCheckListener::enterProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
}
void TypeCheckListener::exitProgram(AslParser::ProgramContext *ctx) {
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
}

void TypeCheckListener::enterFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);

  TypesMgr::TypeId functype = getTypeDecor(ctx); 
  //Check if it's really a function? TODO
//  Symbols.setCurrentFunctionTy(functype);

  // Symbols.print();
}
void TypeCheckListener::exitFunction(AslParser::FunctionContext *ctx) {
  Symbols.popScope();
  DEBUG_EXIT();
}

void TypeCheckListener::enterDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterBasicDecl(AslParser::BasicDeclContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitBasicDecl(AslParser::BasicDeclContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterArrayDecl(AslParser::ArrayDeclContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitArrayDecl(AslParser::ArrayDeclContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterType(AslParser::TypeContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitType(AslParser::TypeContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());

    if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr()))) {
        Errors.nonReferenceableLeftExpr(ctx->left_expr());
    }

    if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
            (not Types.copyableTypes(t1, t2))) { 
        Errors.incompatibleAssignment(ctx->ASSIGN());
    }

    DEBUG_EXIT();
}
  
void TypeCheckListener::enterFunctionAsExpr(AslParser::FunctionAsExprContext *ctx) {
  DEBUG_ENTER();
}
  
void TypeCheckListener::exitFunctionAsExpr(AslParser::FunctionAsExprContext *ctx) {
  TypesMgr::TypeId t = getTypeDecor(ctx->functioncall());

  //Se utiliza como una expresion, nos interesa el return type...
  if (Types.isFunctionTy(t)) {

    TypesMgr::TypeId rettype = Types.getFuncReturnType(t);

    if (Types.isVoidTy(rettype)) {
        Errors.isNotFunction(ctx->functioncall());
    }
    else {
        putTypeDecor(ctx, rettype);
        putIsLValueDecor(ctx, false);
    }
  }
  else {
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    //Subimos lo que viene de abajo...
  }

  DEBUG_EXIT();  
}

void TypeCheckListener::enterIndexArrayLeftExpr(AslParser::IndexArrayLeftExprContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitIndexArrayLeftExpr(AslParser::IndexArrayLeftExprContext *ctx) {
  TypesMgr::TypeId t = getTypeDecor(ctx->array_access());
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, true);
  DEBUG_EXIT();
}

void TypeCheckListener::enterArray_access(AslParser::Array_accessContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitArray_access(AslParser::Array_accessContext *ctx) {
  TypesMgr::TypeId index_type = getTypeDecor(ctx->expr());
  TypesMgr::TypeId ident_type = getTypeDecor(ctx->ident());

  TypesMgr::TypeId error_type = Types.createErrorTy();
  if ((not Types.isErrorTy(ident_type)) and (not Types.isArrayTy(ident_type))) {
    Errors.nonArrayInArrayAccess(ctx);
    putTypeDecor(ctx, error_type);
    putIsLValueDecor(ctx, false);
  }

  if ((not Types.isErrorTy(index_type) and (not Types.isIntegerTy(index_type)))) {
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());
    putTypeDecor(ctx, error_type);
    putIsLValueDecor(ctx, false);
  }
 
  if ((not Types.isErrorTy(ident_type)) and (Types.isArrayTy(ident_type))) {
    TypesMgr::TypeId ret_type = Types.getArrayElemType(ident_type);
    putTypeDecor(ctx, ret_type);
    putIsLValueDecor(ctx, true);   
  }
 
  DEBUG_EXIT();
}

void TypeCheckListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) {
    Errors.booleanRequired(ctx);
  }

  DEBUG_EXIT();
}
  
void TypeCheckListener::enterWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
}
  
void TypeCheckListener::exitWhileStmt(AslParser::WhileStmtContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) {
    Errors.booleanRequired(ctx);
  }
  DEBUG_EXIT();
}


void TypeCheckListener::enterProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitProcCall(AslParser::ProcCallContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
    Errors.isNotCallable(ctx->ident());
  }
  
  if (not Types.isErrorTy(t1) and Types.isFunctionTy(t1)) {
      int num_params = Types.getNumOfParameters(t1);
      
      int i = 0;
      for (auto param : ctx->expr()) {

        if (i >= num_params) {
            i++;
            continue;
        }

        TypesMgr::TypeId called_param_type = getTypeDecor(param);
        TypesMgr::TypeId declared_param_type = Types.getParameterType(t1, i);

        if ((not Types.isErrorTy(called_param_type)) and (not Types.isErrorTy(declared_param_type)) and
             (not Types.copyableTypes(declared_param_type, called_param_type))) {
            Errors.incompatibleParameter(param, i+1, ctx->ident());
        }         
        i++;
      }
    
      if (i != num_params) {
        Errors.numberOfParameters(ctx);
      }

      putTypeDecor(ctx, t1);
      putIsLValueDecor(ctx, false);
  }
    
  DEBUG_EXIT();
}

void TypeCheckListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
}

void TypeCheckListener::enterWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
}

void TypeCheckListener::enterWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_EXIT();
}


void TypeCheckListener::enterIdentifier(AslParser::IdentifierContext *ctx) {
 DEBUG_ENTER();
}

void TypeCheckListener::exitIdentifier(AslParser::IdentifierContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);

  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
}

void TypeCheckListener::enterIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitIdent(AslParser::IdentContext *ctx) {
  std::string ident = ctx->ID()->getText();
  int found_stack = Symbols.findInStack(ident);
  if (found_stack == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }


  DEBUG_EXIT();
}
  
void TypeCheckListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
  //TODO FALTA subir las cosas
  DEBUG_EXIT();
}


void TypeCheckListener::enterUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitUnary(AslParser::UnaryContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    std::string oper = ctx->op->getText();

    TypesMgr::TypeId t;

    if (oper != "not") {
        if ((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) {
            Errors.incompatibleOperator(ctx->op);
        }
        t = t1;
        putTypeDecor(ctx, t);
    }
    else {
        if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) {
            Errors.incompatibleOperator(ctx->op);
        }
        t = Types.createBooleanTy();
        putTypeDecor(ctx, t);
    }
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
}

void TypeCheckListener::enterIndexArrayExpr(AslParser::IndexArrayExprContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitIndexArrayExpr(AslParser::IndexArrayExprContext *ctx) {
  TypesMgr::TypeId t = getTypeDecor(ctx->array_access());
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, true); 
  DEBUG_EXIT();
}

void TypeCheckListener::enterReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  //Palabra clave return y una expresion (o no)
  TypesMgr::TypeId functype = Symbols.getCurrentFunctionTy();

  if ((not Types.isErrorTy(functype)) and (Types.isFunctionTy(functype))) {
      TypesMgr::TypeId returntype = Types.getFuncReturnType(functype); 

      TypesMgr::TypeId exprtype = getTypeDecor(ctx->expr()); 

      if (not ctx->expr() and (not Types.isErrorTy(returntype)) and
              (not Types.isVoidTy(returntype))) {
            Errors.incompatibleReturn(ctx);
      }

      if ((not Types.isErrorTy(returntype)) and (not Types.isErrorTy(exprtype)) and
              (not Types.copyableTypes(returntype, exprtype))) {
            Errors.incompatibleReturn(ctx);
      }
  }

  DEBUG_EXIT();
}  

void TypeCheckListener::enterArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  std::string op = ctx->op->getText();
  if (op == "%") {
	  if (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))) or
	     ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2)))) {
		  Errors.incompatibleOperator(ctx->op);
	  }
  }
  else {
      if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
	     ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2)))) { 
		   Errors.incompatibleOperator(ctx->op);
	   } 
  }

  TypesMgr::TypeId t;
  if (((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) 
		and (Types.isFloatTy(t1) or Types.isFloatTy(t2)))) {
    t = Types.createFloatTy();
  }
  else {
    t = Types.createIntegerTy();
  }

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);

  DEBUG_EXIT();
}

void TypeCheckListener::enterBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitBoolean(AslParser::BooleanContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if ((((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
      (((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2)))))) {
    Errors.incompatibleOperator(ctx->op);
  } 

  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);

  DEBUG_EXIT();
}

void TypeCheckListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitRelational(AslParser::RelationalContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();

  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);

  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterIntegervalue(AslParser::IntegervalueContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitIntegervalue(AslParser::IntegervalueContext *ctx) {
  TypesMgr::TypeId t = Types.createIntegerTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterFloatvalue(AslParser::FloatvalueContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitFloatvalue(AslParser::FloatvalueContext *ctx) {
  TypesMgr::TypeId t = Types.createFloatTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterChar(AslParser::CharContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitChar(AslParser::CharContext *ctx) {
  TypesMgr::TypeId t = Types.createCharacterTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterBooleanvalue(AslParser::BooleanvalueContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitBooleanvalue(AslParser::BooleanvalueContext *ctx) {
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitExprIdent(AslParser::ExprIdentContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);

  DEBUG_EXIT();
}


void TypeCheckListener::enterParenthesis(AslParser::ParenthesisContext *ctx) {
  DEBUG_ENTER();
}
  
void TypeCheckListener::exitParenthesis(AslParser::ParenthesisContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->expr());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
}
  
void TypeCheckListener::enterPair_access(AslParser::Pair_accessContext *ctx) {
  DEBUG_ENTER();
}
  
void TypeCheckListener::exitPair_access(AslParser::Pair_accessContext *ctx) {
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());

  TypesMgr::TypeId t1 = Types.getFirstPairType(t);
  TypesMgr::TypeId t2 = Types.getSecondPairType(t); 
  
  if (ctx->FIRST()) {
    putTypeDecor(ctx, t1);
  }
  else if(ctx->SECOND()) {
    putTypeDecor(ctx, t2);
  }

  putIsLValueDecor(ctx, true);
  
  DEBUG_EXIT();
}
  
void TypeCheckListener::enterPairAccessExpr(AslParser::PairAccessExprContext *ctx) {
  DEBUG_ENTER();
}
 
void TypeCheckListener::exitPairAccessExpr(AslParser::PairAccessExprContext *ctx) {
  putTypeDecor(ctx, getTypeDecor(ctx->pair_access()));
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}
  
void TypeCheckListener::enterPairAccessLeftExpr(AslParser::PairAccessLeftExprContext *ctx) {
  DEBUG_ENTER();
}
  
void TypeCheckListener::exitPairAccessLeftExpr(AslParser::PairAccessLeftExprContext *ctx) {
  putTypeDecor(ctx, getTypeDecor(ctx->pair_access()));
  putIsLValueDecor(ctx, true);
  DEBUG_EXIT();
}

// void TypeCheckListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_ENTER();
// }
// void TypeCheckListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_EXIT();
// }
// void TypeCheckListener::visitTerminal(antlr4::tree::TerminalNode *node) {
//   DEBUG("visitTerminal");
// }
// void TypeCheckListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
// }


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckListener::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckListener::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckListener::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckListener::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
