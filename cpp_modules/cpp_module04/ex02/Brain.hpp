#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
public:
	Brain();
	~Brain();
protected:
	std::string _idea[100];
};

#endif