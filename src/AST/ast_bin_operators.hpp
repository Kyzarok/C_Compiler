#ifndef ast_bin_operators_hpp
#define ast_bin_operators_hpp

/*
Not actually sure if this is a needed file / where it goes. I'm sort of confused about the grammar tbh
which is a shame as its sort of been made by me.
*/

#include <iostream>
#include "ast_node.hpp"
#include <string>

/*
If the file is needed, then it will contain Operator as a largely virtual class used to define
other classes such as addOperator.

I _think_ it is needed though?
*/

class Operators
    : public Node
{
protected:
    ExpressionPtr left;
    ExpressionPtr right;

   
public:
	 Operator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
	
    virtual const char *getOpcode() const =0;

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" ";
        dst<<getOpcode();
        dst<<" ";
        right->print(dst);
        dst<<" )";
    }
};



#endif
