#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *cccHorde = zombieHorde(N, "ccc");
	for (int i = 0; i < N; i++)
		cccHorde[i].announce();
	delete[] cccHorde;
	return (0);
}
