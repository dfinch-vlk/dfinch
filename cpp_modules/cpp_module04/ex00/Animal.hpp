#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
public:
	std::string getType() const;
	virtual void makeSound() const;
	Animal();
	virtual ~Animal();
	Animal &operator=(const Animal& other);
protected:
	std::string _type;
};

#endif