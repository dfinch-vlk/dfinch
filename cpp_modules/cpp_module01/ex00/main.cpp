#include "Zombie.hpp"

int main()
{
	Zombie zombie1("Evgen");
	Zombie *zombie2;

	randomChump("Oleg");
	zombie2 = newZombie("Pedro");
	zombie1.announce();
	zombie2->announce();
	delete zombie2;
	randomChump("Kiril");
	return (0);
}