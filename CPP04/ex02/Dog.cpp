#include "Dog.hpp"
#include <iostream>


Dog::Dog() : AAnimal("Dog"), _brain(new Brain)
{
		for(size_t i = 0; i < 5; i++)
			_brain->setIdea(i, "Wif dog Id_" +std::to_string(i));
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: New dog object created!" << "\033[0m" << std::endl;
}

Dog::Dog(const Dog& src) : AAnimal(src), _brain(new Brain(*src._brain))
{
	for(size_t i = 0; i < 5; i++)
		_brain->setIdea(i, "Wif dog Id_" +std::to_string(i));
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: Copying another dog object... Who let the dogs out?!" << "\033[0m" << std::endl;
	// *this = src;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: Goodbye, world! This dog object is leaving the program now." << "\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: Copying one dog object to another..." << "\033[0m" << std::endl;
	AAnimal::operator=(rhs);
	delete _brain;
	_brain = new Brain(*(rhs._brain));
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "\033[48;2;210;105;30m" << "Woof woof! That's the sound of a happy Dog, wagging its tail." << "\033[0m" << std::endl;
}

std::string* Dog::getIdeas()
{
	return _brain->getIdeas();
}
