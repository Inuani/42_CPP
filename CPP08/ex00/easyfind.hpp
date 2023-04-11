#include <iostream>

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

class NotFound : public std::exception {
	public:

	virtual const char *what() const throw(){
		return "value not found";
	}

};

template <typename T>
typename T::iterator	easyfind(T& container, int val) // T can be of any type but it is expected to be a container type
{
	// keyword typename to indicate compiler that T::iterator is a type and not a function or a variable !
	typename T::iterator	it = std::find(container.begin(), container.end(), val);
	// T::iterator is a nested type of the container type T 
	// (nested type is type declared inside another class or struct)
	// if val not found then end() is returned

	if (it != container.end())
		return it;
	else
		throw NotFound();
}

template <typename T>
void	testEasyfind(T& container, const std::string& contName)
{
	std::cout << "Tests for " << contName << " :" << std::endl;
	
	for (int i = -2; i <= 7; ++i)
	{
		try {
			std::cout << "Searching for " << i << ": ";
			std::cout << *easyfind(container, i) << std::endl;
		} catch (NotFound& e) {
			std::cout << e.what() << std::endl;
		}
	}
}


// prototype of the function template std::find :
// template< class InputIt, class T > // InputIt is an iterator
// InputIt find( InputIt first, InputIt last, const T& value );

// iterator is an object that points to an element in a container (a vector or an array).
// It allows to traverse the container and access its elements.


#endif
