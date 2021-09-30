#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	void attack(std::string const &target);
 	void takeDamage(unsigned int amount);
 	void beRepaired(unsigned int amount);
	ClapTrap(std::string name);
	ClapTrap();
	~ClapTrap();
private:
	std::string name;
	int Hitpoints;
 	int Energy_points;
	int Attack_damage;
};

#endif