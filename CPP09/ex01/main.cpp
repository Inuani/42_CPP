#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: usage: ./RPN <inverted Polish mathematical expression>" << std::endl;
		return 1;
	}
	RPN	inst;
	std::string input(av[1]);
	try {
		int res = inst.doingRPN(input);
		std::cout << res << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: "<< e.what() << std::endl;
	}
	return 0;
}
