#include <iostream>
#include <vector>

#ifndef SPAN_HPP
# define SPAN_HPP

class Span {

public:


	Span(unsigned int);
	Span(const Span& src);
	~Span();

	Span& operator=(const Span& rhs);

	void			addNumber(int nb);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	void	addRangeNb(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);


	class SpanIsFull : public std::exception {
		public:
		virtual const char *what() const throw();
	};

	class NotEnoughNbSpan : public std::exception {
		public:
		virtual const char *what() const throw();
	};

private:

	Span();
	unsigned int		_vecMaxSize;
	std::vector<int>	_intVec;

};

#endif
