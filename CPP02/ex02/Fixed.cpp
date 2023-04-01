#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &src)
{
	_value = src._value;
}

Fixed::Fixed(const int nb)
{
	_value = nb << _fractionalBits;
}

Fixed::Fixed(const float nb)
{
	_value = static_cast<int>(roundf(nb * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed &rhs)
{
	_value = rhs._value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int	Fixed::toInt( void ) const
{
	return _value >> _fractionalBits;
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	if (_value < rhs._value)
		return true;
	return false;
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return _value > rhs._value;
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return _value >= rhs._value;
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return _value <= rhs._value;
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return _value == rhs._value;
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return _value != rhs._value;
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	result;

	result._value = this->_value + rhs._value;
	return result;
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	result;

	result._value = this->_value * rhs._value / (1 << _fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	result;

	result._value = this->_value << _fractionalBits / rhs._value;
	return result;
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	result;

	result._value = this->_value - rhs._value;
	return result;
}

Fixed&	Fixed::operator++() // pre-inc
{
	this->_value += 1;
	return *this;
}

Fixed	Fixed::operator++(int) // post-inc
{
	Fixed	tmp = *this;
	this->_value += 1;
	return tmp;
}

Fixed&	Fixed::operator--() // pre-dec
{
	this->_value -= 1;
	return *this;
}

Fixed	Fixed::operator--(int) //post-dec
{
	Fixed	tmp = *this;
	this->_value -= 1;
	return tmp;
}

const Fixed&	Fixed::min(const Fixed& rhs, const Fixed& lhs)
{
	return (rhs < lhs) ? rhs : lhs;
}

Fixed&	Fixed::min(Fixed& rhs, Fixed& lhs)
{
	return (rhs < lhs) ? rhs : lhs;
}

const Fixed&	Fixed::max(const Fixed& rhs, const Fixed& lhs)
{
	return (rhs > lhs) ? rhs : lhs;
}

Fixed&	Fixed::max(Fixed& rhs, Fixed& lhs)
{
	return (rhs > lhs) ? rhs : lhs;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

