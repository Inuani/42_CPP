#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Robotomy demand", _gradeMin2Sign, _gradeMin2Exec, "defaultTarget") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Robotomy demand", _gradeMin2Sign, _gradeMin2Exec, target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src) {
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	AForm::operator=(rhs);
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	// bool keepGoing = true;
	// try
	// {
		if (!getIsSigned())
			throw FormNotSignedException();
		if (b.getGrade() > _gradeMin2Exec)
			throw GradeTooLowException();
	// }
	// catch (const GradeTooLowException& e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// 	keepGoing = false;
	// } catch (const FormNotSignedException& e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// 	keepGoing = false;
	// }
	// if (!keepGoing)
	// 	return ;
	std::cout << getTarget() << " is forgiven by Zaphod Beeblebrox." << std::endl;
}
