#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << _name << " apparaît en fanfare, prêt à semer le chaos avec son humour noir !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << src._name << " se multiplie, créant un double tout aussi sarcastique et dangereux !" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " disparaît dans un nuage d'ironie et de sarcasme, te laissant un vide émotionnel..." << std::endl;
}

// rhs is the object you want to copy the data from
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{	
	// std::cout << "ClapTrap " << _name << " absorbe le sarcasme et l'humour noir de " << rhs._name << " pour se réinventer !" << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints += 1;
		std::cout << "ClapTrap " << _name << " attaque " << target << " avec une répartie cinglante, infligeant " << _attackDamage << " points de dégâts et laissant des cicatrices émotionnelles !"<< std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " n'a pas assez d'énergie ou de points de vie pour avoir de la répartie et faire une blague." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " est déjà hors service, pas la peine d'en rajouter." << std::endl;
		return ;
	}
	if (_hitPoints < amount)
		amount = _hitPoints;
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " encaisse " << amount << " points de dégâts, rigolant jaune tout en retenant quelques larmes d'amertume." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " se répare avec " << amount << " points de vie, murmurant des plaisanteries sarcastiques pour masquer sa douleur." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " n'a pas assez d'énergie ou de points de vie pour se réparer." << std::endl;
}

std::string ClapTrap::getName() const { return _name; }

unsigned int	ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::setEnergyPoints(unsigned int amount)
{
	_energyPoints = amount;
}

void ClapTrap::setHitPoints(unsigned int amount)
{
	_hitPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
}
