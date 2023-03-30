#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Unknown animal")
{
	std::cout << "Welcome to the world, little Animal! I hope you like living in a computer program." << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Welcome to the world, little " << _type << "! I hope you like living in a computer program." << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Copying an Animal... Well, I guess this is how we make more of them." << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "RIP, little Animal. You lived a good life... in this program." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	_type = rhs._type;
	std::cout << "Are you ready to witness some serious Animal copy-and-pasting? Here we go!" << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Listen carefully, can you hear it? The majestic Animal sound... Oh wait, it's just the sound of silence. Sorry, no refunds." << std::endl;
}

void	Animal::setType(const std::string& type)
{
	_type = type;
}

const std::string&	Animal::getType() const
{
	return _type;
}

