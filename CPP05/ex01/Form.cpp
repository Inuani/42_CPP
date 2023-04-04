#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : 
	_title(""),
	_signed(false),
	_gradeMin2Sign(150), 
	_gradeMin2Exec(150) {
}

Form::Form(const std::string& title, int gradeMin2Sign, int gradeMin2Exec) : 
	_title(title),
	_signed(false),
	_gradeMin2Sign(gradeMin2Sign),
	_gradeMin2Exec(gradeMin2Exec) {
}

Form::Form(const Form &src) :
	_title(src._title),
	_signed(src._signed),
	_gradeMin2Sign(src._gradeMin2Sign),
	_gradeMin2Exec(src._gradeMin2Exec) {
}

Form::~Form()
{
}

Form&	Form::operator=(const Form& rhs)
{
	// not sure this can be called operator = 
	// since gradeMin2Sign and 2 Exec can not be changed
	_title = rhs._title;
	_signed = rhs._signed;
	return *this;
}

const std::string&	Form::getTitle() const
{
	 return _title;
}

bool	Form::getIsSigned() const
{
	return _signed;
}

int		Form::getGradeMin2Sign() const
{
	return _gradeMin2Sign;
}

int		Form::getGradeMin2Exec() const
{
	return _gradeMin2Exec;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeMin2Sign)
		throw GradeTooLowException();
	else if (b.getGrade() < 1)
		throw GradeTooHighException();
	else
		_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os	<< "Form " << form.getTitle()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", required grade to sign: " << form.getGradeMin2Sign()
		<< ", required grade to execute: " << form.getGradeMin2Exec();
	return os;
}
