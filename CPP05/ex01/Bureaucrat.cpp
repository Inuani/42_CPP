#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
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

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getTitle() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << _name << " couldn't sign " << form.getTitle() << " because his/her "<< e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << form.getTitle() << " because his/her "<< e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	//takes a ref to std::ostream object (e.g., std::cout)
	os << bureaucrat.getName() << ", bureaucrate grade " << bureaucrat.getGrade();
	return os;
}
