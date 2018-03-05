#ifndef ast_expressions_hpp
#define ast_expressions_hpp

#include "ast_node.hpp"

class Expression : public Node {

};



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

class Operator : public Expression {
protected:
	NodePtr left;
	NodePtr right;
	Operator(NodePtr _left, NodePtr _right) : left(_left), right(_right){}
public:
	virtual const char *getOpcode() const = 0;
	NodePtr getLeft() const { return left; }
	NodePtr getRight() const { return right; }
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" ";
		dst<<getOpcode();
		dst<<" ";
		right->print(dst);
		dst<<" )";
	}
};

 // generic class for all expressions. May add functions to this later so important to separate

 //I am unsure what expressions we actually need is the issue.
 
class BinaryExpression : public Expression { // ie for stuff like x+3

public:
	const Expression *getLeft() const;
	const Expression *getRight() const;
	std::string getOperator() const;

};

class Identifier : public Expression { // ie for stuff like x+3

public:
	const Expression *getLeft() const;
	const Expression *getRight() const;
	std::string getOperator() const;

};


//TODO Add AST nodes for operators, AST nodes for literals and variables
//added =, +, -, *, /, ==, !=, &&, ||, !, &, |, ~, ^, <<, >>
//when it comes to Operators, Arithmetic, logical and bitwise all require the same root of Operator
//this means that they can get both Expressions on either side of the Operator
//I'd like to go over making a separation between Arith, Log and Bit so that we can use OOP
//it should make sorting stuff out easier as we can classify them all under Expression: Operator


//Start of Arithmetic Operators
class EqualsOperator : public Operator { // ie for stuff like x+3
protected:
	virtual const char *getOpcode() const override { return "="; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return //need to figure out what needs to be returned here as not sure if equals
	}
};
//Equals needs to be different, its probably just vl = vr but want to make sure we go through this together first

class AddOperator : public Operator { 
protected:
	virtual const char *getOpcode() const override { return "+"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl + vr;
	}
};

class SubOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "-"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl - vr;
	}
};

class MulOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "*"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl*vr;
	}
};

class DivOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "/"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl/vr;
	}
};
//End of Arithmetic Operators
//Start of Logical Operators

class EqualToOperator : public Operator {	//need to go over how mapping works with booleans
protected:
	virtual const char *getOpcode() const override { return "=="; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		if(vl == vr){
			return 1;
		}
		else{
			return 0;
		}
	}
};

class NotEqualOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "!="; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		if(vl != vr){
			return 1;
		}
		else{
			return 0;
		}
	}
};

class LAndOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "&&"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		if(vl && vr){
			return 1;
		}
		else{
			return 0;
		}
	}
};

class LOrOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "||"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		if(vl || vr){
			return 1;
		}
		else{
			return 0;
		}
	}
};

class NotOperator : public Operator {	// a not operator only requires RHS of !
protected:
	virtual const char *getOpcode() const override { return "!"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		//double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		if(!vr){
			return 1;
		}
		else{
			return 0;
		}
	}
};

//End of Logical Operators
//Start of Bitwise Operators

class BAndOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "&"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl & vr;
	}
};

class BOrOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "|"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl | vr;
	}
};

class BNotOperator : public Operator {	//not would only intake RHS
protected:
	virtual const char *getOpcode() const override { return "~"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		//double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return ~vr;
	}
};

class XorOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "^"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl && vr;		//Dont't know bitwise or in C++
	}
};

class LShiftOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "<<"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl << vr;
	}
};

class RShiftOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return ">>"; }
public:
	EqualsOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluayte(bindings);
		return vl >> vr;
	}
};

#endif ast_expressions_hpp
