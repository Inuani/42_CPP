#include <iostream>
#include <stack>

#ifndef MutantStack_HPP
# define MutantStack_HPP

template <typename T>
class MutantStack : public std::stack<T> {

public:

	MutantStack();
	MutantStack(const MutantStack& src);
	~MutantStack();

	MutantStack& operator=(const MutantStack& rhs);

private:

};

#endif

// NOTES:
// 0. std::stack class is a container adapter that give the functionality of a stack
// 1. Internally it uses std::deque STL container
// 2. It is a LIFO (last-in, first-out) data structure.
// 3. std::stack allows to push (insert) and pop (remove) only fomr back.

// FUNCTIONS PROVIDED
// empty() - returns whether the stack is empty
// size() - returns the size odf the stack
// top () - returns a reference to the top most element of the stack
// push(g) - adds the element 'g' at the top of the stack
// pop() - deletes the top most element of the stack
