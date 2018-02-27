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
	OperatorCode getOperator() const; // will need to somewhere define a type of Operator code

};

//TODO Add AST nodes for operators, AST nodes for literals and variables



//TODO Add other types of expression

class AssignmentExpression : public Expression{ // ie for EXPRESSION = EXPRESSION
	/*rough code, will need hashing out
	
	protected:
		ExpressionPtr Left; // has a left expressions
		ExpressionPtr Right; // to be assigned to right expression
		
	public:
		AssignmentExpression(ExpressionPtr _left, ExpressionPtr _right)
			: left(_left)
			, right(_right)
		{}
		
		
		const Expression *getLeft() const;
		const Expression *getRight() const;
	
	*/
	
}
#endif ast_expressions_hpp
