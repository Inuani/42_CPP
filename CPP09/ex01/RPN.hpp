#include <iostream>

// very good video to understand RPN - source for algo : https://www.youtube.com/watch?v=7ha78yWRDlE

#ifndef RPN_HPP
# define RPN_HPP

class RPN {

public:

	RPN();
	RPN(const RPN& src);
	~RPN();

	RPN& operator=(const RPN& rhs);

	int	doingRPN(const std::string& input);

private:

};

#endif
