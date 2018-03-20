#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <vector>


 // a global variab (gasp) to track global variables as they are parsed...
static int myGlobVarbCounter = 0;

static std::vector<std::string> myGlobVarbContainer; // another global variable, allowing for translation from c to python, hopefully

class Node; //template function, contains only virtual functions to overwrite.
class Expression;
class Statement;
class StatementList;
class CompoundStatement;
class Declaration;

typedef const Node *NodePtr; // use NodePtr to point to other nodes
typedef const Expression *ExpressionPtr;
typedef const Statement *StatementPtr;
typedef const StatementList *StatementListPtr;
typedef const CompoundStatement *CompStatementPtr;
typedef const Declaration *DeclPtr;

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

	virtual void translate(std::ostream &dst, int indent) const =0;
	
	virtual void compile(std::ostream &dst) const =0;

	virtual void explore(int & declarations) const =0;
	//if we keep $2 free then all we need is declarations, all other operations can be run internally
};    



#endif
