#include "ScavTrap.hpp"
#include "iostream"

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
	std::cout << "\033[33m" << "ScavTrap default constructor called !" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "\033[33m" << "ScavTrap " << name << " émerge d'une nuée de poussière, prêt à défendre cette porte minable que même un chat errant pourrait enjamber !" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "\033[34m" << "ScavTrap " << src.getName() << " se clône, créant un double tout aussi inutile et désespérant que le premier !" << "\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[31m" << "ScavTrap " << getName() << " succombe à ses blessures, laissant derrière lui une porte qui n'a jamais été menacée et un héritage de médiocrité." << "\033[0m" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "\033[33m" << "ScavTrap " << getName() << " absorbe la rage et la détermination de " << rhs.getName() << " pour mieux défendre cette porte qui ne mène qu'à une impasse !" << "\033[0m" << std::endl;
	ClapTrap::operator=(rhs);
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "\033[33m" << "ScavTrap " << getName() << " attaque " << target << " avec des insultes à peine imaginatives, infligeant " << getAttackDamage() << " points de dégâts!" << "\033[0m" << std::endl;
	}
	else
		std::cout << "\033[33m" << "ScavTrap " << getName() << " n'a pas assez d'énergie ou de points de vie pour avoir de la répartie et faire une blague." << "\033[0m" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "\033[36m" << "ScavTrap " << getName() << " garde cette porte qui ne mène nulle part avec une détermination qui ne serait même pas assez pour effrayer un enfant !" << "\033[0m" << std::endl;
}
