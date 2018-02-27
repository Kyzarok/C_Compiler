#ifndef ast_expressions_hpp
#define ast_expressions_hpp

#include "ast_node.hpp"

class Expression : public Node {
protected:
	NodePtr arg;
	Expression(NodePtr _arg) :arg(_arg) {} //literally just verbatim of DT's stuff hope its right
public:
	virtual const char * getExpression() const = 0;
	NodePtr getArg() const { return arg; }
	virtual void print(std::ostream &dst) const override {
		dst << getExpression() << "( ";
		arg->print(dst);
		dst << " )";
	}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override {
		throw std::runtime_error("Expression is not implemented");
	}
}; // generic class for all expressions. May add functions to this later so important to separate

/*class BinaryExpression : public Expression { // ie for stuff like x+3

public:
	const Expression *getLeft() const;
	const Expression *getRight() const;
	OperatorCode getOperator() const; // will need to somewhere define a type of Operator code

};

*/


#endif ast_expressions_hpp
