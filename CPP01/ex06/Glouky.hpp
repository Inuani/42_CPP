#include <iostream>

#ifndef GLOUKY_HPP
# define GLOUKY_HPP

class Glouky {

	public :

	Glouky();
	~Glouky();

	void	complain( std::string level);
	int	input2Int(std::string av);

	private :

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

	struct SeverityLevel {
		std::string	_level;
		void		(Glouky::*func)();
	};

	SeverityLevel	_levels[4];

	

};

# endif
