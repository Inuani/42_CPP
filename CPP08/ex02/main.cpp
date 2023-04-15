#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main( void )
{
	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);

	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	
	// mstack.push(0);
	// MutantStack<int>::iter it = mstack.begin();
	// MutantStack<int>::iter ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite) {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);

	 // Test basic functionality
	MutantStack<int> ms;
	ms.push(10);
	ms.push(20);
	ms.push(30);

	std::cout << "Test basic functionality" << std::endl;
	for (MutantStack<int>::iter it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	// Test copy constructor
	MutantStack<int> ms2(ms);

	std::cout << "Test copy constructor" << std::endl;
	for (MutantStack<int>::iter it = ms2.begin(); it != ms2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	// Test assignment operator
	MutantStack<int> ms3;
	ms3 = ms;

	std::cout << "Test assignment operator" << std::endl;
	for (MutantStack<int>::iter it = ms3.begin(); it != ms3.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	// Test pop
	ms.pop();

	std::cout << "Test pop" << std::endl;
	for (MutantStack<int>::iter it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	// Test with double
	MutantStack<double> ms4;
	ms4.push(1.5);
	ms4.push(2.5);
	ms4.push(3.5);

	std::cout << "Test with double)" << std::endl;
	for (MutantStack<double>::iter it = ms4.begin(); it != ms4.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	return 0;
}


// SAME MAIN WITH LIST CONTAINER
// int main( void )
// {
// 	std::list<int> list;
// 	list.push_back(10);
// 	list.push_back(20);
// 	list.push_back(30);

// 	std::cout << "Test basic functionality" << std::endl;
// 	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl << std::endl;

// 	// Test copy constructor
// 	std::list<int> list2(list);

// 	std::cout << "Test copy constructor" << std::endl;
// 	for (std::list<int>::iterator it = list2.begin(); it != list2.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl << std::endl;

// 	// Test assignment operator
// 	std::list<int> list3;
// 	list3 = list;

// 	std::cout << "Test assignment operator" << std::endl;
// 	for (std::list<int>::iterator it = list3.begin(); it != list3.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl << std::endl;

// 	// Test pop
// 	list.pop_back();

// 	std::cout << "Test pop" << std::endl;
// 	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl << std::endl;

// 	// Test with double
// 	std::list<double> list4;
// 	list4.push_back(1.5);
// 	list4.push_back(2.5);
// 	list4.push_back(3.5);

// 	std::cout << "Test with double)" << std::endl;
// 	for (std::list<double>::iterator it = list4.begin(); it != list4.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl << std::endl;

// 	return 0;
// }
