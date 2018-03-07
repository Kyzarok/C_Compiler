#ifndef ast_statements_hpp
#define ast_statements_hpp

#include "ast_expressions.hpp"

class Statement : public Node {
	//Once we go over how to separate Expression Statement and ReturnStatement it should be good
};w

typedef const Statement *StatementPtr;

class ExpressionStatement : public Statement {

	protected:
		ExpressionPtr expr;
	public:	
		ExpressionStatement(ExpressionPtr _expr) : expr(_expr){} // constructor
//need to add evaluater
	

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
};
//TODO make Compound Statement and Statement List work

class CompoundStatement : public Node{ 
//pointer to dec list
//pointer to statement list
//C does not allow for random order of declaration and statement
//all dec's come before the statements

};

class StatementList : public Node{
	protected: 
		std::vector<StatementPtr> sl; // I think its easiest to have a Statement list be a vector?
	public:
		StatementList(){ // wip constructor
			//do something
			sl(0);
		}	
};

typedef const StatementList *StatementListPtr;

#endif
