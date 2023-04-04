#include <iostream>
#include <stdexcept>

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

class AForm;

class Bureaucrat {

public:

	class GradeTooHighException : public std::exception // my custom std::exception
	{
		public :
		const char *what() const throw();
		// what function is a virtual member function std::exception class, 
		// The purpose of what() function is to return a string that represents an error/exception
	};

	class GradeTooLowException : public std::exception
	{
		public :
		const char *what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& rhs);

	int		getGrade() const;
	const	std::string& getName() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(AForm& form);

private:

	std::string		_name;
	int				_grade;

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
// overload an operator outside a class, it allows to use the operator in a more natural way,
// just like you would with built-in types.
// If you were to declare the operator<< function as a member function of the Bureaucrat class,
// the syntax for using it would be less intuitive :
//Bureaucrat b("John", 42);
// b.operator<<(std::cout);

#endif
