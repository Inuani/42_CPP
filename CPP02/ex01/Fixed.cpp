#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = src._value;
}

// when leftshift value by 8 bits it is equivalent to
// multiply the int by 2^8 (256)
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	_value = nb << _fractionalBits;
}

// (1 << _fractionalBits) = 256 in our case
// rounded to the nearest int but still a float -> static_cast<int>
Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(nb * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = rhs._value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

// (1 << _fractionalBits) -> 2^8 = 256
// undoing scaling that was done when storing fix point number.
float	Fixed::toFloat( void ) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

// divide the value by 2^fractinalBits (2^8 = 256).
// -> removes the fractional part of the number
int	Fixed::toInt( void ) const
{
	return _value >> _fractionalBits;
}


std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// left-shift operation on a number multiply it 
// by 2 raised to the power of positions shifted.
// Each position in a binary number represents a power of 2.
// 0101 (5) becomes 1010 (10) with  1 left bitshift op-> 5 * 2
// right shifting does the opposite, divide 2 ^ power positions shifted


// int Fixed::getBit(int bitNum) const
// {
// 	// assert(bitNum >= 0 && bitNum < 32);
// 	return _value & (1 << bitNum) ? 1 : 0;
// }

// std::string Fixed::getRawBitsRepr(void) const
// {
// 	char buf[2];
// 	std::string s;

// 	for (int i = 32; --i >= 0;)
// 	{
// 		if (i == _fractionalBits - 1)
// 			s += '.';
// 		std::sprintf(buf, "%d", getBit(i));
// 		s += buf;
// 	}
// 	return s;
// }
