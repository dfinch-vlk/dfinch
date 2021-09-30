#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << name << " had died" << std::endl;
}

Zombie::Zombie(std::string s)
{
	name = s;
}

Zombie::Zombie(){};

void	Zombie::announce(void)
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string s)
{
	name = s;
}
