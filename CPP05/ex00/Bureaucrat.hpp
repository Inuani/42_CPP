#include <iostream>

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

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

private:

	std::string		_name;
	int				_grade;

};

#endif
