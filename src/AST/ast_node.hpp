#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>

class Node //template function, contains only virtual functions to overwrite.



typedef const Node *NodePtr;

class Node
{
public:
	virtual ~Node (){} //destructor, may or may not be implemented in subclasses
	{ throw std::runtime_erro("Node not implemented"); }
};

//so top level of abstraction, still kinda confused how this works as surely we need to sort other stuff out before cramming things in here, as in the return types in .y file.
//I get that the node needs to be top level, then expression, then statement.
//btw, you had double included ast.hpp, might have caused errors later so removed it in statements
//for now I will leave as is, but will comment in the stuff DT gave us.
//I need to go over with you what operations we need to include in Node, although I don't think its many if I understand it right

#endif
