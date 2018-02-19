#ifndef c_lexer.hpp
#define c_lexer.hpp


#include <string>


//This can be auto generated from bison. I think this entire file isn't needed anymore
/*enum TokenType{
    None		= 0, // This indicates there are no more tokens
    Int			= 1, // token code. Techically a constant 
    Char		= 2, //Also constant
    Float		= 3, //Also constant
    Enumerator	= 4, //A type of constant. No clue what it is though, low priority, look up later
    //Operator 	= , // I am aware of 46 different operator types. How do we plan to handle this? Split between arithmetic and logical?
	OperatorArithmetic	= 5, //stuff like +, - 
	OperatorLogical		= 6, //stuff like !=, ||
	OperatorBitwise		= 7, //stuff like |, &
    Keyword		= 8, // ie stuff like for, if etc. May later be split into additonal cases
    Identifier	= 9, // ie variable names
    Punctuator	= 10, // looking at a list of punctuators: 	
		<> 	Header name
		[] 	Array delimiter
		{} 	Initializer list, function body, or compound statement delimiter
		()	Function parameter list delimiter; also used in expression grouping
		*	Pointer declaration
		,	Argument list separator
		
															
    StringLiteral
	
	
	
    
    // THIS IS A WIP list, will need to edit
    
    
};*/


union TokenValue{
    double numberValue;
    std::string *wordValue;
};

// This is a global variable used to move the
// attribute value from the lexer back to the
// main program.
// By convention it is called yylval, as that is
// the name that will be automatially generated
// by Bison (see next lab).
extern TokenValue yylval;

// This is the lexer function defined by flex. Each
// time it is called, a token type value will be
// returned.
extern int yylex();

#endif
