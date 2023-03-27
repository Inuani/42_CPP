#include "Glouky.hpp"
#include <iostream>


Glouky::Glouky()
{
	_levels[0]._level = "DEBUG";
	_levels[0].func = &Glouky::debug;

	_levels[1]._level = "INFO";
	_levels[1].func = &Glouky::info;

	_levels[2]._level = "WARNING";
	_levels[2].func = &Glouky::warning;

	_levels[3]._level = "ERROR";
	_levels[3].func = &Glouky::error;
}

Glouky::~Glouky()
{
}

void Glouky::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (_levels[i]._level == level)
		{
			(this->*(_levels[i].func))();
			break ;
		}
	}
}

void Glouky::debug(void)
{
	std:: cout << "Detected a time-traveling customer."<< std::endl;
	std:: cout << "Coordinates: 12.34, -56.78. Year: 2050." << std::endl;
	std:: cout << std::endl;
}

void Glouky::info(void)
{
	std:: cout << "Alien customer has placed an order: "<< std::endl;
	std::cout << "'One burger with moon cheese and Martian ketchup, please.'" << std::endl;
	std:: cout << std::endl;
}

void Glouky::warning(void)
{
	std:: cout << "Zombie invasion in progress."<< std::endl;
	std::cout << "Recommend offering free brain-flavored milkshakes to appease them." << std::endl;
	std:: cout << std::endl;
}

void Glouky::error(void)
{
	std:: cout << "Catastrophic event detected: The burger machine "<< std::endl;
	std::cout << "has become sentient and is holding the pickles hostage!" << std::endl;
	std:: cout << std::endl;
}
