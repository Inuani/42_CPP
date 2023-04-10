#include <iostream>
#include "Array.hpp"

struct Point {
	int	x;
	int	y;
};

int main( void )
{

	// constructor by default
	Array<int> empty;
	std::cout << "empty array size: " << empty.size() << std::endl;

	//constructor with size
	Array<int> intA(5);
	std::cout << "intA size: " << intA.size() << std::endl;

	std::cout << std::endl;
	// value initialization by 0
	for(unsigned i = 0; i < intA.size(); ++i)
		std::cout << "intA[" << i << "] = " << intA[i] << std::endl;
	
	std::cout << std::endl;
	// modify value
	for(unsigned i = 0; i < intA.size(); ++i)
		intA[i] = i * 2;
	for(unsigned i = 0; i < intA.size(); ++i)
		std::cout << "intA[" << i << "] = " << intA[i] << std::endl;

	std::cout << std::endl;
	// copy constructor
	Array<int>	copyA(intA);
	for(unsigned i = 0; i < copyA.size(); ++i)
		std::cout << "copyA[" << i << "] = " << copyA[i] << std::endl;

	std::cout << std::endl;
	// operator =
	Array<int> opA;
	opA = copyA;
	for(unsigned i = 0; i < opA.size(); ++i)
		std::cout << "opA[" << i << "] = " << opA[i] << std::endl;

	std::cout << std::endl;
	try {
		std::cout << "try access array at index: "<< intA[4] << std::endl;
	} catch (const std:: out_of_range& e){
		std::cout << "caught exception: " << e.what() << std::endl;
	}
	// out of range index
	try {
		std::cout << "try access array at index: "<< intA[7] << std::endl;
	} catch (const std:: out_of_range& e){
		std::cout << "caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// struct Point array
	Array<Point> pointA(3);
	for(unsigned i = 0; i < pointA.size(); ++i){
		pointA[i].x = i * 2 - 3;
		pointA[i].y = i * 2 + 1;
	}
	for(unsigned i = 0; i < pointA.size(); ++i)
		std::cout << "pointA["<< i << "] = (" << pointA[i].x << ',' << pointA[i].y << ')' << std::endl;
	return 0;
}
