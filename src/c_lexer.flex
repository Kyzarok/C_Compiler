%option noyywrap

%{
/*
Section of c code to be embedded at top of generated code. 
Put includes, definitions, etc up here
*/

#include <stdlib.h>
#include "c_lexer.hpp"

// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}

T_Char 			[a-zA-Z]
T_Digit			[0-9]

T_Left			[(]
T_Right			[)]
T_LeftSquare	[[]
T_RightSquare	[]]
T_LeftCurly		[{]
T_RightCurly	[}]

T_Plus			[+]
T_Minus			[-]
T_Star			[*]
T_Equals			[=]
T_ForwardSlash	[/]
T_BackSlash		[\]
T_LessThan		[<]
T_GreatThan		[>]



%%

{TDigit}+	{ fprintf(stderr, "Integer : %s\n", yytext); }
{TChar}+		{ fprintf(stderr, "Word : %s\n", yytext); }

%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}

