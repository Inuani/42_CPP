#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>

int main( void )
{
	std::vector<int> vec;
	for(int i = 1; i <= 5; ++i)
		vec.push_back(i);

	std::cout << "vector of int:"<< std::endl;
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << std::endl;
	testEasyfind(vec, "std::vector");

	std::cout << std::endl;
	std::list<int> list;
	for(int i = 0; i <= 5; ++i)
		list.push_back(i * 2);

	std::cout << std::endl;
	testEasyfind(list, "std::list");

	std::cout << std::endl;
	std::vector<int> empty;
	testEasyfind(empty, "empty std::vector");

	std::cout << std::endl;
	std::vector<int> unitVec;
	unitVec.push_back(21);
	testEasyfind(unitVec, "unit std::vector");

	return 0;
}
