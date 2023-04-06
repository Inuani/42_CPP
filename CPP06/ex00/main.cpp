#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string input(av[1]);
		ScalarConverter::convert(input);
	}
	else
		std::cout << "Usage: ./convert <value> where <value> is a literal of type char, int, double, or float." << std::endl;
	return 0;
}
