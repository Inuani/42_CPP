#include <iostream>
#include "AForm.hpp"

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

class ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

	virtual void	execute(const Bureaucrat& b) const;

private:

	// static make sit shared among all instances of the class
	// since it is a constant associated with the class itself
	static const int	_gradeMin2Sign = 145;
	static const int	_gradeMin2Exec = 137;
};

#endif
