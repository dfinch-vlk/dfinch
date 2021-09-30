#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap hero("Evgen");
	ScavTrap hero1("Vova");
	FragTrap hero2("Ed");

	hero.attack("Ed");
	hero.takeDamage(11);
	hero.attack("Demon");
	hero.beRepaired(5);
	hero.attack("Bob");
	std::cout << "-------------------------------------------" << std::endl;
	hero1.attack("Misha");
	hero1.takeDamage(20);
	hero1.beRepaired(25);
	hero1.guardGate();
	std::cout << "-------------------------------------------" << std::endl;
	hero2.attack("Bob");
	hero2.highFivesGuys();
	hero2.takeDamage(60);
	return (0);
}