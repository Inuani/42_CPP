#include <iostream>
#include "AMateria.hpp"

#ifndef CURE_HPP
# define CURE_HPP

class Cure : public AMateria {

public:

	Cure();
	Cure(const Cure& src);
	~Cure();

	Cure& operator=(const Cure& rhs);

private:

};

#endif
