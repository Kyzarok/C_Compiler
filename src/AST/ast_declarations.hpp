#ifndef ast_declarations_hpp
#define ast_declarations_hpp


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
		//going to need to use special case with $4 - $7
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
			dst<<"def "<<fnc_ID<<"(";
			std::cerr<<"_____dec2_____"<<std::endl;
			if(args!=NULL){
				args->translate(dst, indent);
			}
			dst<<"):"<<std::endl;
			std::cerr<<"_____dec3_____"<<std::endl;
			body->translate(dst,indent+4);
			std::cerr<<"_____dec4_____"<<std::endl;
			
		}
		virtual void compile(std::ostream &dst) const override {
			dst<<"	.globl	"<<fnc_ID<<std::endl;
			dst<<"	.ent	"<<fnc_ID<<std::endl;
			dst<<fnc_ID<<":"<<std::endl;
			dst<<"addiu $sp,$sp,-8" <<std::endl; // this number 8 needs to be dynamic
			dst<<"sw $fp,4($sp)"<<std::endl;
			if(args!=NULL){
				args->compile(dst);
			}
			body->compile(dst);
			dst<<"move $sp,$fp" << std::endl;
			dst<<"lw $fp,4($sp)"<<std::endl;
			dst<<"addiu $sp,$sp,8" <<std::endl;
			dst<<"j $31"<<std::endl;
			dst<<"nop"<<std::endl;			
			dst<<"	.end	"<<fnc_ID<<std::endl;			
		}	//may be an idea to make sure stuff can point to parent
			//or at least the capability to count up a glob var
		/*virtual void explore(int & declarations) const override{
			

		}*/
};

class Param : public Node{

	protected:
		std::string type;
		std::string id;
		//ExpresstionPtr value; // technically this is valid eg int f(int x=2){return x;} is a valid function, returning 2 or the input. Not going to be supported.
	public:
		Param (std::string _type, std::string _id) : type(_type), id(_id){} //constructor
		virtual void print(std::ostream &dst) const override {
			
		}
		virtual void translate(std::ostream &dst, int indent) const override {
			dst<<id;
				
		}
		virtual void compile(std::ostream &dst) const override {
			std::cerr<<"Not implemented"<<std::endl;
		}
};

class ParamList : public Node{ // list of function paramaters

	protected:
		NodePtr current; // pointer to current Parameter, of type node
		NodePtr next; // pointer to next Parameter list, of type node too
	public:
		ParamList(NodePtr _current) : current(_current), next(NULL){} // constructor with no next
		ParamList(NodePtr _current, NodePtr _next) : current(_current), next(_next){} // constructor with next
		
		virtual void print(std::ostream &dst) const override {
			
		}
		
		virtual void translate(std::ostream &dst, int indent) const override {
			std::cerr<<"_____paramLIST1_____"<<std::endl;
			if(next!=NULL){				
				next->translate(dst,indent);
				dst<<", ";
			}
			std::cerr<<"_____paramLIST2_____"<<std::endl;
			current->translate(dst,indent);
			std::cerr<<"_____paramLIST3_____"<<std::endl;
				
		}
		virtual void compile(std::ostream &dst) const override {
			std::cerr<<"Not implemented"<<std::endl;
		}
};



#endif

/*addiu	$sp,$sp,-8			return 3
	sw	$fp,4($sp)
	move	$fp,$sp

	li	$2,3			# 0x3
	
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

addiu	$sp,$sp,-16			int x = 3
	sw	$fp,12($sp)		return x
	move	$fp,$sp

	li	$2,3			# 0x3
	sw	$2,4($fp)	storing 3 into main mem
	lw	$2,4($fp)	loading the mem location with 3

	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop


addiu	$sp,$sp,-16			int f(int x){
	sw	$fp,12($sp)			int y;
	move	$fp,$sp				y = 5;
						return x+y;
	sw	$4,16($fp)
	li	$2,5			# 0x5
	sw	$2,4($fp)
	lw	$3,16($fp)
	lw	$2,4($fp)
	addu	$2,$3,$2

	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop


*/


