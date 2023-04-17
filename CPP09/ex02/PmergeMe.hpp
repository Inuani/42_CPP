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
	void	vecRecursionMergeSort(std::vector<int>& vec);
	void	listRecursionMergeSort(std::list<int>& lst);
};

#endif
