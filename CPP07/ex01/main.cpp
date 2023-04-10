#include "Iter.hpp"
#include <iostream>

int	main ()
{

	std::cout << "--------------------- test int ---------------------" << std::endl;
	int	intArray[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(intArray) / sizeof(intArray[0]);

	iter(intArray, len, printArrayElement);

	iter(intArray, len, incrementArrayElement);
	std::cout << std::endl;
	iter(intArray, len, printArrayElement);

	iter(intArray, len, setToZeroArrayElement);
	std::cout << std::endl;
	iter(intArray, len, printArrayElement);

	std::cout << "--------------------- test People class ---------------------" << std::endl;

	People peps[] = {
		People("Alice", 32),
		People("Elisse", 33),
		People("Ulysse", 21)
	};

	size_t nbPeps = sizeof(peps) / sizeof(peps[0]);

	iter(peps, nbPeps, printArrayElement);
	std::cout << std::endl;

	// The += 1 operation in the incrementArrayElement function
	// is translated to a call to operator+=(1) for the People object.
	iter(peps, nbPeps, incrementArrayElement);
	iter(peps, nbPeps, printArrayElement);

	return 0;
}
