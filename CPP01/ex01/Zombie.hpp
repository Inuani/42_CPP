#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	public:

	Zombie();
	Zombie(std::string name);

	~Zombie();

	void	announce(void);

	private:

	std::string	_name;
};

void	randomChump( std::string name );
Zombie	*newZombie( std::string name );
Zombie	*zombieHorde( int N, std::string name );

#endif
