#include "Zombie.hpp"

int main()
{
	int n = 25;
	Zombie *zombies = zombieHorde(n, "Evgen");

	for (int i = 0; i < 25; i++)
		zombies[i].announce();
	delete []zombies;
	return (0);
}