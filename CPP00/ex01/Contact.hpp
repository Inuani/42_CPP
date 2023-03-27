#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

	public:

	Contact() {}

	~Contact() {}

	void		setFirstName(const std::string& name);
	void		setDarkestSecret(const std::string& secret);
	void		setPhoneNumber(const std::string& number);
	void		setNickname(const std::string& name);
	void		setLastName(const std::string& name);
	std::string	getFirstName() const;
	std::string	getDarkestSecret() const;
	std::string	getPhoneNumber() const;
	std::string	getNickname() const;
	std::string	getLastName() const;

	private:

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string	phoneNumber;
	std::string darkestSecret;
};

#endif
