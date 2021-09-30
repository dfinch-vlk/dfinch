#include "HumanB.hpp"

void HumanB::setWeapon(Weapon *w)
{
	this->weapon = w;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attack " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string s)
{
	this->name = s;
}

HumanB::HumanB(){};