#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap(std::string const name);
	DiamondTrap(DiamondTrap const &other);
	virtual ~DiamondTrap();
	void    attack(std::string const & target);
	void whoAmI();
private:

	DiamondTrap();
	std::string _name;
};

#endif