#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

class Node //template function, contains only virtual functions to overwrite.



typedef const Node *NodePtr; // use NodePtr to point to other nodes

class Node
{
public:
	
	virtual ~Node (){} //destructor, may or may not be implemented in subclasses
	
	//copied the following functions from DT's examples, will need work in other places too
	
	virtual void print(std::ostream &dst) const =0;

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const
    { throw std::runtime_error("Not implemented."); }
    
    /* Additional functions to add
    virtual const translate(std::ostream &dst) const=0; // function to be overwritten by subclasses. Will output translated python code over stdout - send to output file.
    
    virtual const compile (std::ostream &dst) const =0; // function to be overwritten by subclasses. Will output compiled MIPS assembly over stdout - send to output file.
    */
};

//so top level of abstraction, still kinda confused how this works as surely we need to sort other stuff out before cramming things in here, as in the return types in .y file.
//I get that the node needs to be top level, then expression, then statement.
//btw, you had double included ast.hpp, might have caused errors later so removed it in statements
//for now I will leave as is, but will comment in the stuff DT gave us.
//I need to go over with you what operations we need to include in Node, although I don't think its many if I understand it right

#endif
