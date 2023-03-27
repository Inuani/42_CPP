#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {

	public:

	PhoneBook () : nbContact(0), nextIndex(0) {}
	
	~PhoneBook () {}
	
	void	incNbContact();
	void	addCmd(PhoneBook& phbk);
	int		getNextIndex() const;
	void	printContact(int index) const;
	void	searchCmd(PhoneBook& phbk) const;

	private :

	static const int MAX_CONTACT = 8;
	Contact contacts[MAX_CONTACT];
	int		nbContact;
	int		nextIndex;

	std::string	setRandomFirstName() const;
	std::string	setRandomLastName() const;
	std::string	setRandomNickname() const;
	std::string	setRandomPhoneNumber() const;
	std::string	setRandomDarkestSecret() const;
	void	printContactInArray(PhoneBook& phbk) const;
};

#endif
