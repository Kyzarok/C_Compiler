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



class Variable : public Node {	//If we can figure out how Variable works then we can tie it in with EqualsOperator so that we know what to return for it
	protected:
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

class Identifier : public Node {

};

class IntLiteral : public Node {
	private:
    	int value;
	public:
    	IntLiteral(int _value) : value(_value) {}
    	int getValue() const { return value; }
    	virtual void print(std::ostream &dst) const override {
     	   dst<<value;
    	}
    	virtual double evaluate(const std::map<std::string,double> &bindings) const override {
        	return value;
    	}
};

class StringLiteral : public Node {
	private:
		std::string str;
	public:
		StringLiteral(std::string _str) : str(_str) {}
		const std::string getStr() const { return str; }
		virtual void print(std::ostream &dst) const override {
			dst << str;
		}
		virtual double evaluate(const std::map<std::string, double> &bindings) const override {
			return str;
		}
};
	
class CharLiteral : public Node {
	private:
		char character;
	public:
		CharLiteral(char _character) : character(_character) {}
		const char getChar() const { return character; }
		virtual void print(std::ostream &dst) const override {
			dst << character;
		}
		virtual double evaluate(const std::map<std::string, double> &bindings) const override {
			return character;
		}
};

class Float : public Node { // not priority, handling floats hard
	private:
		float flo;
	public:
		Float(float _flo) : flo(_flo) {}
		const float getFloat() const { return flo; }
		virtual void print(std::ostream &dst) const override {
			dst << flo;
		}
		virtual double evaluate(const std::map<std::string, double> &bindings) const override {
			return flo;
		}
};

#endif
