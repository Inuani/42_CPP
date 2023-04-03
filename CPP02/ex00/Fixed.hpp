#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

public:

Fixed();
Fixed(const Fixed& src);
~Fixed();

Fixed& operator= (const Fixed& rhs);

int		getRawBits( void ) const;
void	setRawBits( int const raw );

private :

int					_value;
static const int	_fractionalBits = 8; // the fixed-point number has 8 bits after decimal point.

};

#endif

// fixed-point number is a number with a fixed number of digits after the decimal point.