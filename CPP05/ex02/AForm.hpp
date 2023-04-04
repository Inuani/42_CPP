#include <iostream>

#ifndef Form_HPP
# define Form_HPP

class Bureaucrat;

class AForm {

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

	class FormNotSignedException : public std::exception
	{
		public :
		const char *what() const throw();
	};

	AForm();
	AForm(const std::string& title, int gradeMin2Sign, int gradeMin2Exec);
	AForm(const AForm& src);
	~AForm();

	AForm& operator=(const AForm& rhs);

	const std::string&	getTitle() const;
	bool				getIsSigned() const;
	int					getGradeMin2Sign() const;
	int					getGradeMin2Exec() const;
	const std::string&	getTarget() const;
	
	virtual void	beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& b) const = 0;

protected:

	AForm(const std::string& title, int gradeMin2Sign, int gradeMin2Exec, const std::string& target);

private:

	std::string	_title;
	bool		_signed;
	const int	_gradeMin2Sign;
	const int	_gradeMin2Exec;
	std::string	_target;

};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
