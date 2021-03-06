//////////////////////////////////////////////////////////////////////
//
//    CodeGenListener - Walk the parser tree to do
//                             the generation of code
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

#include "CodeGenListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenListener::CodeGenListener(TypesMgr       & Types,
				 SymTable       & Symbols,
				 TreeDecoration & Decorations,
				 code           & Code) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Code{Code} {
}

void CodeGenListener::enterProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
}
void CodeGenListener::exitProgram(AslParser::ProgramContext *ctx) {
  Symbols.popScope();
  DEBUG_EXIT();
}

void CodeGenListener::enterFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  subroutine subr(ctx->ID()->getText());
  Code.add_subroutine(subr);
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  codeCounters.reset();
}
void CodeGenListener::exitFunction(AslParser::FunctionContext *ctx) {
  subroutine & subrRef = Code.get_last_subroutine();
  instructionList code = getCodeDecor(ctx->statements());

  std::string ident = ctx->ID()->getText();

  TypesMgr::TypeId t = getTypeDecor(ctx); 

  if (not Types.isVoidFunction(t)) {
    subrRef.add_param("_result");
  }
 
  for (auto decl : ctx->param_decl()) {
    AslParser::BasicParamDeclContext* basicdeclaration = dynamic_cast<AslParser::BasicParamDeclContext*>(decl); 
    AslParser::ArrayParamDeclContext* arraydeclaration = dynamic_cast<AslParser::ArrayParamDeclContext*>(decl); 

    if (basicdeclaration) {
        subrRef.add_param(basicdeclaration->ID()->getText()); 
    }
    else if (arraydeclaration) {
        subrRef.add_param(arraydeclaration->ID()->getText()); 
    }
 } 

  code = code || instruction::RETURN();
  subrRef.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
}

void CodeGenListener::enterDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_EXIT();
}

/*void CodeGenListener::enterVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitVariable_decl(AslParser::Variable_declContext *ctx) {
  subroutine       & subrRef = Code.get_last_subroutine();
  TypesMgr::TypeId        t1 = getTypeDecor(ctx->type());
  std::size_t           size = Types.getSizeOfType(t1);
  subrRef.add_var(ctx->ID()->getText(), size); //Añadir variable a la subrutina
   
  DEBUG_EXIT();
}*/

void CodeGenListener::enterBasicDecl(AslParser::BasicDeclContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitBasicDecl(AslParser::BasicDeclContext *ctx) {
  
  TypesMgr::TypeId        t1 = getTypeDecor(ctx->type());
  subroutine       & subrRef = Code.get_last_subroutine();
  std::size_t           size = Types.getSizeOfType(t1);
 
  for (auto identifier : ctx->ID()) {
    subrRef.add_var(identifier->getText(), size); //Añadir variable a la subrutina
  } 

  DEBUG_EXIT();
}

void CodeGenListener::enterArrayDecl(AslParser::ArrayDeclContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitArrayDecl(AslParser::ArrayDeclContext *ctx) {

  subroutine       & subrRef = Code.get_last_subroutine();
  
  for (auto identifier : ctx->ident()) {
    TypesMgr::TypeId        t1 = getTypeDecor(identifier);
    std::size_t           size = Types.getSizeOfType(t1);
    subrRef.add_var(identifier->getText(), size); //Añadir variable a la subrutina
  }

 DEBUG_EXIT();
}
  
void CodeGenListener::enterIndexArrayLeftExpr(AslParser::IndexArrayLeftExprContext *ctx) {
  DEBUG_ENTER();
}
  
void CodeGenListener::exitIndexArrayLeftExpr(AslParser::IndexArrayLeftExprContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->array_access()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->array_access()));
  putCodeDecor(ctx, getCodeDecor(ctx->array_access()));
  DEBUG_EXIT();
}

void CodeGenListener::enterIndexArrayExpr(AslParser::IndexArrayExprContext *ctx) {
  DEBUG_ENTER();
}
  
