#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal{
public:
	virtual void makeSound() const;
	Cat();
	virtual ~Cat();
	Cat &operator=(const Cat& other);
};

#endif