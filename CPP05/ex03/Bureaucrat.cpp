#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

Bureaucrat::~Bureaucrat() {
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

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getTitle() << std::endl;
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout << _name << " couldn't sign " << form.getTitle() << " because his/her "<< e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << form.getTitle() << " because his/her "<< e.what() << std::endl;
	}
	// Handle the exceptions within the function 
	// allows to encapsulate the error handling
	// logic within the function.
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

void	Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << getName() << " executed "<< form.getTitle() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << getName() << " "<< e.what() << " to execute " << form.getTitle() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << form.getTitle() << " couldn't be executed by " << getName() << " because the " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	//takes a ref to std::ostream object (e.g., std::cout)
	os << bureaucrat.getName() << ", bureaucrate grade " << bureaucrat.getGrade();
	return os;
}