void CodeGenListener::exitIndexArrayExpr(AslParser::IndexArrayExprContext *ctx) {
  std::string addr     = getAddrDecor(ctx->array_access());
  std::string offs     = getOffsetDecor(ctx->array_access());
  instructionList code = getCodeDecor(ctx->array_access());

  std::string temp1 = "%"+codeCounters.newTEMP();

  if (Symbols.isParameterClass(addr)) {
    std::string temp2 = "%"+codeCounters.newTEMP();
    code = code || instruction::LOAD(temp1, addr) || instruction::LOADX(temp2, temp1, offs);
    putAddrDecor(ctx, temp2);
  } 
  else {
    code = code || instruction::LOADX(temp1, addr, offs);
    putAddrDecor(ctx, temp1);
  }

  putOffsetDecor(ctx, offs);
  putCodeDecor(ctx, code);

  DEBUG_EXIT();
}
  
void CodeGenListener::enterArray_access(AslParser::Array_accessContext *ctx) {
  DEBUG_ENTER();
}
  
void CodeGenListener::exitArray_access(AslParser::Array_accessContext *ctx) {
  //What you have to do is to populate the offset ([thisnumber]),
  //but the code will be empty. 
  std::string offset = getAddrDecor(ctx->expr());
  instructionList code = getCodeDecor(ctx->expr());

  putAddrDecor(ctx, ctx->ident()->ID()->getText());
  putOffsetDecor(ctx, offset);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterType(AslParser::TypeContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitType(AslParser::TypeContext *ctx) {
  DEBUG_EXIT();
}

void CodeGenListener::enterStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitStatements(AslParser::StatementsContext *ctx) {
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    code = code || getCodeDecor(stCtx);
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
  instructionList  code;
  std::string     addr1 = getAddrDecor(ctx->left_expr());
  std::string     offs1 = getOffsetDecor(ctx->left_expr());
  instructionList code1 = getCodeDecor(ctx->left_expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  std::string     addr2 = getAddrDecor(ctx->expr());
  std::string     offs2 = getOffsetDecor(ctx->expr());
  instructionList code2 = getCodeDecor(ctx->expr());
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());

  if (offs1 != "") { //Is an array access!
    std::string temp1 = "%"+codeCounters.newTEMP();
    	  
    if (Symbols.isParameterClass(addr1)) {
      code = code1 || code2 || instruction::LOAD(temp1, addr1) || instruction::XLOAD(temp1, offs1, addr2);
    } 
    else {
      code = code1 || code2 || instruction::XLOAD(addr1, offs1, addr2);
    }
  }
  else {
    if (Types.isArrayTy(tid1) and Types.isArrayTy(tid2)) {
    	//We shall copy the values of addr2 into addr1.
	//Supposing that the sizes are equal!
	
 	instructionList copy;	
	int array_size = Types.getArraySize(tid1);
	
    	std::string temp1 = "%"+codeCounters.newTEMP();
    	std::string temp2 = "%"+codeCounters.newTEMP();

	//Take into account that you can be using parameters here, so 
	//probably you will have to use a temporal in between to use
	//the base address of the array.
	std::string aux1 = addr1;
	std::string aux2 = addr2;

	if (Symbols.isParameterClass(addr1)) {
	  aux1 = "%"+codeCounters.newTEMP();
	  copy = instruction::LOAD(aux1, addr1);
	}  

	if (Symbols.isParameterClass(addr2)) {
	  aux2 = "%"+codeCounters.newTEMP();
	  copy = instruction::LOAD(aux2, addr2);
	}  

	for (int i = 0; i < array_size; ++i) {
	  copy = copy || instruction::ILOAD(temp1, std::to_string(i)) 	||
 			 instruction::LOADX(temp2, aux2, temp1) 	|| 
			 instruction::XLOAD(aux1, temp1, temp2);
	}
	code = code1 || code2 || copy;
    }
    else {
      code = code1 || code2 || instruction::LOAD(addr1, addr2);
    }
  }

  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
  instructionList   code;
  std::string      addr1 = getAddrDecor(ctx->expr());
  instructionList  code1 = getCodeDecor(ctx->expr());
  instructionList  code2 = getCodeDecor(ctx->statements(0));
  std::string      label = codeCounters.newLabelIF();

  if (ctx->statements(1)) {
    //else 
    std::string labelElse = "else"+label;
    instructionList code3 = getCodeDecor(ctx->statements(1));
    code = code1 || instruction::FJUMP(addr1, labelElse) ||
           code2 || instruction::LABEL(labelElse)        || 
           code3;
  }
  else {
    std::string labelEndIf = "endif"+label;
    code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
           code2 || instruction::LABEL(labelEndIf);
  }

  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitWhileStmt(AslParser::WhileStmtContext *ctx) {
  instructionList   code;
  std::string      addr1 = getAddrDecor(ctx->expr());
  instructionList  code1 = getCodeDecor(ctx->expr());
  instructionList  code2 = getCodeDecor(ctx->statements());
  std::string      label = codeCounters.newLabelWHILE();
  std::string labelStartWhile = "startwhile"+label;
  std::string labelEndWhile = "endwhile"+label;

  code = instruction::LABEL(labelStartWhile)                || 
         code1 || instruction::FJUMP(addr1, labelEndWhile)  ||
         code2 || instruction::UJUMP(labelStartWhile)       ||
         instruction::LABEL(labelEndWhile);

  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  std::string     addr1;
  instructionList code1;

  if (ctx->expr()) {
    addr1 = getAddrDecor(ctx->expr());
    code1 = getCodeDecor(ctx->expr());
    std::string temp = "%"+codeCounters.newTEMP();

    code1 = code1 || instruction::LOAD("_result", addr1); 
  }
  
  putAddrDecor(ctx, addr1);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code1);
  DEBUG_EXIT();
  
  DEBUG_EXIT();
}

void CodeGenListener::enterProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitProcCall(AslParser::ProcCallContext *ctx) {
  instructionList code;
  // std::string name = ctx->ident()->ID()->getSymbol()->getText();
  std::string name = ctx->ident()->getText();

  TypesMgr::TypeId t = getTypeDecor(ctx->ident());
   
  if (not Types.isVoidFunction(t)) {
    code = instruction::PUSH();
  }

 TypesMgr::TypeId function_type = getTypeDecor(ctx);
 
 int i = 0;
 std::string temp;
 
 for (auto param : ctx->expr()) {
    std::string addr =          getAddrDecor(param);
    instructionList paramcode = getCodeDecor(param); 
    
    instructionList conversioncode;
    TypesMgr::TypeId originalparam_type = Types.getParameterType(function_type, i);
    TypesMgr::TypeId passedparam_type   = getTypeDecor(param);  
    if (Types.isFloatTy(originalparam_type) and Types.isIntegerTy(passedparam_type)) {
        conversioncode = instruction::FLOAT(addr, addr);
    }

    if (Types.isArrayTy(originalparam_type)) {
        temp = "%"+codeCounters.newTEMP();
        paramcode = paramcode || instruction::ALOAD(temp, addr);
        addr = temp;
    }

    code = code || paramcode || conversioncode || instruction::PUSH(addr);
    //TODO Surely we have to do some conversions...
    i++;
  }

  code = code || instruction::CALL(name);

  for (auto param : ctx->expr()) {
    std::string addr = getAddrDecor(param);
    code = code || instruction::POP();
  }
  
  temp = "";
  if (not Types.isVoidFunction(t)) {
    temp = "%"+codeCounters.newTEMP();
    code = code || instruction::POP(temp);
  }
  
  putAddrDecor(ctx, temp);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
  instructionList  code;
  std::string     addr1 = getAddrDecor(ctx->left_expr());
  std::string     offs1 = getOffsetDecor(ctx->left_expr());
  instructionList code1 = getCodeDecor(ctx->left_expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

  std::string address;

  if (offs1 != "") {
    //Array access
    address = "%"+codeCounters.newTEMP();
  }
  else {
    address = addr1;
  }

  if (Types.isCharacterTy(tid1)) {
    code = code1 || instruction::READC(address);
  }
  else if (Types.isFloatTy(tid1)) {
    code = code1 || instruction::READF(address);
  }
  else {
    code = code1 || instruction::READI(address);
  }

  if (offs1 != "") {
    code = code || instruction::XLOAD(addr1, offs1, address);
  }

  putOffsetDecor(ctx, offs1);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterChar(AslParser::CharContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitChar(AslParser::CharContext *ctx) {
  instructionList code;
  std::string s = ctx->CHARS()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  
  code = instruction::CHLOAD(temp, s.substr(1, s.size()-2)); 
 
  putAddrDecor(ctx, temp);	  
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);

  DEBUG_EXIT();	
}

void CodeGenListener::enterWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
  instructionList code;
  std::string     addr1 = getAddrDecor(ctx->expr());
  std::string     offs1 = getOffsetDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());

  if (Types.isCharacterTy(tid1)) { 
    code = code1 || instruction::WRITEC(addr1);
  }
  else if (Types.isFloatTy(tid1)) {
    code = code1 || instruction::WRITEF(addr1);
  }
  else {
    code = code1 || instruction::WRITEI(addr1);
  }

  putOffsetDecor(ctx, offs1);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteString(AslParser::WriteStringContext *ctx) {
  instructionList code;
  std::string s = ctx->STRING()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  int i = 1;
  while (i < int(s.size())-1) {
    if (s[i] != '\\') {
      code = code ||
	     instruction::CHLOAD(temp, s.substr(i,1)) ||
	     instruction::WRITEC(temp);
      i += 1;
    }
    else {
      assert(i < int(s.size())-2);
      if (s[i+1] == 'n') {
        code = code || instruction::WRITELN();
        i += 2;
      }
      else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,2)) ||
	       instruction::WRITEC(temp);
        i += 2;
      }
      else {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,1)) ||
	       instruction::WRITEC(temp);
        i += 1;
      }
    }
  }

  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}
