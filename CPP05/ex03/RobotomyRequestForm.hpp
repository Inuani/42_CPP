#include <iostream>
#include "AForm.hpp"

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

	virtual void	execute(const Bureaucrat& b) const;

private:

	static const int	_gradeMin2Sign = 72;
	static const int	_gradeMin2Exec = 45;

};

#endif
