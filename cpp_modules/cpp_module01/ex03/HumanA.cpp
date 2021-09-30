#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << this->name << " attack " << weapon->getType() << std::endl;
}

HumanA::HumanA(std::string n, Weapon *w)
{
	this->name = n;
	this->weapon = w;
}

HumanA::HumanA(){};