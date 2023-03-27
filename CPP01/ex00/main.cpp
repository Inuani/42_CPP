#include "Zombie.hpp"

int main()
{
	randomChump("Frido");

	Zombie *zomb = newZombie("Puppy");
	zomb->announce();
	delete zomb;
	return (0);
}

