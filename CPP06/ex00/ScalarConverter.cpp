#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (&rhs == this) {}
	return *this;
}

bool	ScalarConverter::isChar(const std::string& input)
{
	if (input.empty()) 
		return false;
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return true;
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
	{
		if (std::isprint(input[1]) && !std::isdigit(input[1]))
			return true;
	}
	return false;
}

bool	ScalarConverter::isInt(const std::string& input)
{
	if (input.empty()) 
		return false;
	size_t	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for(; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::isFloat(const std::string& input)
{
	if (input.empty()) 
		return false;
	if (input.back() == 'f' || input.back() == 'F')
	{
		std::string withoutF = input.substr(0, input.size() - 1);
		if (withoutF == "+inf" || withoutF == "-inf" || withoutF == "nan")
			return true;
		return isDouble(withoutF);
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string& input)
{
	if (input.empty()) 
		return false;
	if (input == "+inf" || input == "-inf" || input == "nan")
		return true;
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	bool dotFound = false;
	int	digitCount = 0;
	for(; i < input.size(); i++)
	{
		if (input[i] == '.')
		{
			if(dotFound)
				return false;
			dotFound = true;
		}
		else if (!std::isdigit(input[i]))
			return false;
		else
			digitCount++;
	}
	if (!dotFound && digitCount > 9)
		return true;
	return dotFound;
}

char		ScalarConverter::str2Char(const std::string& input)
{
	if (input[0] == '\'')
		return input[1];
	return input[0];
}

int		ScalarConverter::str2Int(const std::string& input)
{
	int res;
	std::stringstream ss(input);
	ss >> res;
	return res;
}

float	ScalarConverter::str2Float(const std::string& input)
{
	float res;
	std::string	withoutF = input.substr(0, input.size() -1 );
	std::stringstream ss(withoutF);
	ss >> res;
	return res;
}

double	ScalarConverter::str2Double(const std::string& input)
{
	double res;
	std::stringstream ss(input);
	ss >> res;
	return res;
}

// first to specify that we are using Checker type that is nested struct
// in ScalarConverter class
// ScalarConverter::checkers[] to specify we are initialising the member "checkers"
ScalarConverter::Checker ScalarConverter::_checkers[] = {
	{"char", isChar},
	{"double", isDouble},
	{"float", isFloat},
	{"int", isInt}
};

void	ScalarConverter::caseChar(const std::string& input)
{
	char charRes = str2Char(input);
	std::cout << "char: \'" << charRes << '\'' << std::endl;
	int	i = static_cast<int>(charRes);
	std::cout << "int: " << i << std::endl;
	float f = static_cast<float>(charRes);
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	// std::setprecision(1) sets precision of output, number of digits after decimal point.
	// << std::fixed sets output for floating-point values to fixed-point notation.
	double d = static_cast<double>(charRes);
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

void	ScalarConverter::caseInt(const std::string& input)
{
	int intRes = str2Int(input);
	char c = static_cast<char>(intRes);
	std::cout << "char: ";
	if ((intRes <= std::numeric_limits<char>::max() && intRes >= std::numeric_limits<char>::min()) && std::isprint(c))
		std::cout << '\'' << c << '\'' << std::endl;
	else
		std::cout << "Non-displayable" << std::endl;
	std::cout << "int: " << intRes << std::endl;
	float f = static_cast<float>(intRes);
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	double d = static_cast<double>(intRes);
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

void	ScalarConverter::caseFloat(const std::string& input)
{
	float floatRes;
	if (input == "-inff" || input == "+inff" || input == "nanf")
		floatRes = handleSpecial(input);
	else 
	{
		floatRes = str2Float(input);
		char c = static_cast<char>(floatRes);
		std::cout << "char: ";
		if ((floatRes <= std::numeric_limits<char>::max() && floatRes >= std::numeric_limits<char>::min()) && std::isprint(c))
			std::cout << '\'' << c << '\'' << std::endl;
		else
			std::cout << "Non-displayable" << std::endl;
		int	i = static_cast<int>(floatRes);
		if (floatRes <= std::numeric_limits<int>::max() && floatRes >= std::numeric_limits<int>::min())
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: Non-displayable" << std::endl;
	}
	std::cout << "float: " << std::setprecision(1) << std::fixed << floatRes << "f" << std::endl;
	double d = static_cast<double>(floatRes);
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

double ScalarConverter::handleSpecial(const std::string& input) {
	double inf = HUGE_VAL;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "-inf" || input == "-inff") {
		return -inf;
	} else if (input == "+inf" || input == "+inff") {
		return inf;
	} else if (input == "nan" || input == "nanf") {
		return inf / inf;
	}
	return 0.0;
}

bool isWithinFloatRange(double value) {
	float minValue = -std::numeric_limits<float>::max();
	float maxValue = std::numeric_limits<float>::max();

	if (value >= static_cast<double>(minValue) && value <= static_cast<double>(maxValue))
		return true;
	return false;
}

void	ScalarConverter::caseDouble(const std::string& input)
{
	double doubleRes;
	if (input == "-inf" || input == "+inf" || input == "nan")
		doubleRes = handleSpecial(input);
	else 
	{
		doubleRes = str2Double(input);
		char c = static_cast<char>(doubleRes);
		std::cout << "char: ";
		if ((doubleRes <= std::numeric_limits<char>::max() && doubleRes >= std::numeric_limits<char>::min()) && std::isprint(c))
			std::cout << '\'' << c << '\'' << std::endl;
		else
			std::cout << "Non-displayable" << std::endl;
		int	i = static_cast<int>(doubleRes);
		if (doubleRes <= std::numeric_limits<int>::max() && doubleRes >= std::numeric_limits<int>::min())
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: Non-displayable" << std::endl;
	}
	float f = static_cast<float>(doubleRes);
	if (isWithinFloatRange(doubleRes) || input == "-inf" || input == "+inf" || input == "nan")
		std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	else
		std::cout << "float: Non-displayable" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << doubleRes << std::endl;
}

void	ScalarConverter::convert(const std::string& input)
{
	std::string	type = "";
	for(size_t i = 0; i < 4; ++i)
	{
		if (_checkers[i].func(input) == true)
		{
			type = _checkers[i]._type;
			break ;
		}
	}
	if (type.empty())
	{
		std::cout << "Usage: ./convert <value> where <value> is a literal of type char, int, double, or float." << std::endl;
		return ;
	}
	switch (type[0])
	{
		case 'c': {
			caseChar(input);
			break; }
		case 'i': {
			caseInt(input);
			break; }
		case 'f': {
			caseFloat(input);
			break; }
		case 'd': {
			caseDouble(input);
			break; }
		default :
			break;
	}
}
