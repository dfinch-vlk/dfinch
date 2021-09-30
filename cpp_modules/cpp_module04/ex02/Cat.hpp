#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
public:
	virtual void makeSound() const;
	Cat();
	virtual ~Cat();
	Cat &operator=(const Cat& other);
private:
	Brain *brain;
};

#endif