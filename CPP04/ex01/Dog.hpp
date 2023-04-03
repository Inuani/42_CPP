#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef Dog_HPP
# define Dog_HPP

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& src);
	~Dog();

	Dog&	operator=(const Dog& rhs);
	void			makeSound() const;
	std::string*	getIdeas();

private:

	Brain	*_brain;

};

#endif
