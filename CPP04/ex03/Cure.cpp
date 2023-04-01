#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &src) : AMateria(src)
{
}

Cure::~Cure()
{
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

Cure&	Cure::operator=(const Cure& rhs)
{
	AMateria::operator = (rhs);
	return *this;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
