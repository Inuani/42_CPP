#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat"), _brain(new Brain)
{
	for(size_t i = 0; i < 5; i++)
		_brain->setIdea(i, "Mehow cat Id_" +std::to_string(i));
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Meow! A new cat object is born!" << "\033[0m" << std::endl;
}

Cat::Cat(const Cat& src) : AAnimal(src), _brain(new Brain(*src._brain))
{
	for(size_t i = 0; i < 5; i++)
		_brain->setIdea(i, "Mehow cat Id_" +std::to_string(i));
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Creating a new cat object by copying another one... I wonder if they'll get along." << "\033[0m" << std::endl;
	// *this = src;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Goodbye, world! This cat object is leaving the program now." << "\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Copying one cat object to another... This is purr-fect!" << "\033[0m" << std::endl;
	AAnimal::operator=(rhs);
	delete _brain;
	_brain = new Brain(*(rhs._brain));
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "\033[48;2;255;192;203m" << "Purrfect! The Cat is making its signature sound... Now, if only we could patent it." << "\033[0m" << std::endl;
}

std::string*	Cat::getIdeas()
{
	return _brain->getIdeas();
}
