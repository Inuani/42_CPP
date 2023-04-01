#include <iostream>
#include "AMateria.hpp"

#ifndef CURE_HPP
# define CURE_HPP

class Cure : public AMateria {

public:

	Cure();
	Cure(const Cure& src);
	virtual ~Cure();

	Cure&	operator=(const Cure& rhs);

	virtual void	use(ICharacter& target);
	Cure*	clone() const;

private:

};

#endif
