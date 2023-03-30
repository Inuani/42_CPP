#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Meow! A new cat object is born!" << "\033[0m" << std::endl;
}

Cat::Cat(const Animal& src) : Animal(src)
{
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Creating a new cat object by copying another one... I wonder if they'll get along." << "\033[0m" << std::endl;
	// *this = src;
}

Cat::~Cat()
{
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Goodbye, world! This cat object is leaving the program now." << "\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "\033[48;2;211;211;211m" << " [CAT]: Copying one cat object to another... This is purr-fect!" << "\033[0m" << std::endl;
	Animal::operator=(rhs);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "\033[48;2;255;192;203m" << "Purrfect! The Cat is making its signature sound... Now, if only we could patent it." << "\033[0m" << std::endl;
}
