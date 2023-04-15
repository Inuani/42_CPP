#include <iostream>
#include <stack>

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T> {

public:

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& src) : std::stack<T>(src), _helpContainer(src._helpContainer) {}
	~MutantStack() {}

	MutantStack& operator=(const MutantStack& rhs) {
		if (this != &rhs) {
			std::stack<T>::operator=(rhs);
			_helpContainer = rhs._helpContainer;
		}
		return *this;
	}

	typedef typename std::deque<T>::iterator		iter;

	// In C++ templates, you encounter types that are dependent on a template parameter :
	// When a type is dependant on a template, the compiler has difficulty determining if an identifier is a type or a value.
	// typename keyword is used to tell the compiler that  std::deque<T>::iterator is a type.

	typedef typename std::deque<T>::const_iterator	constIter;

	iter begin() {
		return _helpContainer.begin();
	}

	iter end() {
		return _helpContainer.end();
	}

	constIter begin() const {
		return _helpContainer.begin();
	}

	constIter end() const {
		return _helpContainer.end();
	}

	void push(const T& value) {
		std::stack<T>::push(value);
		_helpContainer.push_back(value);
	}

	void pop() {
		if (!std::stack<T>::empty()) {
			std::stack<T>::pop();
			_helpContainer.pop_back();
		}
	}

	// typedef typename std::stack<T>::container_type::iterator 		iter;

	// // In C++ templates, you encounter types that are dependent on a template parameter :
	// // When a type is dependant on a template, the compiler has difficulty determining if an identifier is a type or a value.
	// // typename keyword is used to tell the compiler that std::stack<T>::container_type::iterator is a type.

	// // std::stack<T>::container_type -> is a typedef of std::stack<T> class
	// // that represent the type of the UNDERLYING container used to implement the stack (std::deque<T>)
	// // Since T is a template parameter, container_type is a dependent type that depends on the type of T.

	// // std::stack<T>::container_type::iterator -> represent the iterator type. An iterator of type std::stack<T>::containter_type
	// // is also a dependent type, as it depends on the type of the underlying container which in turn depends on T.

	// typedef typename std::stack<T>::container_type::const_iterator	constIter;

	// iter	begin() {
	// 	return this->c.begin(); // this->c refers to the underlying container of the std::stack<T>
	// }

	// iter	end() {
	// 	return this->c.end();
	// }

	// constIter	beginConst() {
	// 	return this->c.begin();
	// }

	// constIter	endConst() {
	// 	return this->c.end();
	// }

private:
	std::deque<T> _helpContainer;
};

#endif

// NOTES:
// 0. std::stack class is a container adapter that give the functionality of a stack
// 1. Internally it uses std::deque STL container
// 2. It is a LIFO (last-in, first-out) data structure.
// 3. std::stack allows to push (insert) and pop (remove) only fomr back.

// FUNCTIONS PROVIDED
// empty() - returns whether the stack is empty
// size() - returns the size of the stack
// top () - returns a reference to the top most element of the stack
// push(g) - adds the element 'g' at the top of the stack
// pop() - deletes the top most element of the stack
