#ifndef HUMANB_CPP
# define HUMANB_CPP

# include "Weapon.hpp"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	void attack(void);
	HumanB(std::string n);
	HumanB();
	void setWeapon(Weapon *w);
};

#endif