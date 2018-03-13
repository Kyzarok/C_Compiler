#ifndef ast_expressions_hpp
#define ast_expressions_hpp

#include "ast_node.hpp"

class Expression : public Node {

};

typedef const Expression *ExpressionPtr;

class AssignmentExpression : public Expression{ // ie for EXPRESSION = EXPRESSION	
	protected:
		std::string target; // has a left expressions
		ExpressionPtr value; // to be assigned to right expression
		
	public:
		AssignmentExpression(std::string _target, ExpressionPtr _value) : target(_target), value(_value){}
		const Expression *getvalue() const;
		virtual void print(std::ostream &dst) const override {
			dst<<target;
			dst << " = ";
			value->print(dst);
		}
		virtual void translate(std::ostream &dst, int indent) const override {
			dst<<target;
			dst << " = ( ";
			value->translate(dst,indent);
			dst << " )";
		}
};

class Operator : public Expression {
protected:
	NodePtr left;
	NodePtr right;
	
public:
	Operator(NodePtr _left, NodePtr _right) : left(_left), right(_right){}
	virtual const char *getOpcode() const = 0;
	NodePtr getLeft() const { return left; }
	NodePtr getRight() const { return right; }
};

//Start of Arithmetic Operators

class AddOperator : public Operator { 
protected:
	virtual const char *getOpcode() const override { return "+"; }
public:
	AddOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return vl + vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" + ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" + ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class SubOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "-"; }
public:
	SubOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return vl - vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" - ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" - ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class MulOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "*"; }
public:
	MulOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return vl*vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" * ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" * ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class DivOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "/"; }
public:
	DivOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return vl/vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" / ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" / ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

//End of Arithmetic Operators
//Start of Logical Operators

class EqualToOperator : public Operator {	//need to go over how mapping works with booleans
protected:
	virtual const char *getOpcode() const override { return "=="; }
public:
	EqualToOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if(vl == vr){
			return 1;
		}
		else{
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" == ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" == ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class NotEqualOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "!="; }
public:
	NotEqualOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if(vl != vr){
			return 1;
		}
		else{
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" != ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" != ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class LAndOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "&&"; }
public:
	LAndOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if(vl && vr){
			return 1;
		}
		else{
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" && ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" AND ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class LOrOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "||"; }
public:
	LOrOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if(vl || vr){
			return 1;
		}
		else{
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" || ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" OR ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class NotOperator : public Operator {	// a not operator only requires RHS of !
protected:
	virtual const char *getOpcode() const override { return "!"; }
public:
	NotOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		//double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if(!vr){
			return 1;
		}
		else{
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" ! ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" NOT ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class GThanOperator : public Operator {	// a not operator only requires RHS of !
protected:
	virtual const char *getOpcode() const override { return "!"; }
public:
	GThanOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override {
		//double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if (!vr) {
			return 1;
		}
		else {
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst << " > ";
		right->print(dst);
		dst << " )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst << "( ";
		left->translate(dst,indent);
		dst << " > ";
		right->translate(dst,indent);
		dst << " )";
	}
};

class LThanOperator : public Operator {	// a not operator only requires RHS of !
protected:
	virtual const char *getOpcode() const override { return "!"; }
public:
	LThanOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override {
		//double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if (!vr) {
			return 1;
		}
		else {
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst << " < ";
		right->print(dst);
		dst << " )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst << "( ";
		left->translate(dst,indent);
		dst << " < ";
		right->translate(dst,indent);
		dst << " )";
	}
};

class GEThanOperator : public Operator {	// a not operator only requires RHS of !
protected:
	virtual const char *getOpcode() const override { return "!"; }
public:
	GEThanOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override {
		//double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if (!vr) {
			return 1;
		}
		else {
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst << " >= ";
		right->print(dst);
		dst << " )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst << "( ";
		left->translate(dst,indent);
		dst << " >= ";
		right->translate(dst,indent);
		dst << " )";
	}
};

class LEThanOperator : public Operator {	// a not operator only requires RHS of !
protected:
	virtual const char *getOpcode() const override { return "!"; }
public:
	LEThanOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override {
		//double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		if (!vr) {
			return 1;
		}
		else {
			return 0;
		}
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst << " <= ";
		right->print(dst);
		dst << " )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst << "( ";
		left->translate(dst,indent);
		dst << " <= ";
		right->translate(dst,indent);
		dst << " )";
	}
};
//End of Logical Operators
//Start of Bitwise Operators

class BAndOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "&"; }
public:
	BAndOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return (int)vl & (int)vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" & ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" & ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class BOrOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "|"; }
public:
	BOrOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return (int)vl | (int)vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" | ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" | ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class BNotOperator : public Operator {	//not would only intake RHS
protected:
	virtual const char *getOpcode() const override { return "~"; }
public:
	BNotOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		//double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return ~(int)vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" ~ ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" ~ ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class XorOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "^"; }
public:
	XorOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return (int)vl ^ (int)vr;		//Dont't know bitwise or in C++
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" ^ ";
		right->print(dst);
		dst<<" )";
	}
};

class LShiftOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return "<<"; }
public:
	LShiftOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return (int)vl << (int)vr;
	}
	virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" << ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" << ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

class RShiftOperator : public Operator {
protected:
	virtual const char *getOpcode() const override { return ">>"; }
public:
	RShiftOperator(NodePtr _left, NodePtr _right) : Operator(_left, _right) {}
	virtual double evaluate(const std::map<std::string, double> &bindings) const override{
		double vl = left->evaluate(bindings);
		double vr = right->evaluate(bindings);
		return (int)vl >> (int)vr;
	}virtual void print(std::ostream &dst) const override {
		dst << "( ";
		left->print(dst);
		dst<<" >> ";
		right->print(dst);
		dst<<" )";
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		dst<<"( ";
		left->translate(dst,indent);
		dst<<" >> ";
		right->translate(dst,indent);
		dst<<" )";
	}
};

#endif
