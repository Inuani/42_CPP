#include "Fixed.hpp"

#ifndef POINT_HPP
# define POINT_HPP

class Point {

public :

Point();
Point(const Fixed& a, const Fixed& b);
~Point();

	const Fixed& getX() const;
	const Fixed& getY() const;

private :

Fixed _x;
Fixed _y;	

};

std::ostream&	operator<<(std::ostream& os, const Point& point);
bool	bsp(const Point& P, const Point& A, const Point& B, const Point& C);

#endif
