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
%tokem
%token T_LBRACKET T_RBRACKET T_LSQUARE T_RSQUARE T_LCURLY T_RCURLY
%token T_KEYW_IF T_KEYW_ELSE
%token T_NUMBER T_VARIABLE

%type <expr> EXPR TERM FACTOR
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%%

ROOT : EXPR { g_root = $1; }
