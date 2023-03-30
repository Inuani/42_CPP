#include <iostream>
#include "Animal.hpp"

#ifndef Cat_HPP
# define Cat_HPP

class Cat : public Animal {
public:
	Cat();
	Cat(const Animal& src);
	~Cat();

	Cat&	operator=(const Cat& rhs);
	void			makeSound() const;

private:

};

#endif
