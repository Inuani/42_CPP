#include <iostream>
#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : virtual public ClapTrap {

public:

	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& src);
	~FragTrap();

	FragTrap& operator=(const FragTrap& rhs);

	void	highFivesGuys( void );

private:

};

#endif
