#include <iostream>

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& rhs);

private:

};

#endif
