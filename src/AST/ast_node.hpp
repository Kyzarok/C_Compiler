#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

class Node; //template function, contains only virtual functions to overwrite.

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



#endif
