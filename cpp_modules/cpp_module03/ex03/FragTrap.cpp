#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap " << this->name << " a created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " is died" << std::endl;
}

void FragTrap::attack(std::string const &target)
{
	if (this->Energy_points != 0 && this->Hitpoints >= 0)
	{
		std::cout << "FragTrap " << this->name << " attack " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points -= 1;
	}
	else
		std::cout << "Sorry " << name << " is incapacitated" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "\033[1;32m";

	std::cout << "   _.-._" << std::endl;
	std::cout << "  | | | |_ " << std::endl;
	std::cout << "  | | | | | " << std::endl;
	std::cout << "  | | | | | " << std::endl;
	std::cout << "_ |  '-._ | " << std::endl;
	std::cout << "\\`\\`-.'-._; " << std::endl;
	std::cout << " \\    '   | " << std::endl;
	std::cout << "  \\  .`  / " << std::endl;
	std::cout << "   |    | " << std::endl;

	std::cout << "\033[0m";
}