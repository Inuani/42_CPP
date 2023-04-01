#include <iostream>

#ifndef ICharacter_HPP
# define ICharacter_HPP

class ICharacter {
public:
	ICharacter();
	ICharacter(const ICharacter& src);
	~ICharacter();

	ICharacter& operator=(const ICharacter& rhs);

private:

};

#endif
