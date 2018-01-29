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

TChar 			[a-zA-Z]
TDigit			[0-9]

TLeft			[(]
TRight			[)]
TLeftSquare		[[]
TRightSquare	[]]
TLeftCurly		[{]
TRightCurly		[}]


%%

{TChar}+{ fprintf(stderr, "Word : %s\n", yytext); }

%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}

