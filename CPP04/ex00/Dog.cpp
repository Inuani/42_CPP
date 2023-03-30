#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: New dog object created!" << "\033[0m" << std::endl;
}

Dog::Dog(const Animal& src) : Animal(src)
{
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: Copying another dog object... Who let the dogs out?!" << "\033[0m" << std::endl;
	// *this = src;
}

Dog::~Dog()
{
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: Goodbye, world! This dog object is leaving the program now." << "\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "\033[48;2;139;69;19m" << " [DOG]: Copying one dog object to another..." << "\033[0m" << std::endl;
	Animal::operator=(rhs);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "\033[48;2;210;105;30m" << "Woof woof! That's the sound of a happy Dog, wagging its tail." << "\033[0m" << std::endl;
}
