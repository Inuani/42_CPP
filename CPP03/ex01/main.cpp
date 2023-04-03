#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	scavy("Scavy");
	ClapTrap	clapix("Clapix", 10, 10, 0);

	std::cout << std::endl;
	scavy.guardGate();

	std::cout << std::endl;
	// diff message with attack function
	scavy.attack("Clapix");
	clapix.attack("Scavy");

	std::cout << std::endl;
	scavy.takeDamage(8);
	scavy.beRepaired(4);

	std::cout << std::endl;
	ScavTrap	scavux("Scavux");
	scavux = scavy;
	std::cout << std::endl;
	
	// ScavTrap	scaval(scavy);
	return 0;
}
