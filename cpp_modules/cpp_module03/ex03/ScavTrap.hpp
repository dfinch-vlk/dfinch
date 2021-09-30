#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	void guardGate();
	ScavTrap();
	~ScavTrap();
 	ScavTrap(std::string name);
	void attack(std::string const &target);
};

#endif