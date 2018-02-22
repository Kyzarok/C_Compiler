#ifndef ast_expressions_hpp
#define ast_expressions_hpp

#include "ast_node.hpp"

class Expression : public Node {}; // generic class for all expressions. May add functions to this later so important to separate

class BinaryExpression : public Expression { // ie for stuff like x+3

public:
	const Expression *getLeft() const;
	const Expression *getRight() const;
	OperatorCode getOperator() const; // will need to somewhere define a type of Operator code

};

class 


#endif ast_expressions_hpp
