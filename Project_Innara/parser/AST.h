class ExprAST{

	public:
		virtual ~ExprAST() = default;
		
};


class NumberExpr: public ExprAST{
	public:
		std::string value; 
		NumberExpr(std::string v): value(v) {};
};

class BinaryOperation: public ExprAST{

	public:
		std::string op;
		std::unique_ptr<ExprAST> lhs;
		std::unique_ptr<ExprAST> rhs;
		BinaryOperation(std::string operation, std::unique_ptr<ExprAST> left, std::unique_ptr<ExprAST> right): op(operation), lhs(std::move(left)), rhs(std::move(right)) {};

};
