%code requires{
	#include "ast.hpp"
	#include <string>
	#indlude <cassert>
	extern const Expression *g_root;
	int yylex(void);
	void yyerror(const char *);
}

%union{
	const Expression *expr;
	double number;
	std::string *string;
}

%token	K_INT K_CHAR K_FLOAT K_RETURN 
//%token	K_IF K_ELSE
%token	O_PLUS O_EQUALS
%token	T_INT T_VARIABLE




%type <Node> PROGRAM FNC_DEC T_INT T_VARIABLE K_INT K_CHAR K_FLOAT K_RETURN O_PLUS O_EQUALS TYPE_SPEC FNC_ID COMPOUND_STATEMENT STATEMENT_LIST STATEMENT RETURN_STATEMENT EXPRESSION CONSTANT
%start ROOT
%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM : FNC_DECL	{ $$ = $1; }
	//|other shit
	//

FNC_DECL : TYPE_SPEC FNC_ID "(" ")" COMPOUND_STATEMENT

TYPE_SPEC : K_INT	{ $$ = $1; }
	
TYPE_VAR : T_INT	
	/*okay, so if I understand this correctly, this is where the return that goes into the AST happens*/ 

FNC_ID : T_VARIABLE

COMPOUND_STATEMENT : "{" STATEMENT_LIST "}"
		//and some other stuff

STATEMENT_LIST : STATEMENT	{ $$ = $1; }
		| STATMENT STATEMENT_LIST

STATEMENT : RETURN_STATEMENT	{ $$ = $1; }

RETURN_STATEMENT : K_RETURN EXPRESSION ";"

EXPRESSION : TYPE_VAR	{ $$ = $1; }

%%
const Node *g_root; // The top of the program is a node. Might be better type?

const Node *parseAST() //This function returns the tree
{
  g_root=0;
  yyparse();
  return g_root;
}


/*need to create more abstraction to separate operators, identifiers, keywords etc....*/
/*END OF WHAT K DID 26/2/18*/






NC_DEC	:  TYPE_SPEC FNC_NAME "(" ")"COMPOUND_STATEMENT // two types of function declaration in basic parser/lexer
	//| TYPE_SPEC FNC_NAME "("FNC_ARGS_LIST")"COMPOUND_STATEMENT // one with type, name, arguments and body, and one without the arguments
	//more complex fnc_dec might have a declaration in one place, and a definition in an other. This is a longer term goal to support

TYPE_SPEC : T_INT // only type required for 5 basic programs

FNC_NAME : IDENTIFIER 

IDENTIFIER : T_VARIABLE

//FNC_ARGS_LIST : /* stuff */

COMPOUND_STATEMENT : "{" DECLARATION_LIST STATEMENT_LIST "}"
		| "{" STATEMENT_LIST "}"

DECLARATION_LIST : DECLARATION
		 | DECLARATION_LIST DECLARATION

DECLARATION	: DECL_SPEC DECL_CO
	 
STATEMENT_LIST : STATEMENT STATEMENT_LIST

STATEMENT : EXPRESSION_STATEMENT
	//COMPUND_STATEMENT
	RETURN_STATEMENT

RETURN_STATEMENT : K_RETURN ";"
		 | K_RETURN EXPRESSION ";"

EXPRESSION_STATEMENT : EXPRESSION ";"

EXPRESSION : ASSIGNMENT_EXPRESSION
	//EXPRESSION, ASSIGNMENT_EXPRESSION // this is for doing stuff like "int x, y;" i think. Not needed
ASSIGNMENT_EXPRESSION : IDENTIFIER	

//GLB_VAR	: TYPE IDENTIFIER




