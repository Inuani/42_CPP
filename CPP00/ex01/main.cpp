#include "PhoneBook.hpp"
#include <iostream>


int	main( void)
{
	std::cout << "Welcome to your awesome phonebook !"<< std::endl;
	std::cout << "Available commands :"<< std::endl;
	std::cout << "ADD to register a new contact" << std::endl;
	std::cout << "SEARCH a contact to display" << std::endl;
	std::cout << "EXIT to quit" << std::endl;
	std::cout << std::endl;

	PhoneBook	phbk;
	std::string		input;
	while (true)
	{
		std::cout << "Please enter a command : ";
		getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (input == "SEARCH")
			phbk.searchCmd(phbk);
		else if (input == "ADD")
			phbk.addCmd(phbk);
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please enter SEARCH, ADD, or EXIT." << std::endl;
	}
	return (0);
}
