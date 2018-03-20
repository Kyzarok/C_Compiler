#ifndef context_hpp
#define context_hpp

#include <map>



class Context{ // contains a map, key is string, stored is string. Maps variables to values
	/*protected:
		std::map<std::string, std::string>  ctxt;
	public:
		void update(std::string str_1, std::string str_2){
			

		}*/
};

class Registers{ // contains useful info about registers
	/*Register conventions
	$0 - always 0
	$1 - used by assembler?
	$2,3 - return values ($2 by default, $3 if more than 32 bits)
	$4-7 - argument registers, contain first four arg values in function call
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
