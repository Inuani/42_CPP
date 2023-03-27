#include <iostream>
#include <fstream>
#include "FileHandler.hpp"
#include "StringRep.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage :" << av[0] << " <filename> <string to replace> <replacement string>" << std::endl;
		return 1;
	}
	FileHandler	fileHandler(av[1]);
	StringRep	stringRep(av[2], av[3], fileHandler.getInfileStr());
	fileHandler.copyStrInOutfileStream(stringRep.getOutfileStr());
	return 0;
}
