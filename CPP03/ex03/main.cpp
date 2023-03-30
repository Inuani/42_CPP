#include <iostream>
#include "DiamondTrap.hpp"


int main( void )
{
    DiamondTrap dia("Dia");
    dia.whoAmI();
    dia.attack("Crapux");

    std::cout << std::endl;
    DiamondTrap dia2(dia);

    std::cout << std::endl;
    DiamondTrap dia3;
    dia3 = dia;

    std::cout << std::endl;
    dia.highFivesGuys();
    dia.guardGate();

    std::cout << std::endl;
    {
        //testing destructor
        DiamondTrap dia4("Dios");
    }
    return 0;
}
