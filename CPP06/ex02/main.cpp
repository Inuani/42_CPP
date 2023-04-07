#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	std::srand(std::time(0)); // seed random generator using current time
	int random = std::rand() %3; // nb btw 0 and 2

	switch(random) {
		case 0 :
			return new A();
		case 1 :
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A was hiding behind Base pointer!"<< std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B was hiding behind Base pointer!"<< std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C was hiding behind Base pointer!"<< std::endl;
	else
		std::cout << "Not A, B or C sorry!"<< std::endl;
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A was hiding behind Base reference!"<< std::endl;
		(void)a;
	}
	catch (const std::bad_cast&) {
		try {
			B& b = dynamic_cast<B&>(p);
			std::cout << "B was hiding behind Base reference!"<< std::endl;
			(void)b;
		}
		catch (const std::bad_cast&) {
			try {
				C& c = dynamic_cast<C&>(p);
				std::cout << "C was hiding behind Base reference!"<< std::endl;
				(void)c;
			}
			catch (const std::bad_cast&) {}
		}
	}
}

int main( void )
{
	Base* a = generate();
	identify(a);
	identify(*a);
	delete a;
	return 0;
}
