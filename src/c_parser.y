%code requires{
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

%token K_INT K_RETURN  //Keywords. These are the ones needed for my minimal lexer / parser
//%token K_IF K_ELSE //more keyowords
%token O_PLUS O_EQUALS //Operators. Minimal ones for parser / lexer

%token T_INT T_VARIABLE //Types. Minimal ones for parser / lexer

//%type <expr> EXPR TERM FACTOR
//%type <number> T_NUMBER
//%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%type <program_node> PROGRAM

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM	: FNC_DEC
	/* comment out things that we don't need right now
	|GLB_VAR
	|FNC_DEC PROGRAM
	|GLB_VAR PROGRAM
	*/
FNC_DEC	: RETTYPE FNC_NAME "("FNC_ARGS_LIST")"FNC_BODY

RETTYPE	: TYPE_SPEC

TYPE_SPEC	: T_INT

FNC_NAME : IDENTIFIER

FNC_ARGS_LIST : /* stuff */

FNC_BODY : COMPOUND_STATEMENT

GLB_VAR	: TYPE IDENTIFIER

%%
const /*Need to change type of this*/Expression *g_root; // Definition of variable (to match declaration earlier)

