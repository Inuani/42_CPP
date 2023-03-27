#include <iostream>

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

class ClapTrap {

public :

	ClapTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& rhs);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private :

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif
