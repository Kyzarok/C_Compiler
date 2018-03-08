%code requires{
  #include "ast.hpp"
  #include <string>
  #include <cassert>
  #include <iostream>

  extern const Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Node *node;
  const Expression *expression;
  const Statement *statement;
  double number;
  std::string *string;
}

//Need to put all token types here

%token K_INT K_RETURN  //Keywords. These are the ones needed for my minimal lexer / parser
%token K_IF K_ELSE K_CHAR K_FLOAT K_FOR K_WHILE //more keyowords, not needed for minimal parser / lexer
%token O_PLUS O_EQUALS O_MINUS O_ASTR O_DIV //Arithmetic Operators (and pointer I guess). Minimal ones for parser / lexer
%token L_IS_EQUAL L_IS_NOT_EQUAL L_AND L_OR L_NOT //Logical operators
%token B_AND B_OR B_NOT B_XOR B_LSHIFT B_RSHIFT //Bitwise operators
%token P_LHEADER P_RHEADER P_LSQBRAC P_RSQBRAC P_LCURLBRAC P_RCURLBRAC P_LBRACKET P_RBRACKET // punctuators
%token P_LIST_SEPARATOR P_STATEMENT_LABEL P_STATEMENT_END P_VARIABLE_LENGTH_ARGUMENT_LIST P_INCLUDE P_CHAR_CONST //more punctuators, not sure if needed?
%token T_INT T_IDENTIFIER //Types. Minimal ones for parser / lexer


%type <node> PROGRAM FNC_DEC K_INT K_RETURN  TYPE_SPEC  COMPOUND_STATEMENT      

%type <number> T_INT
%type <string> T_IDENTIFIER
%type <expression> EXPRESSION TERM FACTOR MATH_EXPR ASSIGNMENT_EXPR CONSTANT FNC_ID
%type <statement> STATEMENT RETURN_STATEMENT EXPR_STATEMENT STATEMENT_LIST
/*
*/

%start ROOT

%%

ROOT : PROGRAM { g_root = $1; }

 /*	Most of the AST is not implemented. However, by recognizing in advance what
	nodes of the tree we will encounter, it prevents the issue of advancing too
	far and having an unstable foundation
 */
PROGRAM	: FNC_DEC	{$$=$1;}
	/* 	comment out things that we don't need right now
		as they're unneeded for basic parser
	|GLB_VAR
	|FNC_DEC PROGRAM
	|GLB_VAR PROGRAM

	*/
FNC_DEC : TYPE_SPEC FNC_ID P_LBRACKET P_RBRACKET P_LCURLBRAC COMPOUND_STATEMENT P_RCURLBRAC 

TYPE_SPEC : K_INT	/*add other types*/

CONSTANT : T_INT {$$ = new IntLiteral($1);}
	/*okay, so if I understand this correctly, this is where the return that goes into the AST happens*/

FNC_ID : T_IDENTIFIER	{$$ = new Identifier(*$1);}

COMPOUND_STATEMENT : STATEMENT_LIST {$$ = new CompoundStatement($1); std::cerr<<"making a new comp statement"<<std::endl;} // code to the effect of $$ = new StatementList $1
		//and some other stuff
		// ie variable declaration list
		//declaration list followed vby statement list
	//
	
//A statement list has a pointer to the current statement, and a pointer to another statement list / node, yay
STATEMENT_LIST : STATEMENT_LIST STATEMENT {$$ = new StatementList($2,$1);std::cerr<<"New statmentlist, yay"<<std::endl;}// code to the effect of $$.vector.push_back($1)
			|   STATEMENT {$$=$1;std::cerr<<"Bottom of left recursion on Statement list?"<<std::endl;}

STATEMENT : RETURN_STATEMENT {$$=$1;}
			| EXPR_STATEMENT {$$=$1;}

RETURN_STATEMENT : K_RETURN EXPRESSION P_STATEMENT_END { $$ = new ReturnStatement($2); }

EXPR_STATEMENT : EXPRESSION P_STATEMENT_END {$$ = new ExpressionStatement($1);}

EXPRESSION : ASSIGNMENT_EXPR {$$=$1;}
	| MATH_EXPR {$$=$1;}



MATH_EXPR: TERM {$$=$1;}
	| EXPRESSION O_PLUS TERM {$$ = new AddOperator($1, $3);}
	| EXPRESSION O_MINUS TERM {$$ = new SubOperator($1, $3);}

TERM : FACTOR {$$=$1;}
	| TERM O_ASTR FACTOR {$$ = new MulOperator($1, $3);}
	| TERM O_DIV FACTOR {$$ = new DivOperator($1, $3);}

FACTOR : CONSTANT {$$=$1;}
	| FNC_ID {$$=$1;}
	| P_LBRACKET MATH_EXPR P_RBRACKET {$$ = $2;}

//going to need the same BIDMAS architecture used in lab 2

ASSIGNMENT_EXPR : T_IDENTIFIER O_EQUALS EXPRESSION {$$ = new AssignmentExpression(*$1,$3);}


%%
const Node *g_root; // The top of the program is a node. Might be better type?

const Node *parseAST() //This function returns the tree
{
  g_root=0;
  yyparse();
  return g_root;
}
/*need to create more abstraction to separate operators, identifiers, keywords etc....*/
