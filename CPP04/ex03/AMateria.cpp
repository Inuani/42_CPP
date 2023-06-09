#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("")
{
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &src)
{
	_type = src._type;
	// *this = src;
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	_type = rhs._type;
	return *this;
}

const std::string &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
