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

Fixed& operator= (const Fixed& rhs);

int		getRawBits( void ) const;
void	setRawBits( int const raw );
float	toFloat( void ) const;
int		toInt( void ) const;

// int	getBit(int bitNum) const;
// std::string	getRawBitsRepr(void) const;

private :

int					_value;
static const int	_fractionalBits = 8;

};

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed);

#endif
