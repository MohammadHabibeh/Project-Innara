#pragma once
#include <string>
#include <vector>

enum class TokenType {
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
