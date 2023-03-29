#include <iostream>
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {

public :

	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	void	attack(const std::string& target);
	void	guardGate();

private :

};

#endif
