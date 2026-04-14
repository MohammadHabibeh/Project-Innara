#include<iostream>
#include<memory>
#include "../lexer/lexer.h"
#include "parser.h"
#include "AST.h"
//#project innara
//fun (int hello, int world) -> int {  
//	ret hello + world;
//}	
std::unique_ptr<ExprAST> Parse(lex& Tokens){
	return ExprPrime(Tokens);
}

std::unique_ptr<ExprAST> ExprPrime(lex& Tokens){
	
	auto a = Term(Tokens);
	
	while(Tokens.CheckNextValue() == "+" || Tokens.CheckNextValue() == "-"){
		auto op = Tokens.lookahead().value;
		auto b = Term(Tokens);
		a = std::make_unique<BinaryOperation>(op, std::move(a), std::move(b));
	}	
	
	return a; 	
	
}

std::unique_ptr<ExprAST> Term(lex& Tokens){	
	return Factor(Tokens);
}

std::unique_ptr<ExprAST> Factor(lex& Tokens){
	
	if(Tokens.CheckNextType() == TokenType::integer){
		Token tok_number = Tokens.lookahead();
		auto ptr = std::make_unique<NumberExpr>(tok_number.value);
		return ptr;	
	} 
	else{
		throw std::invalid_argument("Syntax error: can't parse a non number you idiot");
	} 	

}
int main(){
	std::string str("1+1+1+1"); 
	lex lexer(str);
	auto a = Parse(lexer);
	//BinaryOperation* Bin = dynamic_cast<BinaryOperation*>(a.get()); 
	//if(Bin != nullptr){
//		std::cout<< Bin->rhs;	
//	}
	printvisit print;
	a->accept(print);
	return 0;
}
//program Innara() {
//		the program does assignments on expressions
//		expressions only as of now can only be  calculations grammar
//		recursively descent on expressions
//				
//}


