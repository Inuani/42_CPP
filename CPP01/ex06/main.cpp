#include <iostream>
#include "Glouky.hpp"

void	gloukySwitch(std::string av, Glouky &glouky)
{
	switch (glouky.input2Int(av)) {
		case 0 :
			glouky.complain("DEBUG");
		case 1 :
			glouky.complain("INFO");
		case 2 :
			glouky.complain("WARNING");
		case 3 :
			glouky.complain("ERROR");
			break ;
		default :
			std::cout << "You did not succeed making Glouky complain, too bad!" << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "You did not succeed making Glouky complain, too bad!" << std::endl;
		return 1;
	}
	Glouky	glouky;

	gloukySwitch(av[1], glouky);
	return 0;
}
