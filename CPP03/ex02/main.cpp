#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    FragTrap    fragy("Fragy");

    fragy.highFivesGuys();
    fragy.attack("Clapix");
    fragy.takeDamage(8);
    fragy.beRepaired(4);
    FragTrap    fragol("Fragol");
    fragol = fragy;
    return 0;
}
