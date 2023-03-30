#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
}

Brain::Brain(const Brain &src)
{
	*this = src;
}

Brain::~Brain()
{
}

Brain&	Brain::operator=(const Brain& rhs)
{
	(void)rhs;
	return *this;
}
