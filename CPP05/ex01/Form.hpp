#include <iostream>

#ifndef Form_HPP
# define Form_HPP

class Bureaucrat;

class Form {

public:

	class GradeTooHighException : public std::exception
	{
		public :
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
		const char *what() const throw();
	};

	Form();
	Form(const std::string& title, int gradeMin2Sign, int gradeMin2Exec);
	Form(const Form& src);
	~Form();

	Form& operator=(const Form& rhs);

	const std::string&	getTitle() const;
	bool	getIsSigned() const;
	int		getGradeMin2Sign() const;
	int		getGradeMin2Exec() const;
	void	beSigned(const Bureaucrat& bureaucrat);

private:

	std::string	_title;
	bool		_signed;
	const int	_gradeMin2Sign;
	const int	_gradeMin2Exec;

};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
