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
%token K_IF K_ELSE K_CHAR K_FLOAT K_FOR K_WHILE //more keyowords, not needed for minimal parser / lexer
%token O_PLUS O_EQUALS O_MINUS O_ASTR O_DIV //Arithmetic Operators (and pointer I guess). Minimal ones for parser / lexer
%token L_IS_EQUAL L_IS_NOT_EQUAL L_AND L_OR L_NOT //Logical operators
%token B_AND B_OR B_NOT B_XOR B_LSHIFT B_RSHIFT //Bitwise operators
%token P_LHEADER P_RHEADER P_LSQBRAC P_RSQBRAC L_CURLBRAC R_CURLBRAC P_LBRACKET P_RBRACKET // punctuators
%token P_LIST_SEPARATOR P_STATEMENT_LABEL P_STATEMENT_END P_VARIABLE_LENGTH_ARGUMENT_LIST P_INCLUDE P_CHAR_CONST //more punctuators, not sure if needed?
%token T_INT T_IDENTIFIER //Types. Minimal ones for parser / lexer


%type <Node> PROGRAM FNC_DEC T_INT T_IDENTIFIER K_INT K_RETURN O_PLUS O_EQUALS O_MINUS O_ASTR O_DIV L_IS_EQUAL L_IS_NOT_EQUAL L_AND L_OR L_NOT B_AND B_OR B_NOT B_XOR B_LSHIFT B_RSHIFT TYPE_SPEC FNC_ID COMPOUND_STATEMENT STATEMENT_LIST STATEMENT RETURN_STATEMENT EXPRESSION CONSTANT

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
FNC_DEC : TYPE_SPEC FNC_ID P_LBRACKET P_RBRACKET L_CURLBRAC COMPOUND_STATEMENT R_CURLBRAC // I think maybe just have Statement_list here?

TYPE_SPEC : K_INT

CONSTANT : T_INT
	/*okay, so if I understand this correctly, this is where the return that goes into the AST happens*/

FNC_ID : T_IDENTIFIER

COMPOUND_STATEMENT : STATEMENT_LIST 
		//and some other stuff

STATEMENT_LIST : STATEMENT
		| STATEMENT STATEMENT_LIST

STATEMENT : RETURN_STATEMENT

RETURN_STATEMENT : K_RETURN EXPRESSION P_STATEMENT_END

EXPRESSION : CONSTANT
	|	OPERATOR	//I know this isn't quite right, but I needed a place to declare Operators

OPERATOR : O_PLUS 
	| O_EQUALS 
	| O_MINUS 
	| O_ASTR 
	| O_DIV
	| L_IS_EQUAL 
	| L_IS_NOT_EQUAL 
	| L_AND 
	| L_OR 
	| L_NOT
	| B_AND 
	| B_OR 
	| B_NOT 
	| B_XOR 
	| B_LSHIFT 
	| B_RSHIFT

%%
const Node *g_root; // The top of the program is a node. Might be better type?

const Node *parseAST() //This function returns the tree
{
  g_root=0;
  yyparse();
  return g_root;
}
/*need to create more abstraction to separate operators, identifiers, keywords etc....*/
