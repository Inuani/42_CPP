#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy demand", _gradeMin2Sign, _gradeMin2Exec, "defaultTarget") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy demand", _gradeMin2Sign, _gradeMin2Exec, target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src) {
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	AForm::operator=(rhs);
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& b) const
{
		if (!getIsSigned())
			throw FormNotSignedException();
		if (b.getGrade() > _gradeMin2Exec)
			throw GradeTooLowException();
	std::srand(std::time(nullptr));
	int robotOrNot = std::rand() % 2;
	if (robotOrNot)
		std::cout << "Robotomy on " << getTarget() << ": SUCCESS !" << std::endl;
	else
		std::cout << "Robotomy on " << getTarget() << ": FAILURE !" << std::endl;
}
