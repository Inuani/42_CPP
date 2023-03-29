#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap    scavy("Scavy");
    ClapTrap    Clapix("Clapix", 10, 10, 0);

    scavy.guardGate();

    scavy.attack("Clapix");
    Clapix.attack("Scavy");

    scavy.takeDamage(8);
    scavy.beRepaired(4);

    ScavTrap    scavux("Scavux");
    scavux = scavy;

    // ScavTrap    scaval(scavy);

    return 0;
}
