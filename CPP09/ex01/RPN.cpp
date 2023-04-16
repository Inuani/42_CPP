#include "RPN.hpp"
#include <iostream>

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN&	RPN::operator=(const RPN& rhs)
{
	(void)rhs;
	return *this;
}
