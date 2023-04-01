#include <iostream>

#ifndef Character_HPP
# define Character_HPP

class Character : public ICharacter {

public:

	Character();
	Character(const std::String& name);
	Character(const Character& src);
	~Character();

	const	std::string&	getName() const;
	void	equip(AMateria* mat);

	Character& operator=(const Character& rhs);

private:

	std::string	_name;
	AMateria*	_inventory[4];

};

#endif
