#include <iostream>

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T* array, const size_t length, void(*func)(T&))
{
	for(size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void	printArrayElement(T& element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	incrementArrayElement( T& element)
{
	element += 1;
}

template <typename T>
void	setToZeroArrayElement( T& element)
{
	element = 0;
}

class People {

public:

	People(const std::string& name, const int age)
		: _name(name), _age(age) {
	}

	~People() {}


	void operator+=(int inc) {
		_age += inc;
	}

	int			getAge() const {
		return _age;
	}

	const std::string&	getName() const {
		return _name;
	}

private:

	std::string	_name;
	int			_age;

};

// this is operator overload for ostream class
std::ostream&	operator<<(std::ostream & os, const People& person) {
	os << "Name: " << person.getName() << ", age: " << person.getAge() << std::endl;
	return os;
}



#endif