/*
void CodeGenListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->ident()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
  putCodeDecor(ctx, getCodeDecor(ctx->ident()));
  DEBUG_ENTER();
}
*/
void CodeGenListener::enterArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  TypesMgr::TypeId t  = getTypeDecor(ctx);

  //Here we are doing an operation such as t1 OP t2 = t 
  //if t is of some type t, the operation must be of that type.

  std::string temp = "%"+codeCounters.newTEMP();
  if (not Types.isFloatTy(t)) {
    if (ctx->MUL())
      code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->PLUS())
      code = code || instruction::ADD(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->MOD()) {	
      code = code || instruction::DIV(temp, addr1, addr2);
      code = code || instruction::MUL(temp, temp, addr2);
      code = code || instruction::SUB(temp, addr1, temp);
      //TODO Must be checked someday
    }
    else if (ctx->SUB())
      code = code || instruction::SUB(temp, addr1, addr2);
  }
  else {

    //I reuse the temporal

    if (Types.isIntegerTy(t1)) {
       code = code || instruction::FLOAT(temp, addr1);
       addr1 = temp;
    }  
    
    if (Types.isIntegerTy(t2)) {
       code = code || instruction::FLOAT(temp, addr2);
       addr2 = temp;
    }  

    if (ctx->MUL())
      code = code || instruction::FMUL(temp, addr1, addr2);
    else if (ctx->PLUS())
      code = code || instruction::FADD(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::FDIV(temp, addr1, addr2);
    else if (ctx->MOD()) {	
      code = code || instruction::FDIV(temp, addr1, addr2);
      code = code || instruction::FMUL(temp, temp, addr2);
      code = code || instruction::FSUB(temp, addr1, temp);
      //TODO Must be checked someday
    }
    else if (ctx->SUB())
      code = code || instruction::FSUB(temp, addr1, addr2);
  }
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}
  
