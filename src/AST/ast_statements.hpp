#ifndef ast_statements_hpp
#define ast_statements_hpp

#include "ast_expressions.hpp"

class Statement : public Node {
	
};

class ExpressionStatement : public Statement {

const Expression *getExpression() const; // I belive this covers the statement x = x+5;

};



#endif
