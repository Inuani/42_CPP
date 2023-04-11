#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

Span::Span() : _vecMaxSize(0) {
}

Span::Span(unsigned int N) : _vecMaxSize(N) {
	// _intVec will be automatically initialised 
	// by default constructor of std::vec when an instance of Span is created
}

Span::Span(const Span &src) : _vecMaxSize(src._vecMaxSize), _intVec(src._intVec) {
}

Span::~Span() {
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs) {
		_vecMaxSize = rhs._vecMaxSize;
		_intVec = rhs._intVec; // deep copy and adaptation of the size is automatic with vector assignation 
	}
	return *this;
}

void	Span::addNumber(int nb)
{
	if (_intVec.size() >= _vecMaxSize)
		throw SpanIsFull();
	_intVec.push_back(nb);
}

unsigned int	Span::shortestSpan()
{
	if (_intVec.size() <= 1)
		throw NotEnoughNbSpan();
	std::sort(_intVec.begin(), _intVec.end());
	int min = std::numeric_limits<int>::max(); // set min at max int
	for (size_t i = 1; i < _intVec.size() ;++i)
		min = std::min(min, _intVec[i] -_intVec[i - 1]); // compare min and adjacent values in intVec and set the min at the lowest btw the 2
	return min;
}

unsigned int	Span::longestSpan()
{
	if (_intVec.size() <= 1)
		throw NotEnoughNbSpan();
	std::vector<int>::const_iterator min = min_element(_intVec.begin(), _intVec.end());
	std::vector<int>::const_iterator max = max_element(_intVec.begin(), _intVec.end());
	return *max - *min;
}

void	Span::addRangeNb(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	while (first != last) {
		addNumber(*first);
		first++;
	}
}

const char *Span::SpanIsFull::what() const throw() {
	return "Span is full";
}

const char *Span::NotEnoughNbSpan::what() const throw() {
	return "Not enough number in the span";
}
