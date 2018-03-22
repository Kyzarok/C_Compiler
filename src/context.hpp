#ifndef context_hpp
#define context_hpp

#include <map>



class Context{ // contains a map, key is string, stored is string. Maps variables to values
	/*
	this container should create a table that looks like: 	
	
	var_id	| reg_stored_in?	| StackPointer Offset
	x			| NULL				| 4
	y			| $8					| 8
	
	etc
	*/	
	
	protected:
		std::map<std::string, std::string>  conReg;
		std::map<std::string, int> conOffset;

	public:
		Context(){}
		std::string check(std::string var_id){	//returns reg_stored_in? for each string
			std::string tmp = conReg.at(var_id);
			return tmp;
		}
		void updateConReg(std::string var_id, std::string newReg){
			conReg.at(var_id) = newReg;	
		}
		void updateConOffset(std::string var_id, int offset){
			conOffset.at(var_id) = offset;
		}
		int getOffset(std::string var_id){
			int offset = conOffset.at(var_id);
			return offset;
		}
};

class Registers{ // contains useful info about registers
	/*Register conventions
	$0 - always 0
	$1 - used by assembler?
	$2,3 - return values ($2 by default, $3 if more than 32 bits)
	$4-7 - argument registers, contain first four arg values in function call. These are also by convention stored at the top of the stack / bottom of last frame?
	$8-15,24,25 - temp registers
	$16-23 - saved registers
	$26-27 - Kernel reserved, don't use
	$28 - global pointers? Refrence says to ignore
	$29 - stack pointer
	$30 - frame pointer
	$31 - return address of subroutine call
	
	*/
	
	//genuinely unsure which we can use
	protected:
		// it doesn't matter what's in a register, it matters if its in usage
		bool register_used[32]; // there are 32 registers.
		
	public:
		Registers(){
			for(int i=0; i<32;i++){ // 32 registers, array starts at 0
				register_used[i] = false;
			}
			register_used[0] = true; // reg 0 is always used
		}
		bool ReserveRegister(int x){ // mark a register as used
			if(register_used[x]){ // ie if the register *is* used
				return false; // this indicates I could not reserve register x
			}
			register_used[x] = true; // its now in use
			return true; // indicates success
		}
		void ReleaseRegister(int x){
			if(x!=0){ // can't unfree register 0
				register_used[x]=false;
			}
		}
		int EmptyRegister(){
		//return an unused register in valid range(figure that out). If none available, return -1 I guess
			for(int i= 8;i<=15;i++){
				if(!register_used[i]){
					return i;
				}
			}
			if(!register_used[24]){
				return 24;
			}
			if(!register_used[25]){
				return 25;
			}
			return -1;
		}
};

#endif
