#include <iostream>
#include "../lexer/lexer.h"
#include "../parser/parser.h"
#include "build.h"


int main(){
	std::string str = "1+1";		
	lex tokens(str);
	parse(tokens);
	
	return 0;
}
