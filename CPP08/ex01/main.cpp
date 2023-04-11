#include <iostream>
#include "Span.hpp"

int main( void )
{
	//main provided
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// additional tests
	std::cout << std::endl;
	
	Span big(15000);
	std::vector<int> fillWithNb(15000);
	for(size_t i = 0; i < fillWithNb.size(); ++i)
		fillWithNb[i] = i * 2;
	
	big.addRangeNb(fillWithNb.begin(), fillWithNb.end());
	std::cout << "shortest span is: " << big.shortestSpan() << std::endl;
	std::cout << "longest span is: " << big.longestSpan() << std::endl;

	try {
		big.addNumber(20);
	}
	catch (std::exception& e) {
		std::cout << e.what() <<std::endl;
	}

	// Not engough number in vector test
	std::cout << std::endl;
	Span empty(0);
	try {
		empty.shortestSpan();
	}
	catch (std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	try {
		empty.longestSpan();
	}
	catch (std::exception& e) {
		std::cout << e.what() <<std::endl;
	}

	Span oneElem(1);
	oneElem.addNumber(5);
	try {
		oneElem.shortestSpan();
	}
	catch (std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	try {
		oneElem.longestSpan();
	}
	catch (std::exception& e) {
		std::cout << e.what() <<std::endl;
	}

	// random value in vector
	std::cout << std::endl;

	srand(static_cast<unsigned int>(time(0))); // seed random nb generator with cur time
	Span randBig(10000);
	std::vector<int> randomVec(10000);
	int	min = -10000000;
	int max = 10000000;
	int	range = max - min + 1;
	for (size_t i = 0; i < randomVec.size(); ++i) {
		int randomNb = min + rand() % range;
		randomVec[i] = randomNb;
	}
	randBig.addRangeNb(randomVec.begin(), randomVec.end());

	std::cout << "shortest span is: " << randBig.shortestSpan() << std::endl;
	std::cout << "longest span is: " << randBig.longestSpan() << std::endl;

	return 0;
}
