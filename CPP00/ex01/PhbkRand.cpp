#include "PhoneBook.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


std::string	PhoneBook::setRandomFirstName() const
{
	const std::string	firstNames[10] = {"Kevin", "Theo", "Nicolas", "Sophia", "Hajar", "Leonard", "Maxime", "Shai", "Shaolin", "Xenia"};
	
	std::srand(std::time(nullptr));
	int index = std::rand() % 10;
	std::string randName = firstNames[index];
	
	return randName;
}

std::string	PhoneBook::setRandomLastName() const
{
		const std::string	lastNames[10] = {"Grivel", "Sabir", "Di-noce", "Gentil", "Jerdos", "Koulen", "Genevey", "Sanchez", "Guerga", "Zito"};
	
	std::srand(std::time(nullptr));
	int index = std::rand() % 10;
	std::string randName = lastNames[index];
	
	return randName;
}

std::string	PhoneBook::setRandomNickname() const
{
		const std::string	nicknames[10] = {"Scooter", "Bubbles", "Ziggy", "Muffin", "Pumpkin", "Buttercup", "Buddy", "Fluffy", "Noodle", "Ducky"};
	
	std::srand(std::time(nullptr));
	int index = std::rand() % 10;
	std::string randName = nicknames[index];
	
	return randName;
}

std::string	PhoneBook::setRandomPhoneNumber() const
{
		const std::string	phoneNumber[10] = {"+1 123-456-7890", "+44 7890-123456", "+81 90-1234-5678", "+49 176-12345678", "+86 186-1234-5678", "+61 411-123-456", "+971 50-123-4567", "+27 82-123-4567", "+55 21 98765-4321", "+852 9123-4567"};
	
	std::srand(std::time(nullptr));
	int index = std::rand() % 10;
	std::string randNumber = phoneNumber[index];
	
	return randNumber;
}

std::string	PhoneBook::setRandomDarkestSecret() const
{
		const std::string	darkestSecrets[10] = {	"I secretly believe that all plants are trying to kill me",
													"I can only sleep while listening to heavy metal music",
													"I have a collection of over 100 rubber ducks",
													"I still sleep with a teddy bear every night",
													"I'm convinced that I'm actually a superhero, but my powers haven't kicked in yet",
													"I have a phobia of spoons",
													"I have a shrine dedicated to my favorite celebrity in my closet",
													"I believe that aliens have already invaded Earth and are just hiding among us",
													"I can't stand the taste of pizza",
													"I once tried to learn how to speak Klingon in my free time"};
	std::srand(std::time(nullptr));
	int index = std::rand() % 10;
	std::string randSecret = darkestSecrets[index];
	
	return randSecret;
}

