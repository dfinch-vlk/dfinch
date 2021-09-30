#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "Create Dog" << std::endl;
}

Dog::~Dog() {
	std::cout << "Delete Dog" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

Dog & Dog::operator=(const Dog &other) {
	if (this != &other)
	{
		std::cout << "Cat copy assignment operator." << std::endl;
		_type = other._type;
	}
	return *this;
}