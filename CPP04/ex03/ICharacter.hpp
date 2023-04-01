#include <iostream>

#ifndef ICharacter_HPP
# define ICharacter_HPP

class AMateria;

class ICharacter {

public:

	//virtual destruc to be sure it is the destruc of derived class that will be called
	virtual 		~ICharacter() {};
	virtual const	std::string&	getName() const = 0;
	virtual void	equip(AMateria* mat) = 0;
	virtual void	unequip(int i) = 0;
	virtual void	use(int i, ICharacter& target) = 0;

private:

};

#endif
