#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap hero("Evgen");
	ScavTrap hero1("Vova");

	hero.attack("Ed");
	hero.takeDamage(11);
	hero.attack("Demon");
	hero.beRepaired(5);
	hero.attack("Bob");
	hero1.attack("Misha");
	hero1.takeDamage(20);
	hero1.beRepaired(25);
	hero1.guardGate();
	return (0);
}