#pragma once
#include <string>
#include <vector>

enum class TokenType {
	empty,
	eof,
	integer,
	minus,
	plus,
	div,
	multi,
	invalid

};

struct Token{
	TokenType type;
	std::string value;
};

Token is_operation(const std::string& str, int p);
std::string parse_int(const std::string& str, int p);
Token is_integer(const std::string& str, int p);
Token is_eof(const std::string& str, int p);
std::vector<Token> Tokenizer(const std::string& str); 	

class lex{
	public:
		std::vector<Token> Tokens;

		lex(const std::string& str){
			Tokens = Tokenizer(str);
		}
		//returns and consumes next Token inline
		Token lookahead();
		std::string CheckNextValue();
		TokenType CheckNextType();
};

