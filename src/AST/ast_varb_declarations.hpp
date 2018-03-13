#ifndef ast_varb_declarations_hpp
#define ast_varb_declarations_hpp

#include "ast_node.hpp"
#include "ast_expressions.hpp"
#include <string>

class Declaration : public Node{

	protected: 
		std::string type;
		std::string var_id;
		ExpressionPtr value;
	
	public:
		Declaration(std::string _type, std::string _var_id) : //constructor with no value assignment
			type(_type),
			var_id(_var_id),
			value(NULL)
			{std::cerr<<"New Declaration with no value assigned"<<std::endl;}
		Declaration(std::string _type, std::string _var_id, ExpressionPtr _value) : //constructor with variable assignment
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
			dst<<var_id;
			dst<<" = ";
			if(value!=NULL){
				value ->translate(dst,indent);
			}
			else{
				dst<<"0";
			}
		}
};

/*class DeclList;

typedef const DeclListt *DeclListPtr;

class DeclList : public Node{

	protected:
		DeclPtr decl;
		DeclListPtr next;
	
	public:
};
*/



#endif
