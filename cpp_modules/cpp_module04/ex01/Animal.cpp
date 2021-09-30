#include "Animal.hpp"

Animal::Animal(): _type("????") {
	std::cout << "Create Animal" << std::endl;
}

Animal::~Animal() {
	std::cout << "Delete Animal" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "????" << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}

Animal & Animal::operator=(const Animal &other) {
	if (this != &other)
	{
		std::cout << "Animal copy assignment operator." << std::endl;
		_type = other._type;
	}
	return *this;
}