void CodeGenListener::enterParenthesis(AslParser::ParenthesisContext *ctx) {
  DEBUG_ENTER();
}
  
void CodeGenListener::exitParenthesis(AslParser::ParenthesisContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->expr()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->expr()));
  putCodeDecor(ctx, getCodeDecor(ctx->expr()));
  DEBUG_EXIT();
}

void CodeGenListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitRelational(AslParser::RelationalContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId t  = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->EQUAL())
    code = code || instruction::EQ(temp, addr1, addr2);
  else if (ctx->DIFF()) {
    code = code || instruction::EQ(temp, addr1, addr2);
    code = code || instruction::NOT(temp, temp);
  }
  else if (ctx->GTE()) {
    code = code || instruction::LT(temp, addr1, addr2);    
    code = code || instruction::NOT(temp, temp);    
  }
  else if (ctx->GT()) {
    code = code || instruction::LE(temp, addr1, addr2);    
    code = code || instruction::NOT(temp, temp);    
  }
  else if (ctx->LTE()) {
    code = code || instruction::LE(temp, addr1, addr2);    
  }
  else if (ctx->LT()) {
    code = code || instruction::LT(temp, addr1, addr2);    
  }

  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}  
  
void CodeGenListener::enterUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
}
   
void CodeGenListener::exitUnary(AslParser::UnaryContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  std::string temp = "%"+codeCounters.newTEMP();

  TypesMgr::TypeId t_expr  = getTypeDecor(ctx->expr());
  
  if (ctx->NOT()) {
    code1 = code1 || instruction::NOT(temp, addr1);
  }

  if (Types.isFloatTy(t_expr)) {
    if (ctx->SUB()) {
      code1 = code1 || instruction::FSUB(temp, "", addr1);
    }
  }
  else {
    if (ctx->SUB()) {
      code1 = code1 || instruction::SUB(temp, "", addr1);
    }
  }

  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code1);
  DEBUG_EXIT();
}

