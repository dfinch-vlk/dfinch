#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << name << " had died" << std::endl;
}

Zombie::Zombie(std::string s)
{
	name = s;
}

void	Zombie::announce(void)
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}