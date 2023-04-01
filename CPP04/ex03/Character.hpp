#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#ifndef Character_HPP
# define Character_HPP

class Character : public ICharacter {

public:

	Character();
	Character(const std::string& name);
	Character(const Character& src);
	~Character();

	const	std::string&	getName() const;
	void	equip(AMateria* mat);
	void	unequip(int i);
	void	use(int i, ICharacter& target);
	// void	dropMateria(int i);
	// void	removeFromDroppedMaterias(AMateria* mat);

	Character& operator=(const Character& rhs);

private:

	std::string	_name;
	AMateria*	_inventory[4];

	// struct MateriaNode {
	// 	AMateria* materia;
	// 	MateriaNode* next;
	// };

	// MateriaNode* _droppedMaterias;
};

#endif
