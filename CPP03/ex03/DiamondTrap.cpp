#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), _name()
{
	setName("_clap_name");
	std::cout << "\033[42m" << "DiamondTrap " << getName() << " surgit des ombres. La combinaison ultime de FragTrap et ScavTrap est là pour vous effrayer !" << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : FragTrap(), ScavTrap(), _name(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	setName(name + "_clap_name");
	std::cout << "\033[42m" << "DiamondTrap " << _name << " est assemblé. Il a le pouvoir d'étonner et d'effrayer en même temps !" << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(), ScavTrap(), _name(src._name)
{
	std::cout << "\033[42m" << "DiamondTrap " << src._name << " a été cloné avec succès. Deux robots redoutables valent mieux qu'un !" << "\033[0m" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[42m" << "DiamondTrap " << _name << " a été détruit... Un autre être formidable disparaît dans l'obscurité." << "\033[0m" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "\033[42m" << "DiamondTrap " << _name << " absorbe la puissance et les compétences de " << rhs._name << ". Une fusion d'énergie pour encore plus de chaos !" << "\033[0m" << std::endl;
	ClapTrap::operator=(rhs);
	_name = rhs._name;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "\033[42m" << "Je suis " << getName() << " et " << _name << ", la fusion parfaite de FragTrap et ScavTrap !" << "\033[0m" << std::endl;
}
