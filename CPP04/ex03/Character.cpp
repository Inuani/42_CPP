#include "Character.hpp"
#include <iostream>

Character::Character() : _name("") //, _droppedMaterias(nullptr)
{
	for(int i = 0; i < 4 ; ++i)
		_inventory[i] = nullptr;
}

Character::Character(const std::string& name) : _name(name) //,_droppedMaterias(nullptr)
{
	for(int i = 0; i < 4 ; ++i)
		_inventory[i] = nullptr;
}

Character::Character(const Character &src)
{
	_name = src._name;
	for(int i = 0; i < 4 ; i++)
	{
		if (src._inventory[i] != nullptr)
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character::~Character()
{
	for(int i = 0; i < 4 ; ++i)
	{
		if (_inventory[i] != nullptr)
			delete _inventory[i];
	}
	// MateriaNode *cur = _droppedMaterias;
	// while(cur != nullptr)
	// {
	// 	MateriaNode* nextNode = cur->next;
	// 	if (cur->materia != nullptr)
	// 	{
	// 		delete cur->materia;
	// 		cur->materia = nullptr;
	// 	}
	// 	delete cur;
	// 	cur = nextNode;
	// }
}

Character&	Character::operator=(const Character& rhs)
{
	_name = rhs._name;
	for (int i =0; i < 4 ; i++)
	{
		if (_inventory[i] != nullptr)
			delete _inventory[i];
		if (rhs._inventory[i] != nullptr)
			_inventory[i] = rhs._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	return *this;
}

const	std::string&	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* mat)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = mat;
			// removeFromDroppedMaterias(mat);
			return ;
		}
	}
}

void	Character::unequip(int i)
{
	if (i >= 0 && i < 4 && _inventory[i] != nullptr)
	{
		// dropMateria(i);
		_inventory[i] = nullptr;
	}
}

// void Character::dropMateria(int i)
// {
// 	if (i >= 0 && i < 4 && _inventory[i] != nullptr)
// 	{
// 		MateriaNode* cur = _droppedMaterias;
// 		bool found = false;
// 		while (cur != nullptr)
// 		{
// 			if (cur->materia == _inventory[i])
// 			{
// 				found = true;
// 				break ;
// 			}
// 			cur = cur->next;
// 		}
// 		if (!found)
// 		{
// 			MateriaNode* newNode = new MateriaNode;
// 			newNode->materia = _inventory[i];
// 			newNode->next = _droppedMaterias;
// 			_droppedMaterias = newNode;
// 			newNode->next = nullptr;
// 		}
// 	}
// }

// void Character::removeFromDroppedMaterias(AMateria* mat)
// {
// 	MateriaNode *prev = nullptr;
// 	MateriaNode *cur = _droppedMaterias;
// 	while (cur != nullptr)
// 	{
// 		if (cur->materia == mat)
// 		{
// 			if (prev != nullptr)
// 				prev->next = cur->next;
// 			else
// 				_droppedMaterias = cur->next;
// 			cur->materia = nullptr;
// 			delete cur;
// 			return;
// 		}
// 		prev = cur;
// 		cur = cur->next;
// 	}
// }

void	Character::use(int i, ICharacter& target)
{
	if (i >= 0 && i < 4 && _inventory[i] != nullptr)
		_inventory[i]->use(target);
	// use method of the AMateria obj
}
