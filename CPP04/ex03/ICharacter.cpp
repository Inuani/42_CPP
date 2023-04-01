#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter()
{
}

ICharacter::ICharacter(const ICharacter &src)
{
	*this = src;
}

ICharacter::~ICharacter()
{
}

ICharacter&	ICharacter::operator=(const ICharacter& rhs)
{
	(void)rhs;
	return *this;
}
