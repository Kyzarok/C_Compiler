#ifndef ast_expressions_hpp
#define ast_expressions_hpp

#include "ast_node.hpp"

class Expression : public Node {

};

 // generic class for all expressions. May add functions to this later so important to separate

 //I am unsure what expressions we actually need is the issue.
 
class BinaryExpression : public Expression { // ie for stuff like x+3

public:
	const Expression *getLeft() const;
	const Expression *getRight() const;
	std::string getOperator() const;

};

//TODO Add AST nodes for operators, AST nodes for literals and variables



//TODO Add other types of expression

class AssignmentExpression : public Expression{ // ie for EXPRESSION = EXPRESSION

	
	protected:
		ExpressionPtr target; // has a left expressions
		ExpressionPtr value; // to be assigned to right expression
		
	public:
		AssignmentExpression(ExpressionPtr _target, ExpressionPtr _value) // constructor
			: target(_target)
			, value(_value)
		{}
		
		
		const Expression *gettarget() const;
		const Expression *getvalue() const;
	

	
};
#endif ast_expressions_hpp
