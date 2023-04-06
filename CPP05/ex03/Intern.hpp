#include <iostream>
#include "AForm.hpp"

#ifndef Intern_HPP
# define Intern_HPP

class Intern {

public:

	Intern();
	Intern(const Intern& src);
	~Intern();

	Intern& operator=(const Intern& rhs);

	AForm*	makeForm(const std::string& formTitle, const std::string& target);

private:

	struct FormType {
		std::string	formName;
		// createForm is the name of the pointer to the member function
		// (const std::string&) is the parameter type of the member function
		AForm* (Intern::*createForm)(const std::string&) const;
	};

	// have the same signature as the member function pointer: 
	// they return AForm*
	// they take const std::string& as parameter
	// they are const
	AForm*	createShrubberyCreationForm(const std::string& target) const;
	AForm*	createRobotomyRequestForm(const std::string& target) const;
	AForm*	createPresidentialPardonForm(const std::string& target) const;

};

#endif
