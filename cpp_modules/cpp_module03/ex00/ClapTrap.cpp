#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Hitpoints(10), Energy_points(10), Attack_damage(0)
{
	this->name = name;
	std::cout << "ClapTrap " << this->name << " is created" << std::endl;
}

ClapTrap::ClapTrap(){};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " is died" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->Energy_points != 0 && this->Hitpoints >= 0)
	{
		std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points -= 1;
	}
	else
		std::cout << "Sorry " << name << " is incapacitated" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->Hitpoints -= amount;

	std::cout << this->name << " has been dealt " << std::to_string(amount) << " damage" << std::endl;
	if (this->Hitpoints <= 0)
		std::cout << name << " is incapacitated" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "Add " << std::to_string(amount) << " hp" << std::endl;
	this->Hitpoints += amount;
}
