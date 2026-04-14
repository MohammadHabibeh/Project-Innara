#pragma once
#include<iostream>
#include<memory>
#include<string>


//define Expression Object
class NumberExpr;
class BinaryOperation;

//define visitor interface
class visitor{
	public:
		virtual void visit(NumberExpr& num) = 0;
		virtual void visit(BinaryOperation& bin) = 0;
};

//Expression Defenition
class ExprAST{
	public:
		virtual void accept(visitor& visitor) = 0; 
};


class NumberExpr: public ExprAST{
	public:
		std::string value; 
		NumberExpr(std::string v): value(v) {};
		
		void accept(visitor& visitor) override {
			visitor.visit(*this);
		};
};

class BinaryOperation: public ExprAST{

	public:
		std::string op;
		std::unique_ptr<ExprAST> lhs;
		std::unique_ptr<ExprAST> rhs;
		BinaryOperation(std::string operation, std::unique_ptr<ExprAST> left, std::unique_ptr<ExprAST> right): op(operation), lhs(std::move(left)), rhs(std::move(right)) {};
					
		void accept(visitor& visitor) override {
			visitor.visit(*this);
			
		};
};

//Defnetion of print operator that transform each of objects of expression into printable
class printvisit: public visitor{
	public:
		void visit(NumberExpr& num) override{
			std::cout<<num.value;
		};

		void visit(BinaryOperation& bin) override{
			std::cout<<"Bin( " ;
		 	bin.lhs->accept(*this);
			std::cout<<" " ;
			std::cout<< bin.op;
			std::cout<<" " ;
			bin.rhs->accept(*this);
			std::cout<< " )";	
		};
};
