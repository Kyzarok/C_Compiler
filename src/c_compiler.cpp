//This file contains the I/O handling for compiler and translator

#include"ast.hpp" //header pointing to various AST nodes
#include <iostream>
#include<string>
#include<sstream> // makes printing boiler plate somewhat quicker
#include<cstdlib> //Required for exit
#include<fstream> 
#include<vector>





std::string make_boilerplate(){
	std::stringstream ss; // make a function
	ss<<"# Boilerplate"<<std::endl<<"if __name__ == \"__main__\":"<<std::endl;
	ss<<"    import sys"<<std::endl<<"    ret=main()"<<std::endl<<"    sys.exit(ret)"<<std::endl;
	return ss.str();
};

int main(int argc, char *argv[]){
	
	//check for expected number of inputs
	//program should be ran in form {location} {mode} {source} "-o" {dest}
	if(argc<5){ //expected number
		std::cerr<<"ERROR: Incorrect number of arguments provided"<<std::endl;
		std::exit(1);
	}
	
	//open dest file
	
	std::ofstream fileDest;
	
	fileDest.open(argv[4]); //the location of the dest file
	if(!(fileDest.is_open())){ //if not opened then return error
		std::cerr<<"Dest File "<<argv[2]<< " not found"<<std::endl; 
		std::exit(1);//exit
	}
	
	// get mode
	std::string mode_select(argv[1]);
	
	
	// Build AST
	const Node *ast=parseAST(argv[2]); //TODO make this read from source file, not stdin
	
	
	//functionality
	if(mode_select =="--translate"){ //ie translator mode
	//if(true){ // temp hard code to translate
	
			
		std::cerr<<"We translating"<<std::endl;
		//translate
		
		ast->translate(fileDest,0);
		//fileDest<<std::cout<<std::endl; //TODO make this write to dest file, not stdout. Can put stdout into file stream?
		
		
		
		std::cerr<<"Boilerplate"<<std::endl;
		//now for boilerplate
		fileDest<<std::endl;
		fileDest<<make_boilerplate()<<std::endl;
	}
	else if(mode_select =="-S"){ //ie compile
		std::cerr<<"ERROR: Compile unimplemented at time"<<std::endl;
		std::exit(1);
	}
	
	else{
		std::cerr<<"ERROR: Invalid command"<<std::endl;
		std::exit(1);
	}
	
	return 0;
}
