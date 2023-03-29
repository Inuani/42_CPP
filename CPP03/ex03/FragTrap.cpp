#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
	std::cout << "\033[37m" << "FragTrap default constructor called !" << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "\033[41m" << "FragTrap " << getName() << " est enfin là ! Prêt à vous épater avec ses talents de danse et ses blagues à deux balles." << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "\033[42m" << "FragTrap " << src.getName() << " a été cloné avec succès. Plus on est de fous, plus on rit !" << "\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[40m" << "FragTrap " << getName() << " a été détruit... Pourquoi tout le monde doit-il mourir ?" << "\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "\033[47m" << "FragTrap " << getName() << " absorbe la rage et la détermination de " << rhs.getName() << ". Dommage que tout cela soit gaspillé pour accomplir des tâches aussi inutiles que nettoyer un clavier de PC !" << "\033[0m" << std::endl;
	ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "\033[44m" << "FragTrap " << getName() << " donne des high-fives ! Tant de joie, ça en est presque dérangeant." << "\033[0m" << std::endl;
}