void CodeGenListener::enterBoolean(AslParser::BooleanContext* ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitBoolean(AslParser::BooleanContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  std::string temp = "%"+codeCounters.newTEMP();

  if (ctx->AND()) {
    code = code || instruction::AND(temp, addr1, addr2);
  }
  else if (ctx->OR()) {
    code = code || instruction::OR(temp, addr1, addr2);
  }

  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterIntegervalue(AslParser::IntegervalueContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitIntegervalue(AslParser::IntegervalueContext *ctx) {
  instructionList code;

  std::string ident = ctx->getText();

  std::string temp = "%"+codeCounters.newTEMP();
  code = instruction::ILOAD(temp, ident);
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterFloatvalue(AslParser::FloatvalueContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitFloatvalue(AslParser::FloatvalueContext *ctx) {
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  code = instruction::FLOAD(temp, ctx->getText());
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterBooleanvalue(AslParser::BooleanvalueContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitBooleanvalue(AslParser::BooleanvalueContext *ctx) {
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  std::string true_false = ctx->getText();
  if (true_false == "true") {
    code = instruction::ILOAD(temp, "1");
  }
  else if (true_false == "false") {
    code = instruction::ILOAD(temp, "0");
  }

  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitExprIdent(AslParser::ExprIdentContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->ident()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
  putCodeDecor(ctx, getCodeDecor(ctx->ident()));
  DEBUG_EXIT();
}

void CodeGenListener::enterIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitIdent(AslParser::IdentContext *ctx) {
  putAddrDecor(ctx, ctx->ID()->getText());
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, instructionList());
  DEBUG_EXIT();
}

void CodeGenListener::enterIdentifier(AslParser::IdentifierContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitIdentifier(AslParser::IdentifierContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->ident()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
  putCodeDecor(ctx, getCodeDecor(ctx->ident()));

  DEBUG_EXIT();
}
  
void CodeGenListener::enterFunctionAsExpr(AslParser::FunctionAsExprContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitFunctionAsExpr(AslParser::FunctionAsExprContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->functioncall()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->functioncall()));
  putCodeDecor(ctx, getCodeDecor(ctx->functioncall()));
  DEBUG_EXIT();
}


void CodeGenListener::enterFunctioncall(AslParser::FunctioncallContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitFunctioncall(AslParser::FunctioncallContext *ctx) {
  DEBUG_EXIT();
}
  
void CodeGenListener::enterFuncStmt(AslParser::FuncStmtContext *ctx) {
  DEBUG_ENTER();
}
  
void CodeGenListener::exitFuncStmt(AslParser::FuncStmtContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->functioncall()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->functioncall()));
  putCodeDecor(ctx, getCodeDecor(ctx->functioncall()));
  DEBUG_EXIT();
}

// void CodeGenListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_ENTER();
// }
// void CodeGenListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_EXIT();
// }
// void CodeGenListener::visitTerminal(antlr4::tree::TerminalNode *node) {
//   DEBUG(">>> visit " << node->getSymbol()->getLine() << ":" << node->getSymbol()->getCharPositionInLine() << " CodeGen TerminalNode");
// }
// void CodeGenListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
// }


// Getters for the necessary tree node atributes:
//   Scope, Type, Addr, Offset and Code
SymTable::ScopeId CodeGenListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
std::string CodeGenListener::getAddrDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getAddr(ctx);
}
std::string  CodeGenListener::getOffsetDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getOffset(ctx);
}
instructionList CodeGenListener::getCodeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getCode(ctx);
}

// Setters for the necessary tree node attributes:
//   Addr, Offset and Code
void CodeGenListener::putAddrDecor(antlr4::ParserRuleContext *ctx, const std::string & a) {
  Decorations.putAddr(ctx, a);
}
void CodeGenListener::putOffsetDecor(antlr4::ParserRuleContext *ctx, const std::string & o) {
  Decorations.putOffset(ctx, o);
}
void CodeGenListener::putCodeDecor(antlr4::ParserRuleContext *ctx, const instructionList & c) {
  Decorations.putCode(ctx, c);
}
