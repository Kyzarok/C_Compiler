#ifndef c_lexer.hpp
#define c_lexer.hpp


#include <string>

enum TokenType{
    None		= 0, // This indicates there are no more tokens
    Int			= 1, // token code 
    Char		= 2,
    Var			= 3,
    Operator	= 4,
    Keyword		= 5, // ie stuff like for, if etc. May later be split into additonal cases
    Identifier	 // ie variable names
    
    // THIS IS A WIP list, will need to edit
    
    
};

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
