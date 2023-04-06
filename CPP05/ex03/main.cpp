#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{

	Bureaucrat	sim("Sim", 3);
	std::cout << sim << std::endl;

	Intern	intern;

	std::cout << std::endl;
	std::string formNames[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm",
		"UndefinedForm"
	};

	for (size_t i = 0; i < 4; ++i)
	{
		AForm* form = intern.makeForm(formNames[i], "Suzy");
		if (form != NULL)
		{
			sim.signForm(*form);
			sim.executeForm(*form);
			delete form;
		}
		std::cout << std::endl;
	}
	
	{
		// given in the subject:
		Intern someRandomIntern;
		
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		delete rrf;
	}

	return 0;
}
