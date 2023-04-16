#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

RPN::RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& rhs) {
	(void)rhs;
	return *this;
}

int	RPN::doingRPN(const std::string& input) {
	std::string 		token;
	std::istringstream	ss(input);
	std::stack<int>		nbStack;

	while(ss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (nbStack.size() >= 2) {
				int b = nbStack.top();
				nbStack.pop();
				int	a = nbStack.top();
				nbStack.pop();
				if (token == "+")
					nbStack.push(a + b);
				else if (token == "-")
					nbStack.push(a - b);
				else if (token == "*")
					nbStack.push(a * b);
				else if (token == "/") {
					if (b == 0)
						throw std::runtime_error("Can not divide by 0.");
					else
						nbStack.push(a / b);
				}
			}
			else
				throw std::runtime_error("Invalid input.");
		}
		else {
			std::istringstream	ssDigit(token);
			int digit;
			if (!(ssDigit >> digit) || digit > 10)
				throw std::runtime_error("Invalid token" + token);
			nbStack.push(digit);
		}
	}
	if (nbStack.size() != 1)
		throw std::runtime_error("invalid expression.");
	return nbStack.top();
}


