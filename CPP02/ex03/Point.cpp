#include "Point.hpp"

Point::Point(const Fixed& a, const Fixed& b) : _x(a), _y(b)
{
}

Point::~Point()
{
}

const Fixed &Point::getX() const
{
	return _x;
}

const Fixed &Point::getY() const
{
	return _y;
}

std::ostream&	operator<<(std::ostream& os, const Point& point)
{
	os << point.getX().toFloat() << "," << point.getY().toFloat();
	return os;
}
