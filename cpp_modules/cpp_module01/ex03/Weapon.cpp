#include "Weapon.hpp"

std::string Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string s)
{
	this->type = s;
}

Weapon::Weapon(std::string s)
{
	this->type = s;
}

Weapon::Weapon(){};