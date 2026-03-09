#include<iostream> 
#include<cctype>
#include <vector>
#include <stdexcept>
#include "lexer.h"

Token is_operation(const std::string& str, int p){
	//set  = [=, + , /, *]
	char ch = str[p]; 
	switch(ch){
		case('+'):
			return Token{TokenType::plus, "+"};
		case('/'):
			return Token{TokenType::div, "/"};
		case('*'):
			return Token{TokenType::multi, "*"};
		case('-'):
			return Token{TokenType::minus, "-"};
	}
	return Token{TokenType::invalid, std::string(1,ch)};
};
std::string parse_int(const std::string& str, int p){
	//collect these charaters?
	std::string integers;
	while( isdigit(str[p])){
		integers.push_back(str[p]);
		p++;
	}
	return integers;
};
Token is_integer(const std::string& str, int p){
	if((str[p] >= '0') && (str[p]  <= '9')){
		std::string value = parse_int(str ,p);
		return Token{TokenType::integer, value};	
	}
	return Token{TokenType::invalid, std::string(1,'0')};
	
};

std::vector<Token> Tokenizer(const std::string& str){ 	
	std::vector<Token> tokens;
	int pos = 0;
		
	while(pos < str.size()){
	//checking for white space	
		if(isspace(str[pos])){
    			pos++;
    			continue;
		}
	//checking for operation s.a. [+, -, *, /]	
		Token t = is_operation(str, pos);
		if(t.type != TokenType::invalid){
			tokens.push_back(t);
			pos++;
		}
		else if(((t = is_integer(str, pos))).type != TokenType::invalid){
			tokens.push_back(t);
			pos = pos + (t.value.size());
		}
		else{
			throw std::invalid_argument(
					std::string("lexer error: cannot identify token at: " ) + str[pos]);
		}
	}
	return tokens;
}
	
int main(){

	std::string src = "+++++++1";
	std::vector<Token> hello = Tokenizer(src);

	for(int i = 0; i < hello.size(); i++){
		std::cout<< hello[i].value<<std::endl;
	}
	
	std::cout<< hello.size()<<std::endl;
	return 0;
}
