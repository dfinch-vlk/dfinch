#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
	std::cout << "-------------------------------------------" << std::endl;
	DiamondTrap hero3("Oleg");
	hero3.attack("Bob");
	hero3.highFivesGuys();
	hero3.takeDamage(60);
	hero3.guardGate();
	hero3.whoAmI();
	return (0);
}