#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <sys/time.h>

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
	// std::cout << "VEC :" << std::endl;
	for(unsigned int i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " "; //<< std::endl;
	std::cout << std::endl;
}

void	PmergeMe::printList() {
	std::list<int>::iterator	it;
	// std::cout << "LIST :" << std::endl;
	for(it = _lst.begin(); it != _lst.end(); ++it)
		std::cout << *it << " "; //<< std::endl;
	std::cout << std::endl;
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

void	PmergeMe::mergeSort() {
	std::cout << "Before:	";
	printVec();
	clock_t start = clock();
	recursionMergeSort<std::vector<int> >(_vec.begin(), _vec.end());
	clock_t end = clock();
	double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	start = clock();
	recursionMergeSort<std::list<int> >(_lst.begin(), _lst.end());
	end = clock();
	double listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "After:	";
	printList();
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << nbOfElem<std::vector<int> >(_vec.begin(), _vec.end()) << " elements with std::vec	: " << vecTime * 100 << " us" << std::endl;
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << nbOfElem<std::list<int> >(_lst.begin(), _lst.end()) << " elements with std::list	: " << listTime * 100<< " us"<< std::endl;


	// vecRecursionMergeSort(_vec.begin(), _vec.end());
	// listRecursionMergeSort(_lst.begin(), _lst.end());
}








// void	vecMerge(std::vector<int>::iterator first, std::vector<int>::iterator middle, std::vector<int>::iterator last) {
	
// 	std::vector<int> tmp(first, last);

// 	std::vector<int>::iterator left = tmp.begin();
// 	std::vector<int>::iterator leftEnd = tmp.begin();
// 	std::vector<int>::iterator right = tmp.begin();
// 	std::vector<int>::iterator rightEnd = tmp.end();

// 	// move leftEnd and right iterator to the middle point
// 	int	i = 0;
// 	for (std::vector<int>::iterator it = first; it != middle; ++it)
// 		++i;
// 	for (int j = 0; j < i; ++j) {
// 		++leftEnd;
// 		++right;
// 	}

// 	// iterate through the original vector
// 	for (std::vector<int>::iterator it = first; it != last; ++it) {
// 		if (left == leftEnd) {
// 			*it = *right;
// 			++right;
// 		} else if (right == rightEnd) {
// 			*it = *left;
// 			++left;
// 		} else if (*left < *right) {
// 			*it = *left;
// 			++left;
// 		} else {
// 			*it = *right;
// 			++right;
// 		}
// 	}
// }

// void PmergeMe::vecRecursionMergeSort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
// 	int i = 0;
// 	for (std::vector<int>::iterator it = first; it != last; ++it)
// 		++i;
// 	if (i <= 1)
// 		return;
// 	int middle = i / 2;
// 	std::vector<int>::iterator mid = first;
// 	for (int i = 0; i < middle; ++i)
// 		++mid;

// 	vecRecursionMergeSort(first, mid);
// 	vecRecursionMergeSort(mid, last);

// 	vecMerge(first, mid, last);
// }

// void	listMerge(std::list<int>::iterator first, std::list<int>::iterator middle, std::list<int>::iterator last) {
	
// 	std::list<int> tmp(first, last);

// 	std::list<int>::iterator left = tmp.begin();
// 	std::list<int>::iterator leftEnd = tmp.begin();
// 	std::list<int>::iterator right = tmp.begin();
// 	std::list<int>::iterator rightEnd = tmp.end();

// 	// move leftEnd and right iterator to the middle point
// 	int	i = 0;
// 	for (std::list<int>::iterator it = first; it != middle; ++it)
// 		++i;
// 	for (int j = 0; j < i; ++j) {
// 		++leftEnd;
// 		++right;
// 	}

// 	for (std::list<int>::iterator it = first; it != last; ++it) {
// 		if (left == leftEnd) {
// 			*it = *right;
// 			++right;
// 		} else if (right == rightEnd) {
// 			*it = *left;
// 			++left;
// 		} else if (*left < *right) {
// 			*it = *left;
// 			++left;
// 		} else {
// 			*it = *right;
// 			++right;
// 		}
// 	}
// }


// void	PmergeMe::listRecursionMergeSort(std::list<int>::iterator first, std::list<int>::iterator last) {
// 	int i = 0;
// 	for (std::list<int>::iterator it = first; it != last; ++it)
// 		++i;
// 	if (i <= 1)
// 		return ;
// 	int	middle = i / 2;
// 	std::list<int>::iterator mid = first;
// 	for (int i = 0; i < middle; ++i)
// 		++mid;
	
// 	listRecursionMergeSort(first, mid);
// 	listRecursionMergeSort(mid, last);

// 	listMerge(first, mid, last);
// }

