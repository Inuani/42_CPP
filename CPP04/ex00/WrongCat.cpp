#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "\033[48;2;211;211;211m" << " [WRONG CAT]: Hiss! A new wrong cat object is born, who needs nine lives when you have infinite wrong ones?" << "\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
	std::cout << "\033[48;2;211;211;211m" << " [WRONG CAT]: Creating a new wrong cat object by copying another one... I wonder if they'll get the wrong idea." << "\033[0m" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[48;2;211;211;211m" << " [WRONG CAT]: Goodbye, cruel world! This wrong cat object is leaving the wrong program now." << "\033[0m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "\033[48;2;211;211;211m" << " [WRONG CAT]: Copying one wrong cat object to another... This is pawsome!" << "\033[0m" << std::endl;
	WrongAnimal::operator=(rhs);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "\033[48;2;255;192;203m" << "Hiss! The wrong cat is making its signature sound... now if only we could declaw it." << "\033[0m" << std::endl;
}

