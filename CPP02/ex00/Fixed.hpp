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
static const int	_fractionalBits = 8;

};

#endif
