#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

class DiamondTrap : public FragTrap, public ScavTrap{

public:

	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& src);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& rhs);

	void	whoAmI();
	void	attack(const std::string& target);

private:

	std::string	_name;

};

#endif
