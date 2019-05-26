//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
//
//    Copyright (C) 2017  Universitat Politecnica de Catalunya
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
//    contact: José Miguel Rivero (rivero@cs.upc.es)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID LPAREN ((param_decl',')* param_decl)? RPAREN (':' type)? declarations statements ENDFUNC
        ;

declarations
        : (variable_decl)*
        ;

param_decl
        : ID ':' ARRAY LCLAU expr RCLAU OF type # arrayParamDecl
        | ID ':' type                           # basicParamDecl
        ;

variable_decl
        : VAR decl 
        ;

decl    : ident (','ident)* ':' ARRAY LCLAU expr RCLAU OF type      # arrayDecl
     	| ID (','ID)* ':' type                                      # basicDecl 
        ;

//Tipos básicos
type    : INT
        | FLOAT
        | BOOL
        | CHAR 
        ;

statements
        : (statement)*
        ;

functioncall
        : ident LPAREN((expr',')*expr)?RPAREN # procCall
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'                             # assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statements)? ENDIF      # ifStmt

        | WHILE expr DO statements ENDWHILE   # whileStmt
          // Read a variable
        | functioncall ';'                    # funcStmt

        | READ left_expr ';'                  # readStmt
          // Write an expression
        | WRITE expr ';'                      # writeExpr
          // Write a string
        | WRITE STRING ';'                    # writeString
          // Return statement
        | RETURN expr? ';'                    # returnStmt
        ;

array_access
        : ident LCLAU expr RCLAU
        ;

// Grammar for left expressions (l-values in C++)
left_expr
        : array_access                        # indexArrayLeftExpr
        | ident                               # identifier
        ;

expr    : LPAREN expr RPAREN                  # parenthesis

        | functioncall                        # functionAsExpr

        | array_access                        # indexArrayExpr

        | (op=NOT|op=PLUS|op=SUB) expr        # unary 

        | expr (op=MUL|op=DIV|op=MOD) expr    # arithmetic
        | expr (op=PLUS|op=SUB) expr          # arithmetic

        | expr (op=EQUAL|op=DIFF|op=GTE|
                op=GT|op=LT|op=LTE) expr      # relational
       
        | expr (op=AND|op=OR) expr            # boolean

        | INTVAL                              # integervalue

        | FLOATVAL                            # floatvalue

        | CHARS                               # char

        | (TRUE|FALSE)                        # booleanvalue

        | ident                               # exprIdent
        ;

ident   : ID
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

TRUE      : 'true';
FALSE     : 'false';
LPAREN    : '(';
RPAREN    : ')';
LCLAU     : '[';
RCLAU     : ']';
OF        : 'of';
ARRAY     : 'array';
NOT       : 'not';
AND       : 'and';
OR        : 'or';
ASSIGN    : '=' ;
EQUAL     : '==' ;
DIFF      : '!=';
GT        : '>';
LT        : '<';
GTE       : '>=';
LTE       : '<=';
PLUS      : '+' ;
SUB       : '-';
MUL       : '*';
DIV       : '/';
MOD       : '%';
VAR       : 'var';
INT       : 'int';
FLOAT     : 'float';
BOOL      : 'bool';
CHAR      : 'char';
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
WHILE     : 'while' ;
DO        : 'do' ;
ENDWHILE  : 'endwhile' ;
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
READ      : 'read' ;
WRITE     : 'write' ;
RETURN    : 'return';
ID        : ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;
FLOATVAL  : ('0'..'9')+('.'('0'..'9')+)? ;

// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;
CHARS     : '\''( . | '\\n' )?'\'';
// No influyen en la gramática, son solo para simplificar...
fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
