#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << _name << " apparaît en fanfare, prêt à semer le chaos avec son humour noir !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << _name << " se multiplie, créant un double tout aussi sarcastique et dangereux !" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " disparaît dans un nuage d'ironie et de sarcasme, laissant un vide émotionnel..." << std::endl;
}

// rhs is the object you want to copy the data from
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap " << _name << " absorbe le sarcasme et l'humour noir de " << rhs._name << " pour se réinventer !" << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints )
	std::cout << "ClapTrap " << _name << " attaque " << target << " une répartie cinglante, infligeant <damage> points de dégâts et laissant des cicatrices émotionnelles !"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " encaisse " << amount << " points de dégâts, rigolant jaune tout en retenant quelques larmes d'amertume." << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " se répare avec " << amount << " points de vie, murmurant des plaisanteries sarcastiques pour masquer sa douleur." << std::endl;
}
