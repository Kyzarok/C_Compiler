#ifndef ast_statements_hpp
#define ast_statements_hpp

#include <iostream> 
#include <vector>
#include <iostream> 
#include <string>





class Statement : public Node {
	//Once we go over how to separate Expression Statement and ReturnStatement it should be good
};



class ExpressionStatement : public Statement {

	protected:
		ExpressionPtr expr;
	public:	
		ExpressionStatement(ExpressionPtr _expr) : expr(_expr){} // constructor
//need to add evaluater
		virtual void print(std::ostream &dst) const override {
			expr->print(dst);
			dst<<";"<<std::endl;
		}
		virtual void translate(std::ostream &dst, int indent) const override {
			std::cerr<<"_____stateEXPR1_____"<<std::endl;
			std::cerr<<"Adding indent, indent is currently "<<indent<<std::endl;
			for(int i=0; i<indent;i++){ //Shold make a function / member function, quick hack for now
				dst<<" ";
			}
			expr->translate(dst,indent);
			std::cerr<<"_____stateEXPR2_____"<<std::endl;
			dst<<std::endl;
		}


};

//TODO add more statements, eg Return statement, if statement
class ReturnStatement : public Statement { // added 28/02/18. I think this is the correct format?
	protected:
		ExpressionPtr ret;
	public:
		ReturnStatement(ExpressionPtr _ret) : ret(_ret){}
		ExpressionPtr getReturnExpression() const{return ret;} 
		//print, evaluate, translate, compile, etc
		virtual void print(std::ostream &dst) const override{
			dst<<"return ";
			ret->print(dst);
			dst<<";";
			dst<<std::endl;
		}
		virtual void translate(std::ostream &dst, int indent) const override {
			std::cerr<<"_____stateRETURN1_____"<<std::endl;
			std::cerr<<"Adding indent, indent is currently "<<indent<<std::endl;
			for(int i=0; i<indent;i++){//Shold make a function / member function, quick hack for now
				dst<<" ";
			}
			dst<<"return ";
			ret->translate(dst,indent);
			std::cerr<<"_____stateRETURN2_____"<<std::endl;
			dst<<std::endl;
		}
};



class StatementList ;


class StatementList : public Statement
{ 
	protected: 
		StatementPtr current;
		StatementPtr next;
	public:
		//constructor with no next list
		StatementList(StatementPtr _current) :current(_current),next(NULL){ // wip constructor
			std::cerr<<"In constructor for StatementList with no next Statement List"<<std::endl;		 
		}
		//constructor with next list
		StatementList(StatementPtr _current, StatementPtr _next) :current(_current),next(_next){
			std::cerr<<"In constructor for StatementList with next Statement List"<<std::endl;
		}
	//will have printer, translator, etc
	//will simply call the function of those beneath
	
	virtual void print(std::ostream &dst) const override {
		std::cerr<<"Print on statement list got called"<<std::endl;
		if(next!=NULL){
			next->print(dst);
		}
		current->print(dst);
		std::cerr<<"Print on statement list successfully finished"<<std::endl;
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		std::cerr<<"_____stateLIST1_____"<<std::endl;
		if(next!=NULL){
			next->translate(dst,indent);
		}
		std::cerr<<"_____stateLIST2_____"<<std::endl;
		current->translate(dst,indent);
		std::cerr<<"_____stateLIST3_____"<<std::endl;
	}
};




class IfStatement : public Statement {

protected:
	ExpressionPtr condition; // the execute condition
	NodePtr body; // actually a statement list, the body of the if
public:
	IfStatement(ExpressionPtr _condition, NodePtr _body) : condition(_condition), body(_body) {}
	virtual void print(std::ostream &dst) const override {//if case exists
				
		dst << "if ( ";		//this won't work until bindings map is made
		condition->print(dst);
		dst << " ) { " << std::endl;
		body->print(dst);
		dst << "}";
		dst << std::endl;
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		for(int i=0; i<indent;i++){ //Shold make a function / member function, quick hack for now
			dst<<" ";
		}		
		dst << "if ";
		condition->translate(dst, indent);
		dst << " :" << std::endl;
		body->translate(dst, indent+4);
		dst << std::endl;
	}
};

class ElseStatement : public Statement {
protected:
	NodePtr body; // actually a statement list, the body of the if
public:
	ElseStatement(NodePtr _body) : body(_body) {}
	virtual void print(std::ostream &dst) const override {//if case exists
		dst << "else {" << std::endl;
		body->print(dst);
		dst << "}";
		dst << std::endl;
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		for(int i=0; i<indent;i++){ //Shold make a function / member function, quick hack for now
			dst<<" ";
		}
		dst << "else :" << std::endl;
		body->translate(dst, indent+4);
		dst << std::endl;
	}
};

class WhileStatement : public Statement {
protected:
	ExpressionPtr condition;
	NodePtr body; // actually a statement list, the body of the while
public:
	WhileStatement(ExpressionPtr _condition, NodePtr _body) : condition(_condition), body(_body) {}
	virtual void print(std::ostream &dst) const override {//if case exists
		dst << "while (";
		condition->print(dst);
		dst<< ") {" << std::endl;
		body->print(dst);
		dst << "}";
		dst << std::endl;
	}
	virtual void translate(std::ostream &dst, int indent) const override {
		for (int i = 0; i<indent;i++) { //Shold make a function / member function, quick hack for now
			dst << " ";
		}
		dst << "while ";
		condition->translate(dst,indent);
		dst << " :" << std::endl;
		body->translate(dst, indent + 4);
		dst << std::endl;
	}
};

#endif
