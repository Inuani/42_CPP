#include "Character.hpp"
#include <iostream>

Character::Character()
{
}

Character::Character(const Character &src)
{
	*this = src;
}

Character::~Character()
{
}

Character&	Character::operator=(const Character& rhs)
{
	(void)rhs;
	return *this;
}
