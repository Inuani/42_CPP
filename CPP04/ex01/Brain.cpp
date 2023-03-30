#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = "id_" + std::to_string(i);
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
	for(int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return *this;
}
