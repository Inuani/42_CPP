#include <iostream>
#include "Animal.hpp"

#ifndef Dog_HPP
# define Dog_HPP

class Dog : public Animal {
public:
	Dog();
	Dog(const Animal& src);
	~Dog();

	Dog&	operator=(const Dog& rhs);
	void			makeSound() const;

private:

};

#endif
