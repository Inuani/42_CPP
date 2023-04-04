#include <iostream>
#include "AForm.hpp"

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& src);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

private:

};

#endif
