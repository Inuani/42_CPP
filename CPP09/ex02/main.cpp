#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pm;

	try {
		pm.parseInput(ac, av);
		pm.mergeSort();
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}


