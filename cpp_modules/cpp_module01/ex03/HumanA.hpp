#ifndef HUMANA_CPP
# define HUMANA_CPP

# include "Weapon.hpp"

class HumanA
{
private:
	Weapon *weapon;
	std::string name;
public:
	void attack(void);
	HumanA(std::string n, Weapon *w);
	HumanA();
};

#endif