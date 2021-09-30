#ifndef ZOBIE_HPP
# define ZOBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string name;
public:
	void	announce(void);
	~Zombie();
	Zombie();
	Zombie(std::string s);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif