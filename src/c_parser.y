code requires{
  #include "ast.hpp"
  #include <string>
  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

//Need to put all token types here

%token T_TIMES T_DIVIDE T_PLUS T_MINUS //basic four operators
%token T_EQUALS
%token	T_INT T_CHAR T_STRINGLIT
%token T_LBRACKET T_RBRACKET T_LSQUARE T_RSQUARE T_LCURLY T_RCURLY
%token T_KEYW_IF T_KEYW_ELSE T_
%token T_NUMBER T_VARIABLE

//%type <expr> EXPR TERM FACTOR
//%type <number> T_NUMBER
//%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%type <program_node> PROGRAM

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM	:FNC_DEC
	|GLB_VAR
	|FNC_DEC PROGRAM
	|GLB_VAR PROGRAM

FNC_DEC	: RETTYPE FNC_NAME "("FNC_ARGS")"FNC_BODY

RETTYPE	: TYPE

FNC_NAME : IDENTIFIER

FNC_ARGS : /* stuff */

FNC_BODY : COMPOUND_STATEMENT

GLB_VAR	: TYPE 

%%
const /*Need to change type of this*/Expression *g_root; // Definition of variable (to match declaration earlier)

