#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap	fragy("Fragy");

	std::cout << std::endl;
	fragy.highFivesGuys();
	
	std::cout << std::endl;
	fragy.attack("Clapix");
	fragy.takeDamage(8);
	fragy.beRepaired(4);

	std::cout << std::endl;
	FragTrap	fragol("Fragol");
	std::cout << std::endl;
	fragol = fragy;
	std::cout << std::endl;
	return 0;
}
