#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
}

Cure::Cure(const Cure &src)
{
	*this = src;
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(const Cure& rhs)
{
	(void)rhs;
	return *this;
}
