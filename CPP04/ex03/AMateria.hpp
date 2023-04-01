#include <iostream>
#include "ICharacter.hpp"

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria {

public:

	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& src);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& rhs);

	const std::string&	getType() const;

	// does not need any parameters because 
	// it is called on an instance of the object
	// so it has access to it !
	virtual AMateria*	clone() const = 0;

	//  can accept objects of any class that inherits from ICharacter
	virtual void use(ICharacter& target);

private:

	std::string	_type;

};

#endif
