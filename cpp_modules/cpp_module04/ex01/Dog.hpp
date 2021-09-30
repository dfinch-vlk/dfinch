#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
	virtual void makeSound() const;
	Dog();
	Dog &operator=(const Dog& other);
	virtual ~Dog();
private:
	Brain *brain;
};

#endif