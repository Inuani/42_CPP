#include <iostream>

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {

public:

	Array();
	Array(unsigned int n);
	Array(const Array<T>& src);
	~Array();

	Array<T>&		operator=(const Array<T>& rhs);
	unsigned int	size() const;
	T& operator[](unsigned int idx) const;

private:

	unsigned int	_aSize;
	T*				_array;

};

template <typename T>
Array<T>::Array()
	: _aSize(0), _array(NULL) {
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _aSize(n), _array(new T[n]()) {
	// the parentheses () after [n] are used to value-initialize the elements of the array.
	// It means that elements will be initialized with their default values.
	// For built-in types like int or float, this will initialize the elements to zero.
	// For user-defined types, it will call the default constructor to initialize the elements.
}

template <typename T>
Array<T>::Array(const Array<T>& src) 
	: _aSize(src._aSize), _array(new T[src._aSize]) {
	for(unsigned int i = 0; i < src._aSize; ++i)
		_array[i] = src._array[i];
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& rhs) {
	if (this != &rhs) {
		delete[] _array;
		_array = new T[rhs._aSize];
		_aSize =  rhs._aSize;
		for (unsigned int i = 0; i < _aSize; ++i)
			_array[i] = rhs._array[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx) const {
	if (idx >= _aSize)
		throw std::out_of_range("index out of range");
	return _array[idx];
}

template <typename T>
unsigned int	Array<T>::size() const {
	return _aSize;
}

// // When working with templates, the implementation must be included in the header
// // to ensure that the compiler can instantiate the templates for different types.
// #include "Array.tpp"
#endif
