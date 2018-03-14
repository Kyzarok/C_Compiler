#ifndef ast_declarations_hpp
#define ast_declarations_hpp

#include "ast_node.hpp"
#include "ast_statements.hpp"
#include "ast_expressions.hpp"
#include <string>


class FunctionDecl : public Node {
	protected:
		std::string ret_type; // string containing what the return type is
		std::string fnc_ID; // string containing the function id
		NodePtr body; // point to the compount Statement containing the body
		NodePtr args; // pointer to a parameter list
		bool isMain; // we need to be able to create a valid main entry point. As such, a boolean tracking if this is the main function
	public: 
		//constructor without arguments list
		FunctionDecl(std::string _ret, std::string _ID, NodePtr _body) : 
			ret_type(_ret),
			fnc_ID(_ID),
			body(_body),
			args(NULL)
		
			{
				std::cerr<<"Constructor for func decl"<<std::endl;
				if(fnc_ID=="main"){
					isMain=true;
					std::cerr<<"Just made the main"<<std::endl;
				}
				else{
					isMain=false;
				}

			}
		//constructor with arguments list

		FunctionDecl(std::string _ret, std::string _ID, NodePtr _body, NodePtr _args) : 
			ret_type(_ret),
			fnc_ID(_ID),
			body(_body),
			args(_args)
			
		{
			std::cerr<<"Constructor for func decl with parameters"<<std::endl;
			if(fnc_ID=="main"){
				isMain=true;
				std::cerr<<"Just made the main"<<std::endl;
			}
			else{
				isMain=false;
			}
			
		}
		
		virtual void print(std::ostream &dst) const override {
			std::cerr<<"I am trying to print the func declr"<<std::endl;
			dst<<ret_type;
			dst<<" ";
			dst<<fnc_ID;
			dst<<" ( ";
			dst<<" ) ";
			dst<<std::endl;
			dst<<"{"<<std::endl;
			body->print(dst);
			dst<<"}";
		}

		virtual void translate(std::ostream &dst, int indent) const override {
		
			std::cerr<<"_____dec1_____"<<std::endl;
			dst<<"def "<<fnc_ID<<"():"<<std::endl;
			std::cerr<<"_____dec2_____"<<std::endl;
			if(args!=NULL){
				args->translate(dst, indent);
			}
			std::cerr<<"_____dec3_____"<<std::endl;
			body->translate(dst,indent+4);
			std::cerr<<"_____dec4_____"<<std::endl;
			
		}

};

class Parameter : public Node{

	protected:
		std::string type;
		std::string id;
		//ExpresstionPtr value; // technically this is valid eg int f(int x=2){return x;} is a valid function, returning 2 or the input. Not going to be supported.
	public:
		Parameter(std::string _type, std::string _id) : type(_type), id(_id){} //constructor
		
		virtual void translate(std::ostream &dst, int indent) const override {
			dst<<type;
			dst<<" ";
			dst<<id;
				
		}

};

class ParamaterList : public Node{ // list of function paramaters

	protected:
		NodePtr current; // pointer to current Parameter, of type node
		NodePtr next; // pointer to next Parameter list, of type node too
	public:
		ParamaterList(NodePtr _current) : current(_current), next(NULL){} // constructor with no next
		ParamaterList(NodePtr _current, NodePtr _next) : current(_current), next(_next){} // constructor with next
		
		virtual void translate(std::ostream &dst, int indent) const override {
			std::cerr<<"_____paramLIST1_____"<<std::endl;
			if(next!=NULL){
				dst<<", ";
				next->translate(dst,indent);
			}
			std::cerr<<"_____paramLIST2_____"<<std::endl;
			current->translate(dst,indent);
			std::cerr<<"_____paramLIST3_____"<<std::endl;
				
		}


};

#endif








