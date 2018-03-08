#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include "ast_node.hpp"
#include "ast_expressions.hpp"

class Identifier : public Expression {	//If we can figure out how Variable works then we can tie it in with EqualsOperator so that we know what to return for it
	protected:
		std::string id;
	public:
   	 	Identifier(const std::string &_id) : id(_id) {}
    	const std::string getId() const { return id; }
		virtual void print(std::ostream &dst) const override {
        	dst<<id;
    	}
    	virtual double evaluate(const std::map<std::string,double> &bindings) const override{
       		return bindings.at(id);
    	}    
		virtual void translate(std::ostream &dst) const override {
			id;
		}
};

class IntLiteral : public Expression {
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
		virtual void translate(std::ostream &dst) const override {
			return value;
		}
};


//NON PRIORITY
/*class StringLiteral : public Expression {
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
	
class CharLiteral : public Expression {
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

class Float : public Expression { // not priority, handling floats hard
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
};*/

#endif
