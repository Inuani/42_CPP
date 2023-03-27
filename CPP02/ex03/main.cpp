#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Fixed a(1.0f);
	Fixed b(2.0f);
	Fixed c(3.0f);

	Point A(a, b);
	Point B(b, c);
	Point C(c, a);

	std::cout << "Triangle ABC with point A(" << A << "), point B(" << B << ") and point C(" << C << ")" << std::endl;

	Point P(1.0f, 4.0f);

	bool InsideOrNot = bsp(P, A, B, C);

	std::cout << "Point P(" << P << ")" << (InsideOrNot ? " IS " : " IS NOT ") << "in the triangle ABC !" <<std::endl;

	return 0;
}


