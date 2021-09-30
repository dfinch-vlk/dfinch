#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
public:
	virtual std::string getType() const = 0;
	virtual void makeSound() const = 0;
	Animal();
	virtual ~Animal();
	Animal &operator=(const Animal& other);
protected:
	std::string _type;
};

#endif