#include <iostream>
#include "AForm.hpp"

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

class PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

	virtual void	execute(const Bureaucrat& b) const;

private:

	static const int	_gradeMin2Sign = 25;
	static const int	_gradeMin2Exec = 5;

};

#endif
