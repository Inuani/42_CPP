#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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

	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;
	void			setEnergyPoints(unsigned int amount);
	void			setHitPoints(unsigned int amount);
	void			setAttackDamage(unsigned int amount);

protected :

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif
