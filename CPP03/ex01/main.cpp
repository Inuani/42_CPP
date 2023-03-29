#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ClapTrap    clapix("Clapix", 10, 10, 2);
    ClapTrap    clapox("Clapox", 10, 10, 4);

    clapix.attack("Clapux");

    clapox.takeDamage(13);

    clapix.beRepaired(5);

    ClapTrap    clapux = clapox;

    ClapTrap    clapax(clapux);

    ClapTrap    Clapipox("Clapipox", 0, 10, 2);
    Clapipox.takeDamage(1);

    clapix.attack(clapox.getName());
    clapix.attack(clapux.getName());

    clapix.beRepaired(5);
    clapox.beRepaired(3);

    clapux.takeDamage(7);
    clapax.takeDamage(5);

    return 0;
}
