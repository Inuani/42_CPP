#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

public:

Fixed();
Fixed(const int nb);
Fixed(const float);
Fixed(const Fixed& src);
~Fixed();

Fixed&	operator=(const Fixed& rhs);
bool	operator<(const Fixed& rhs) const;
bool	operator>(const Fixed& rhs) const;
bool	operator>=(const Fixed& rhs) const;
bool	operator<=(const Fixed& rhs) const;
bool	operator==(const Fixed& rhs) const;
bool	operator!=(const Fixed& rhs) const;

Fixed	operator+(const Fixed& rhs) const;
Fixed	operator-(const Fixed& rhs) const;
Fixed	operator*(const Fixed& rhs) const;
Fixed	operator/(const Fixed& rhs) const;

Fixed&	operator++( void ); // pre-inc
Fixed	operator++( int ); // post-inc
Fixed&	operator--( void ); // pre-dec
Fixed	operator--( int ); //post-dec

static const Fixed &	min(const Fixed& rhs, const Fixed& lhs);
static Fixed&			min(Fixed& rhs, Fixed& lhs);
static const Fixed &	max(const Fixed& rhs, const Fixed& lhs);
static Fixed&			max(Fixed& rhs, Fixed& lhs);

int		getRawBits( void ) const;
void	setRawBits( int const raw );
float	toFloat( void ) const;
int		toInt( void ) const;

private :

int					_value;
static const int	_fractionalBits = 8;

};

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed);




#endif
