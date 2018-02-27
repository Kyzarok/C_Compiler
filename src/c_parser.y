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
//%token K_IF K_ELSE //more keyowords, not needed for minimal parser / lexer
%token O_PLUS O_EQUALS //Operators. Minimal ones for parser / lexer

%token T_INT T_VARIABLE //Types. Minimal ones for parser / lexer


%type <Node> PROGRAM FNC_DEC T_INT T_VARIABLE K_INT K_RETURN O_PLUS O_EQUALS TYPE_SPEC FNC_ID COMPOUND_STATEMENT STATEMENT_LIST STATEMENT RETURN_STATEMENT EXPRESSION CONSTANT

/*	
*/

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

 /*	Most of the AST is not implemented. However, by recognizing in advance what
	nodes of the tree we will encounter, it prevents the issue of advancing too
	far and having an unstable foundation
 */
PROGRAM	: FNC_DEC
	/* 	comment out things that we don't need right now
		as they're unneeded for basic parser
	|GLB_VAR
	|FNC_DEC PROGRAM
	|GLB_VAR PROGRAM

	*/
FNC_DEC : TYPE_SPEC FNC_ID "(" ")" COMPOUND_STATEMENT

TYPE_SPEC : K_INT

CONSTANT : T_INT
	

FNC_ID : T_VARIABLE

COMPOUND_STATEMENT : "{"STATEMENT_LIST"}"
		

STATEMENT_LIST : STATEMENT
		| STATEMENT STATEMENT_LIST

STATEMENT : RETURN_STATEMENT

RETURN_STATEMENT : K_RETURN EXPRESSION ";"

EXPRESSION : CONSTANT

%%
const Node *g_root; // The top of the program is a node. Might be better type?

const Node *parseAST() //This function returns the tree
{
  g_root=0;
  yyparse();
  return g_root;
}

