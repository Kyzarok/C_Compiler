#ifndef ast_declarations_hpp
#define ast_declarations_hpp

#include "ast_node.hpp"
#include "ast_statements.hpp"

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
	
	protected:
		std::string ret_type; // string containing what the return type is
		std::string fnc_ID; // string containing the function id
		CompStatementPtr body; // point to the compount Statement containing the body
		//ParamListPtr paramlist; // TODO implement this type / node, is a pointer to the parameter list
		bool isMain; // we need to be able to create a valid main entry point. As such, a boolean tracking if this is the main function
		bool takesArgument; // tracks whether we care about arguments. Might not be needed
	public: 
		//constructor without arguments list
		FunctionDecl(std::string _ret, std::string _ID, CompStatementPtr _body) : 
			ret_type(_ret),
			fnc_ID(_ID),
			body(_body)
			{
				if(fnc_ID=="main"{
					isMain=true;
				}
				else{
					isMain=false;
				}
				takesArgument=false;
			}
		//constructor with arguments list
		//TODO
		//FunctionDecl(std::string _ret, std::string _ID, CompStatementPtr _body, SomeType _args) : 
		
		virtual void print(std::ostream &dst) const override {
			dst<<ret_type;
			dst<<" ";
			dst<<fnc_ID;
			dst<<" ( ";
			/*if(takesArgument){
				paramlist->print(dst);
			}*/
			dst<<" ) ";
			body->print(dst);
		}

};
//unsure if needed?
/*class VariableDecl : public Node{

*/

#endif
