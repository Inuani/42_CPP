#include <iostream>
#include "DiamondTrap.hpp"


int main( void )
{
	DiamondTrap dia("Dia");

	std::cout << std::endl;
	dia.whoAmI();

	std::cout << std::endl;
	dia.attack("Crapux");

	std::cout << std::endl;
	DiamondTrap dia2(dia);

	std::cout << std::endl;
	DiamondTrap dia3;

	std::cout << std::endl;
	dia3 = dia;

	std::cout << std::endl;
	dia.highFivesGuys();
	dia.guardGate();

	std::cout << std::endl;
	{
		//testing destructor
		DiamondTrap dia4("Dios");
	}
	std::cout << std::endl;
	return 0;
}
