#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string s);
	std::string getType(void);
	void		setType(std::string s);
};

#endif