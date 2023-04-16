#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	(void)rhs;
	return *this;
}
