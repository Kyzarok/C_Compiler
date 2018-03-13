#ifndef ast_varb_declarations_hpp
#define ast_varb_declarations_hpp

#include "ast_node.hpp"

class Declaration : public Declaration{

	protected: 
		std::string type;
		std::var_id;
		

};

class DeclList;

typedef const DeclListt *DeclListPtr;

class DeclList : public Node{

	protected:
		DeclPtr decl;
		DeclListPtr next;
	
	public:
};




#endif
