#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : 
	_title(""),
	_signed(false),
	_gradeMin2Sign(150), 
	_gradeMin2Exec(150) {
}

AForm::AForm(const std::string& title, int gradeMin2Sign, int gradeMin2Exec) : 
	_title(title),
	_signed(false),
	_gradeMin2Sign(gradeMin2Sign),
	_gradeMin2Exec(gradeMin2Exec) {
}

AForm::AForm(const AForm &src) :
	_title(src._title),
	_signed(src._signed),
	_gradeMin2Sign(src._gradeMin2Sign),
	_gradeMin2Exec(src._gradeMin2Exec) {
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(const AForm& rhs)
{
	// not sure this can be called operator = 
	// since gradeMin2Sign and 2 Exec can not be changed
	_title = rhs._title;
	_signed = rhs._signed;
	return *this;
}

const std::string&	AForm::getTitle() const
{
	 return _title;
}

bool	AForm::getIsSigned() const
{
	return _signed;
}

int		AForm::getGradeMin2Sign() const
{
	return _gradeMin2Sign;
}

int		AForm::getGradeMin2Exec() const
{
	return _gradeMin2Exec;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeMin2Sign)
		throw GradeTooLowException();
	else if (b.getGrade() < 1)
		throw GradeTooHighException();
	else
		_signed = true;
}

const std::string&	AForm::getTarget() const
{
	return _target;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os	<< "Form " << form.getTitle()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", required grade to sign: " << form.getGradeMin2Sign()
		<< ", required grade to execute: " << form.getGradeMin2Exec();
	return os;
}

AForm::AForm(const std::string& title, int gradeMin2Sign, int gradeMin2Exec, const std::string& target) 
	: _title(title),
	_signed(false),
	_gradeMin2Sign(gradeMin2Sign),
	_gradeMin2Exec(gradeMin2Exec),
	_target(target) {
}
