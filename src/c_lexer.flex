%option noyywrap

%{
/*
Section of c code to be embedded at top of generated code. 
Put includes, definitions, etc up here
*/

#include <stdlib.h>
#include "c_parser.tab.hpp"
#include <string>

// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}

T_Char 			[a-zA-Z]
T_Digit			[0-9]


%%

 /*keywords*/

"int"	{return(K_INT);}
"return" {return(K_RETURN);}

 /*operators*/

"+"	{return(O_PLUS);}
"=" {return(O_EQUALS);}

 /*types*/

{T_Digit}+ { yylval.number=strtod(yytext, 0); return T_INT; } 
{T_Char}({T_Char}|{T_Digit})* { yylval.string=new std::string(yytext); return T_VARIABLE; } //variable

%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}

