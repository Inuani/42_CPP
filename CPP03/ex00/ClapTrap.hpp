#include <iostream>

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

class ClapTrap {

public :

	ClapTrap();
	ClapTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& rhs);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName() const;


private :

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif
