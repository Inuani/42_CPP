#include <iostream>
#include "AMateria.hpp"

#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria {

public:

	Ice();
	Ice(const Ice& src);
	virtual ~Ice();

	Ice& operator=(const Ice& rhs);

	Ice* clone() const;
	virtual void use(ICharacter& target);

private:

};

#endif
