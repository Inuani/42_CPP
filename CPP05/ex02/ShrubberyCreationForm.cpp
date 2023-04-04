#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery emanation", _gradeMin2Sign, _gradeMin2Exec, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src)	{
	// uses copy constructor of AForm
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	AForm::operator=(rhs);
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (b.getGrade() > _gradeMin2Exec)
		throw GradeTooLowException();
	std::ofstream file(getTarget() + "_shrubbery");
	if (file.is_open())
	{
		file << "  /\\  " << std::endl;
		file << " /\\*\\ " << std::endl;
		file << "/\\O\\*\\ " << std::endl;
		file.close();
	}
	else
		throw std::runtime_error("Unable to open file for writing.");

}
