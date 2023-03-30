#include <iostream>

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& src);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& rhs);
	virtual void		makeSound() const;
	void				setType(const std::string& type);
	const std::string&	getType() const;

private:

	std::string	_type;

};

#endif

