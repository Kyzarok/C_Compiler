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
 /*keywords have a very different meaning in TokenJunk, but I'll leave as is and discuss tmr 27/2/18*/
"int"		{return(K_INT);}
"char"		{return(K_CHAR);}
"float"		{return(K_FLOAT);}
"return"	{return(K_RETURN);}
"if"		{return(K_IF);}
"else"		{return(K_ELSE);}
"for"		{return(K_FOR);}
"while"		{return(K_WHILE);}
	/*"enumerator"		{return(K_ENUM);}	NO IDEA WHAT THIS DOES*/ 


 /*Arithmetic operator (and some point stuff we'll probably never implement)*/

"+"	{return(O_PLUS);}
"=" 	{return(O_EQUALS);}
"-" 	{return(O_MINUS);}
"*"	{return(O_ASTR;}	//called as such to avoid issue of * being used for pointers, dereferencing, and multiplication
"/" 	{return(O_DIV);}

 /*Logical operator*/

"==" 	{return(L_IS_EQUAL);}
"!=" 	{return(L_IS_NOT_EQUAL);}
"&&" 	{return(L_AND);}
"||" 	{return(L_OR);}
"!" 	{return(L_NOT);}

 /*Bitwise operator*/

"&" 	{return(B_AND);}
"|" 	{return(B_OR);}
"~" 	{return(B_NOT);}
"^" 	{return(B_XOR);}
"<<" 	{return(B_LSHIFT);}
">>" 	{return(B_RSHIFT);}

 /*Punctuators*/

"<" 	{return(P_LHEADER);}
">" 	{return(P_RHEADER);}
"[" 	{return(P_LSQBRAC);}
"]" 	{return(P_RSQBRAC);}
"{" 	{return(P_LCURLBRAC);}
"}" 	{return(P_RCURLBRAC);}
"(" 	{return(P_LBRACKET);}
")" 	{return(P_RBRACKET);}
	/* SSOOOO slight issue, the symbol for pointer needs * but matches with times as well so we need some level of abstraction to sort it. Solved by renaming O_TIMES to O_ASTR, handles all 3 cases*/
"," 	{return(P_LIST_SEPARATOR);}
":" 	{return(P_STATEMENT_LABEL);}
";" 	{return(P_STATEMENT_END);}
"..." 	{return(P_VARIABLE_LENGTH_ARGUMENT_LIST);}
"#" 	{return(P_INCLUDE);}
"'" 	{return(P_CHAR_CONST);} //not sure this is right?

"/*"[.]*"*/" {} // strip comments
"//"[^\n]* {} //strip comments

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

