#include <iostream>
#include "AForm.hpp"

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

class PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& src);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

private:

};

#endif
