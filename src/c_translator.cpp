//This file will eventually contain the python functionality.

#include"ast.hpp"
#include <iostream>
#include<string>
#include<sstream>

int main(){
	std::stringstream ss;
	ss<<"# Boilerplate"<<std::endl<<"if __name__ == \" __main__ \":"<<std::endl;
	ss<<"import sys"<<std::endl<<"ret=main()"<<std::endl<<"sys.exit(ret)"<<std::endl;
	const Node *ast=parseAST(); //This function won't really return anything
	ast->translate(std::cout);
	std::cout<<std::endl;
	
	//now for boilerplate
	std::cout<<ss.str()<<endl;
	return 0;
}
