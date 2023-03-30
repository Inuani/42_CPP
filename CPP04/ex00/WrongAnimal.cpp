#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("Unknown wrong animal")
{
	std::cout << "Welcome to the world, little wrong animal! I hope you like living in a wrong computer program." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout << "Welcome to the world, little wrong " << _type << "! I hope you like living in a wrong computer program." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "Copying a wrong animal... Well, I guess this is how we make more of them." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "RIP, little wrong animal. You lived a good wrong life... in this wrong program." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	_type = rhs._type;
	std::cout << "Are you ready to witness some serious wrong animal copy-and-pasting? Here we go!" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Listen carefully, can you hear it? The majestic wrong animal sound... Oh wait, it's just the sound of wrong silence. Sorry, no wrong refunds." << std::endl;
}

void    WrongAnimal::setType(const std::string& type)
{
	_type = type;
}

const std::string&  WrongAnimal::getType() const
{
	return _type;
}
