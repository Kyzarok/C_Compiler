//This file contains the I/O handling for compiler and translator

#include"ast.hpp" //header pointing to various AST nodes
#include <iostream>
#include<string>
#include<sstream> // makes printing boiler plate somewhat quicker
#include<cstdlib> //Required for exit

int main(int argc, char *argv[]){
	
	//check for expected number of inputs
	//program should be ran in form location {mode} {source} "-o" {dest}
	if(argc<5){ //expected number
		std::cerr<<"ERROR: Incorrect number of arguments provided"<<std::endl;
		std::exit(1);
	}
	// get mode
	std::string mode_select(argv[1]);
	const Node *ast=parseAST(); // build the ast
	//if translator
	if(mode_select =="--translate"){ //ie translator mode
	
		
		std::stringstream ss; // make a function
		ss<<"# Boilerplate"<<std::endl<<"if __name__ == \" __main__ \":"<<std::endl;
		ss<<"import sys"<<std::endl<<"ret=main()"<<std::endl<<"sys.exit(ret)"<<std::endl;
		
		
		std::cerr<<"We translating"<<std::endl;
		//translate
		ast->translate(std::cout);
		std::cout<<std::endl;
		std::cerr<<"Boilerplate"<<std::endl;
		//now for boilerplate
		std::cout<<ss.str()<<std::endl;
	}
	else if(mode_select =="-S"){ //ie compile
		std::cerr<<"ERROR: Compile unimplemented at time"<<std::endl;
	}
	
	else{
		std::cerr<<"ERROR: Invalid command"<<std::endl;
		std::exit(1);
	}
	
	return 0;
}
