//This file will eventually contain the compile functionality.

#include"ast.hpp"
#include <iostream>
#include<string>
#include<sstream>

int main(/*Paramaters */){
	//TODO take input parameters, work out input file, target file, and whether compiling or translating (or printing I guess)
	
	const Node *ast=parseAST(); // build the ast
	//if translator
	if(true){ // hard code for now, based off of paramaters
		std::stringstream ss;
		ss<<"# Boilerplate"<<std::endl<<"if __name__ == \" __main__ \":"<<std::endl;
		ss<<"import sys"<<std::endl<<"ret=main()"<<std::endl<<"sys.exit(ret)"<<std::endl;
		ast->translate(std::cout);
		std::cout<<std::endl;
	
		//now for boilerplate
		std::cout<<ss.str()<<endl;
	}
	
	return 0;
}
