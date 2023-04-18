#include <iostream>
#include <vector>
#include <list>

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe {

public:

	PmergeMe();
	PmergeMe(const PmergeMe& src);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& rhs);

	void	parseInput(int& ac, char** av);
	void	printVec();
	void	printList();
	void	mergeSort();
	
private:

	std::vector<int>	_vec;
	std::list<int>		_lst;
	// void	vecRecursionMergeSort(std::vector<int>::iterator first, std::vector<int>::iterator last);
	// void	listRecursionMergeSort(std::list<int>::iterator first, std::list<int>::iterator last);
};

template <typename T>
int	nbOfElem(typename T::iterator first, typename T::iterator last)
{
	int i = 0;
	for (typename T::iterator it = first; it != last; ++it)
		++i;
	return i;
}


// source for algo : https://www.youtube.com/watch?v=LeWuki7AQLo

template <typename T>
void containerMerge(typename T::iterator first, typename T::iterator middle, typename T::iterator last) {
	
	T tmp(first, last); // tmp copy of the vec/list last excluded

	typename T::iterator left = tmp.begin();
	typename T::iterator leftEnd = tmp.begin();
	typename T::iterator right = tmp.begin();
	typename T::iterator rightEnd = tmp.end();

	int i = 0;
	for (typename T::iterator it = first; it != middle; ++it)
		++i;
	for (int j = 0; j < i; ++j) {
		++leftEnd; // in interval (left, leftEnd) left is included and leftEnd is excluded
		++right; // same
	}

	for (typename T::iterator it = first; it != last; ++it) { // we iterate through the original vec/list here
		if (left == leftEnd) { // if this is true we are at the end of left vec or list so we just copy the rest of right
			*it = *right;
			++right;
		} else if (right == rightEnd) { // same logic as above
			*it = *left;
			++left;
		} else if (*left < *right) { // if both vec/list have some element we compare value and copy the smaller to the original vec/list
			*it = *left;
			++left;
		} else {
			*it = *right;
			++right;
		}
	}
}

template <typename T>
void recursionMergeSort(typename T::iterator first, typename T::iterator last) {
	int nbElem = 0; // get the nb of element from first to last
	for (typename T::iterator it = first; it != last; ++it)
		++nbElem;
	if (nbElem <= 1)
		return;
	int middle = nbElem / 2;
	typename T::iterator mid = first;
	for (int i = 0; i < middle; ++i)
		++mid; // advance the it to the middle of the list/vec

	recursionMergeSort<T>(first, mid); // first is included and mid is excluded (half open interval)
	recursionMergeSort<T>(mid, last); // mid included, last excluded 

	containerMerge<T>(first, mid, last);
}

// When you see a pair of iterators defining a range (ex: (first, last)), 
// you can generally assume that the first iterator is included,
// and the second iterator is excluded from the range.

#endif
