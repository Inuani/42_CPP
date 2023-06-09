#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery emanation", _gradeMin2Sign, _gradeMin2Exec, "defaultTarget") {
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
	std::ofstream file(getTarget() + "_shrubbery");
	if (file.is_open())
	{
		file << "         &&& &&  & && &&&" << std::endl;
		file << "      && &\\/&\\|() ()/ @* && &&&" << std::endl;
		file << "       & ()(/&\\|&& ()\\/&\\|&& &&&" << std::endl;
		file << "   &&& /\\||/()|/&\\/%%\\ /\\&& &&&" << std::endl;
		file << "  && &/ /&||/& ()\\/&\\|()& /&& &&&" << std::endl;
		file << "  &  / (_)---/&&\\ o /& ()\\&& &&&" << std::endl;
		file << "  &&/ /\\%()| /& o |&&-&& &\\ && &&&" << std::endl;
		file << "   &&/   &|||/\\ |/\\ %/| /  (_)---/" << std::endl;
		file << "     &&()\\/%|/&& &/\\|_(___(_)\\/ &&&" << std::endl;
		file << "     (%&&&/ &&-&&\\|| &&&&&---& &&&" << std::endl;
		file << "        &&&&_&& &&&& &\\ && / /&/\\%" << std::endl;
		file << "           &&&&  &&\\||| /_&& " << std::endl;
		file << "              &&& &&&" << std::endl;
		file << "              &&& &&&" << std::endl;
		file << "              &&& &&&" << std::endl;
		file << "              &&& &&&" << std::endl;
		file << "              &&& &&&" << std::endl;
		file << "              &&& &&&" << std::endl;
		file << "              &&& &&&" << std::endl;
		file << "              &&& &&&" << std::endl;
		file.close();
	}
	else
		throw std::runtime_error("Unable to open file for writing.");
}
