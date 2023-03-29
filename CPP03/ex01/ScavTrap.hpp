#include <iostream>
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public Claptrap {

public :

	ScavTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	// std::string getName() const;

    void guardGate();


private :

	// std::string		_name;
	// unsigned int	_hitPoints;
	// unsigned int	_energyPoints;
	// unsigned int	_attackDamage;
};

#endif