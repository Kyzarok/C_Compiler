#ifndef ast_varb_declarations_hpp
#define ast_varb_declarations_hpp

#include <string>
#include <iostream> 
#include <vector>

extern int myGlobVarbCounter;

extern std::vector<std::string> myGlobVarbContainer;

class Declaration : public Node{

};

class DeclLocal : public Declaration{

	protected: 
		std::string type;
		std::string var_id;
		ExpressionPtr value;
	
	public:
		DeclLocal(std::string _type, std::string _var_id) : //constructor with no value assignment
			type(_type),
			var_id(_var_id),
			value(NULL)
			{std::cerr<<"New Declaration with no value assigned"<<std::endl;}
		DeclLocal(std::string _type, std::string _var_id, ExpressionPtr _value) : //constructor with variable assignment
			type(_type),
			var_id(_var_id),
			value(_value)
			{std::cerr<<"New Declaration with value assigned"<<std::endl;}
			
		virtual void print(std::ostream &dst) const override {
			dst<<type;
			dst << " ";
			dst << var_id;
			dst<<" ";
			if(value!=NULL){
				dst<<"= ";
				value->print(dst);
			}
		}
		virtual void translate(std::ostream &dst, int indent) const override {
			for(int i=0; i<indent;i++){//Shold make a function / member function, quick hack for now
				dst<<" ";
			}	
			dst<<var_id;
			dst<<" = ";
			if(value!=NULL){
				value ->translate(dst,indent);
			}
			else{
				dst<<"0";
			}
			dst<<std::endl;
		}
};

typedef const Declaration *DeclPtr;

class DeclList : public Declaration{

	protected:
		DeclPtr current; // the current declaration
		DeclPtr next; // the next declaration / declaration list
	
	public:
		//constructor with no next list
		DeclList(DeclPtr _current) : current(_current), next(NULL){
			std::cerr<<"Constructed DeclList with no next Decl"<<std::endl;
		}
		//constructor with next list
		DeclList(DeclPtr _current, DeclPtr _next) : current(_current), next(_next){
			std::cerr<<"Constructed DeclList with next Decl"<<std::endl;
		}
		virtual void print(std::ostream &dst) const override {
			std::cerr<<"Print on decl list got called"<<std::endl;
			if(next!=NULL){
				next->print(dst);
			}
			current->print(dst);
			std::cerr<<"Print on declaration list successfully finished"<<std::endl;
		}
		virtual void translate(std::ostream &dst, int indent) const override {
			std::cerr<<"_____declLIST1_____"<<std::endl;
			if(next!=NULL){
				next->translate(dst,indent);
			}
			std::cerr<<"_____declLIST2_____"<<std::endl;
			current->translate(dst,indent);
			std::cerr<<"_____declLIST3_____"<<std::endl;
		}
};

class DeclGlobal : public Node{ 
	protected:
		std::string type;
		std::string var_id;
		ExpressionPtr value;
	public:
		DeclGlobal(std::string _type, std::string _var_id) : 
			type(_type),
			var_id(_var_id),
			value(NULL) {
			
			std::cerr<<"Behold, a global with no initial value. Increment the counter and store the relevant details!"<<std::endl;
			myGlobVarbCounter++;
			myGlobVarbContainer.push_back(type);
			myGlobVarbContainer.push_back(var_id);
			std::cerr<<"The global constructor hath finished!"<<std::endl;
		}
		DeclGlobal(std::string _type, std::string _var_id, ExpressionPtr _value) :
			type(_type),
			var_id(_var_id),
			value(_value) {
			
			std::cerr<<"Behold, a global with an initial value. Increment the counter and store the relevant details!"<<std::endl;
			myGlobVarbCounter++;
			myGlobVarbContainer.push_back(type);
			myGlobVarbContainer.push_back(var_id);
			std::cerr<<"The global constructor hath finished!"<<std::endl;
		}
		virtual void print(std::ostream &dst) const override {
			dst<<type;
			dst << " ";
			dst << var_id;
			dst<<" ";
			if(value!=NULL){
				dst<<"= ";
				value->print(dst);
			}
		}
		virtual void translate(std::ostream &dst, int indent) const override {
			for(int i=0; i<indent;i++){//Shold make a function / member function, quick hack for now
				dst<<" ";
			}	
			dst<<var_id;
			dst<<" = ";
			if(value!=NULL){
				value ->translate(dst,indent);
			}
			else{
				dst<<"0";
			}
			dst<<std::endl;
		}

};

#endif
