#include "Intern.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& rhs)
{
	if (this != &rhs) {}
	return *this;
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	FormType	formTypes[] = {
		{"ShrubberyCreationForm", &Intern::createShrubberyCreationForm},
		{"RobotomyRequestForm", &Intern::createRobotomyRequestForm},
		{"PresidentialPardonForm", &Intern::createPresidentialPardonForm}
	};

	for (size_t i = 0; i < 3; ++i)
	{
		if (formName == formTypes[i].formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formTypes[i].createForm)(target);
		}
	}

	std::cout << "Intern can NOT creates " << formName << " because it does NOT exist"<< std::endl;
	return NULL;
}

AForm*	Intern::createShrubberyCreationForm(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyRequestForm(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialPardonForm(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}
