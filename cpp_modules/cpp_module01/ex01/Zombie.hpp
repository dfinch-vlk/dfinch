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
	void set_name(std::string s);
};

Zombie *zombieHorde(int n, std::string name);
#endif