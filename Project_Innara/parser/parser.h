#pragma once
#include<memory>

class ExprAST;
class NumberExpr;
class BinaryOprtation;

class lex;

std::unique_ptr<ExprAST> Parse(lex& Tokens);
std::unique_ptr<ExprAST> ExprPrime(lex& Tokens);	
std::unique_ptr<ExprAST> Term(lex& Tokens);
std::unique_ptr<ExprAST> Factor(lex& Tokens);
	

