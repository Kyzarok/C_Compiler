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


%type <program_node> PROGRAM 

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
FNC_DEC	: RETTYPE FNC_NAME "("FNC_ARGS_LIST")"COMPUND_STATEMENT // two types of function declaration in basic parser/lexer
	| RETTYPE FNC_NAME "(" ")"COMPUND_STATEMENT // one with type, name, arguments and body, and one without the arguments
		//more complex fnc_dec might have a declaration in one place, and a definition in an other. This is a longer term goal to support

RETTYPE	: TYPE_SPEC //possiby just merge?

TYPE_SPEC : T_INT // only type required for 5 basic programs

FNC_NAME : IDENTIFIER 

FNC_ARGS_LIST : /* stuff */

COMPUND_STATEMENT : "{""}"
	 |"{"STATEMENT_LIST"}"

STATEMENT_LIST : STATEMENT STATEMENT_LIST

STATMENT : EXPRESSION_STATEMENT
	//COMPUND_STATEMENT
	RETURN_STATEMENT

RETURN_STATEMENT : K_RETURN ";"
		 | K_RETURN EXPRESSION ";"

EXPRESSION_STATEMENT : ";"
		| EXPRESSION ";"

EXPRESSION : ASSIGNMENT_EXPRESSION
	//EXPRESSION, ASSIGNMENT_EXPRESSION // this is for doing stuff like "int x, y;" i think
	

GLB_VAR	: TYPE IDENTIFIER

%%
const Node *g_root; // The top of the program is a node. Might be better type?

const Node *parseAST() //This function returns the tree
{
  g_root=0;
  yyparse();
  return g_root;
}

