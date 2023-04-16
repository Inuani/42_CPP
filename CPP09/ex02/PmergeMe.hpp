#include <iostream>

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& rhs);

private:

};

#endif
