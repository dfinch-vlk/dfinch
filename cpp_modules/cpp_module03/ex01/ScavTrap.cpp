#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->Hitpoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap " << this->name << " a created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is died" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->Energy_points != 0 && this->Hitpoints >= 0)
	{
		std::cout << "SlawTrap " << this->name << " attack " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points -= 1;
	}
	else
		std::cout << "Sorry " << name << " is incapacitated" << std::endl;
}