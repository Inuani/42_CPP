#include <iostream>
#include "WrongAnimal.hpp"

#ifndef WrongCat_HPP
# define WrongCat_HPP

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	WrongCat(const WrongCat& src);
	~WrongCat();
	void			makeSound() const;

	WrongCat& operator=(const WrongCat& rhs);

private:

};

#endif
