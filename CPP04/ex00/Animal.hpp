#include <iostream>

#ifndef Animal_HPP
# define Animal_HPP

class Animal {

public:

	Animal();
	Animal(const std::string& type);
	Animal(const Animal& src);
	virtual ~Animal();

	Animal& 		operator=(const Animal& rhs);
	virtual void			makeSound() const;
	void			setType(const std::string& type);
	const std::string&	getType() const;

private:

	std::string	_type;

};

#endif
