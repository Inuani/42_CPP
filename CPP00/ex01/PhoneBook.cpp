
#include "PhoneBook.hpp"
#include <iostream>

#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cctype>

void	PhoneBook::incNbContact()
{
	if (nbContact < MAX_CONTACT)
		nbContact++;
}

int		PhoneBook::getNextIndex() const
{
	return nextIndex - 1;
}

void	PhoneBook::printContact(int index) const
{
	if (nbContact == 0)
	{
		std::cout << "No contact in the phonebook yet." << std::endl;
		return ;
	}
	if (index > nbContact || index < 0)
	{
		std::cout << "No contact at this index." << std::endl;
		return ;
	}
	Contact	contact = contacts[index];
	std::cout << "Index		: " << index << std::endl;
	std::cout << "First name	: " << contact.getFirstName() << std::endl;
	std::cout << "Last name	: " << contact.getLastName() << std::endl;
	std::cout << "Nickname	: " << contact.getNickname() << std::endl;
	std::cout << "Phone number	: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Dark secret	: " << contact.getDarkestSecret() << std::endl;
}

void	PhoneBook::addCmd(PhoneBook& phbk)
{
	std::string	input;

	if (phbk.nextIndex == MAX_CONTACT)
		phbk.nextIndex = 0;
	std::cout << "Enter your first name : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	if (input.empty())
		input = setRandomFirstName();
	phbk.contacts[phbk.nextIndex].setFirstName(input);

	std::cout << "Enter your last name : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	if (input.empty())
		input = setRandomLastName();
	phbk.contacts[phbk.nextIndex].setLastName(input);

	std::cout << "Enter your nickname : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	if (input.empty())
		input = setRandomNickname();
	phbk.contacts[phbk.nextIndex].setNickname(input);

	std::cout << "Enter your phone number : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	if (input.empty())
		input = setRandomPhoneNumber();
	phbk.contacts[phbk.nextIndex].setPhoneNumber(input);

	std::cout << "Enter your darkest secret : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	if (input.empty())
		input = setRandomDarkestSecret();
	phbk.contacts[phbk.nextIndex].setDarkestSecret(input);

	phbk.nextIndex++;
	phbk.incNbContact();
}

void	PhoneBook::printContactInArray(PhoneBook& phbk) const
{
	for (int i = 0; i < nbContact; i++)
	{
		std::string	firstName = phbk.contacts[i].getFirstName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		std::string	lastName = phbk.contacts[i].getLastName();
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		std::string	nickname = phbk.contacts[i].getNickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << "|" << std::setw(10) << i << "|"
		<< std::setw(10) << firstName << "|"
		<< std::setw(10) << lastName << "|"
		<< std::setw(10) << nickname << "|"
		<< std::endl;
		std::cout << " -------------------------------------------" << std::endl;
	}
}

int	checkOnlyDigit(const std::string& input)
{
	for (unsigned long i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (1);
	}
	return (0);
}

void	PhoneBook::searchCmd(PhoneBook& phbk) const
{
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "|     Index"
	<< std::setw(10) << "|First name"
	<< std::setw(10) << "| Last name"
	<< std::setw(10) << "|  Nickname|"
	<< std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	if (nbContact == 0)
	{
		std::cout << "There is no contact to display." << std::endl;
		return ;
	}
	printContactInArray(phbk);
	std::string	input;
	std::cout << "Enter the index of a contact to display : ";
	while (getline(std::cin, input))
	{
		if (input.empty())
			std::cout << "Enter the index of a contact to display : ";
		else
			break ;
	}
	if (input.empty())
	{
		std::cout << std::endl;
		exit(0);
	}
	
	while (true)
	{
		while (checkOnlyDigit(input) || std::stoi(input) < 0 || std::stoi(input) >= nbContact)
		{
			std::cout << "Enter index between 0 and " << (nbContact - 1) << ": ";
			getline(std::cin, input);
		}
		if (input.empty())
    	{
        	std::cout << std::endl;
			continue ;
    	}
    	else if (!checkOnlyDigit(input))
    	{
        	std::cout << "Invalid input. Please enter a valid index." << std::endl;
    	}
		else
			break ;
	}
	if (!input.empty() && checkOnlyDigit(input))
	{
		if (std::stoi(input) >= 0 && std::stoi(input) < nbContact)
			printContact(std::stoi(input));
	}
}
