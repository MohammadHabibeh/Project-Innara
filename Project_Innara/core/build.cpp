#include <iostream>
#include "../lexer/lexer.h"
#include "build.h"


int main(){
	std::string str = "1+1";		
	lex tokens(str);
	//parse(tokens);
	Token tok = tokens.lookahead();	
	std::cout<< tok.value;	
	return 0;
}
