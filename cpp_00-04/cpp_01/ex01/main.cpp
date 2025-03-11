#include "Zombie.hpp"
#include <iostream>

int main()
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "HordeZombie");
	if (!horde)
	{
		std::cerr << "Error creating horde" << std::endl;
		return 1;
	}

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}