#ifndef ast_statements_hpp
#define ast_statements_hpp

#include "ast_expressions.hpp"
#include "ast_node.hpp"

class Statement : public Node {
	
};

class ExpressionStatement : public Statement {

const Expression *getExpression() const; // I belive this covers the statement x = x+5;
//TODO add functionality to this class
};

//TODO add more statments, eg Return statement, if statement

//TODO make Compound Statement and Statement List work


#endif
