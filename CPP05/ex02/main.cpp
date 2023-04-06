#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{

	Bureaucrat	sim("Sim", 3);
	std::cout << sim << std::endl;

	std::cout << std::endl;
	std::cout << "Shrubbery Form:" <<std::endl;
	std::cout << std::endl;
	ShrubberyCreationForm	form("jardin");
	std::cout << form << std::endl;
	sim.signForm(form);
	std::cout << form.getTitle() << " signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
	sim.executeForm(form);
	
	Bureaucrat	seb("Seb", 145);
	ShrubberyCreationForm	form2("hall");
	std::cout << form2 << std::endl;
	seb.signForm(form2);
	std::cout << form2.getTitle() << " signed: " << (form2.getIsSigned() ? "yes" : "no") << std::endl;

	seb.executeForm(form2);

	std::cout << std::endl;
	std::cout << "Robotomy Form:" <<std::endl;
	std::cout << std::endl;

	Bureaucrat				leo("Leo", 70);
	RobotomyRequestForm		form3("Olga");

	leo.executeForm(form3);
	leo.signForm(form3);
	leo.executeForm(form3);
	sim.executeForm(form3);

	std::cout << std::endl;
	std::cout << "Presidential Pardon Form:" <<std::endl;
	std::cout << std::endl;

	PresidentialPardonForm	form4("Ulysse");
	leo.signForm(form4);

	sim.executeForm(form4);
	sim.signForm(form4);
	sim.executeForm(form4);


	return 0;
}
