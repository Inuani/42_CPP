#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs) {
	_vec = rhs._vec;
	_lst = rhs._lst;
	return *this;
}

void	PmergeMe::printVec() {
	std::cout << "VEC :" << std::endl;
	for(unsigned int i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << std::endl;
}

void	PmergeMe::printList() {
	std::list<int>::iterator	it;
	std::cout << "LIST :" << std::endl;
	for(it = _lst.begin(); it != _lst.end(); ++it)
		std::cout << *it << std::endl;
}

void	PmergeMe::parseInput(int& ac, char** av) {
	if (ac < 2)
		throw std::runtime_error ("usage: ./PmergeMe <list of positive intergers>");
	for (int i = 1; i < ac; ++i) {
		std::istringstream	iss(av[i]);
		int					nb;
		char				remain;
		if (!(iss >> nb) || nb < 0 || iss >> remain)
			throw std::runtime_error ("invalid input: provide a list of positive integer only.");
		_vec.push_back(nb);
		_lst.push_back(nb);
	}
}

void	PmergeMe::vecRecursionMergeSort(std::vector<int>& vec) {
	if (vec.size() <= 1)
		return ;
	int	middle = vec.size() / 2; //rounded down to nearest int if odd nb in the vec

	// using std vector constructor that takes 2 iterators. the 1st iterator is included and the last is not included !!
	std::vector<int> left(vec.begin(), vec.begin() + middle); // up but not including the middle element
	std::vector<int> right(vec.begin() + middle, vec.end()); // middle element included

	vecRecursionMergeSort(left);
	vecRecursionMergeSort(right);
}

void	PmergeMe::listRecursionMergeSort(std::list<int>& lst) {
	if (_lst.size() <= 1)
		return ;
	
	int	middle = lst.size() / 2;
	std::list<int> left(lst.begin(), );
	std::list<int> right();
}

void	PmergeMe::mergeSort() {
	vecRecursionMergeSort(_vec);
	listRecursionMergeSort(_lst);
}

