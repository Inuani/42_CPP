#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	clapix("Clapix", 10, 10, 2);
	ClapTrap	clapox("Clapox", 10, 10, 4);

	std::cout << std::endl;
	clapix.attack("Clapux");
	clapox.takeDamage(13);
	clapix.beRepaired(5);

	std::cout << std::endl;
	ClapTrap	clapux = clapox;
	ClapTrap	clapax(clapux);
	ClapTrap	Clapipox("Clapipox", 0, 10, 2);
	// Clapux & Clapipox => Clapox

	std::cout << std::endl;
	Clapipox.takeDamage(1);
	Clapipox.attack(clapux.getName());

	std::cout << std::endl;
	clapix.attack(clapox.getName());

	std::cout << std::endl;
	clapix.beRepaired(5);
	clapox.beRepaired(3);

	std::cout << std::endl;
	// Copie de Clapox
	clapux.takeDamage(7);
	clapax.takeDamage(5);

	std::cout << std::endl;
	return 0;
}
