#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include "ast_node.hpp"

class LitInteger : public Expression // an integer literal

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

}

//TODO Add more primitives, eg char, string literal, variables. I think they go here?

#endif
