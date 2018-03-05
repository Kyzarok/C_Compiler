#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include "ast_node.hpp"

/* class LitInteger : public Expression // an integer literal

{
	private:
		int value; // the value of the integer

	public:
	Number(int _value) // constructor with initialiser
		: value(_value)
		{}
	double getValue() const{ // getter
		return value;
	}

} */

//TODO Add more primitives, eg char, string literal, variables. I think they go here?
//They do
//Got code from DT's primitives example, I think that we should just use Number instead of LitInteger unless there's some special reason we're using it that I'm not aware of

class Variable : public Expression {
private:
    std::string id;
public:
    Variable(const std::string &_id) : id(_id) {}
    const std::string getId() const { return id; }
	virtual void print(std::ostream &dst) const override {
        dst<<id;
    }
    virtual double evaluate(const std::map<std::string,double> &bindings) const override{
        return bindings.at(id);
    }    
};

class Number : public Expression {
private:
    double value;
public:
    Number(double _value) : value(_value) {}
    double getValue() const { return value; }
    virtual void print(std::ostream &dst) const override {
        dst<<value;
    }
    virtual double evaluate(const std::map<std::string,double> &bindings) const override {
        return value;
    }
};


#endif
