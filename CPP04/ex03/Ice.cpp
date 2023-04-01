#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

// copy const of AMateria class invoked.
Ice::Ice(const Ice &src) : AMateria(src)
{
	// *this = src; // possible but not recommended
}

Ice::~Ice()
{
}

// clone instead of calling construc.
// but still call the copy construc and return pointer
Ice* Ice::clone() const
{
	return new Ice(*this);
}

Ice&	Ice::operator=(const Ice& rhs)
{
	// since no data member in Ice, no need to do anything else than calling op= of Materia
	AMateria::operator = (rhs);
	return *this;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}
