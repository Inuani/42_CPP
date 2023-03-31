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

std::string* Brain::getIdeas( void )
{
	return _ideas;
}

void	Brain::setIdea(size_t i, const std::string& idea)
{
	if (i < 100)
		_ideas[i] = idea;
}
