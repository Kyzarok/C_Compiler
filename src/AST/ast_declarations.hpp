#ifndef ast_declarations_hpp
#define ast_declarations_hpp

#include "ast_node.hpp"

class FunctionDecl : public Node{


/*
	protected:
		Type_Spec ret_type;	//return type should really be a string for max flexiblity rn
		std::string fnc_ID;	//use T_IDENTIFIER as in flex and .y
		CompoundStatement body; // probably should be a pointer to a compound statement? If we remove Compound Statement, this changes
		//just a pointer to the body, no complex internal stuff needed
		//someType ArgsList, pointer to ArgList, this is relevant when f() is not empty
		//bool isMain; // needed to identify if function is the main for creating valid start point
		
	public:
		// constructor without args list
		// constructor with args list -> case where f() so no arg list
*/
	

}
//unsure if needed?
/*class VariableDecl : public Node{

*/

#endif
