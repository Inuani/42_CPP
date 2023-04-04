#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

	Bureaucrat	sim("Sim", 10);
	std::cout << sim << std::endl;

	Form	form("contract", 20, 5);
	std::cout << form << std::endl;

	sim.signForm(form);
	std::cout << form.getTitle() << " signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;

	Form	form2("crazy contract", 2, 5);
	std::cout << form2 << std::endl;
	sim.signForm(form2);
	std::cout << form2.getTitle() << " signed: " << (form2.getIsSigned() ? "yes" : "no") << std::endl;

	Bureaucrat	seb("Seb", 150);
	Form	form3("insignificant contract", 150, 145);

	seb.signForm(form3);
	std::cout << form3.getTitle() << " signed: " << (form3.getIsSigned() ? "yes" : "no") << std::endl;

	return 0;
}
