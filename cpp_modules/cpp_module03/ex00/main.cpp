#include "ClapTrap.hpp"

int main()
{
	ClapTrap hero("Evgen");

	hero.attack("Ed");
	hero.takeDamage(11);
	hero.attack("Demon");
	hero.beRepaired(5);
	hero.attack("Bob");
	return (0);
}