#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{

	Bureaucrat	sim("Sim", 2);
	std::cout << sim << std::endl;

	try
	{
		// code within this block may throw exceptions.
		// If an exception is thrown, the program jumps 
		// to the nearest matching catch to handle the exception.
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.incrementGrade();
		std::cout << bob << std::endl;

		bob.decrementGrade();
		std::cout << bob << std::endl;

		bob.decrementGrade();
		std::cout << bob << std::endl;

		Bureaucrat	olga("Olga", 200);
		std::cout << olga << std::endl;
	}
	catch (const std::exception& err) //err represent the caught exception
	{
		std::cerr << err.what() << std::endl;
	}

	try
	{
		Bureaucrat anne("Anne", 1);
		std::cout << anne << std::endl;
		anne.incrementGrade();
		std::cout << anne << std::endl;

		// Not shown because it has already gone into catch !
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat lou("Lou", 150);
		std::cout << lou << std::endl;
		lou.decrementGrade();
		std::cout << lou << std::endl;
	}
	catch (const std::exception& e) // works fine because only 1 type of exception, otherwise catching specific exception (Bureaucrat::GradeTooLowException& e) is more appropriate
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
