#include <iostream>
#include "Glouky.hpp"

int	main()
{
	Glouky	glouky;

	glouky.complain("DEBUG");
	glouky.complain("ERROR");
	glouky.complain("INFO");
	glouky.complain("WARNING");
	return 0;
}
