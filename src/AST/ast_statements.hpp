#ifndef ast_statements_hpp
#define ast_statements_hpp

#include "ast_expressions.hpp"

class Statement : public Node {
	
};

class ExpressionStatement : public Statement {

	protected:
		ExpressionPtr expr;
		
		ExpressionStatement(ExpressionPtr _expr) : expr(_expr){} // constructor
	

//TODO add functionality to this class
};

//TODO add more statements, eg Return statement, if statement
class ReturnStatement :public Statement { // added 28/02/18. I think this is the correct format?
	protected:
		ExpressionPtr ret;
		
		ReturnStatement(ExpressionPtr _ret) : ret(_ret){}
	public:
		ExpressionPtr *getReturnExpression() const; 
		//print, evaluate, translate, compile, etc
}
//TODO make Compound Statement and Statement List work

class CompoundStatement : public Node{ // not sure why this extra level is needed, or how to implement. Cut?
}

class StatementList : public Node{

	protected: 
		std::vector<Statement> sl; // I think its easiest to have a Statement list be a vector?
		int sl_l; // possibly just have a variable returning the length? Probably not needed.
	public:
		StatementList(){ // wip constructor
		
		}
		
}


#endif
