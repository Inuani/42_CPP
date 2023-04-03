#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	_grade = rhs._grade;
	_name = rhs._name;
	return *this;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

const	std::string& Bureaucrat::getName() const
{
	return _name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
