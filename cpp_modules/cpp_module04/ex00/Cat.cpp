#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "Create Cat" << std::endl;
}

Cat::~Cat() {
	std::cout << "Delete Cat" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Cat & Cat::operator=(const Cat &other) {
	if (this != &other)
	{
		std::cout << "Cat copy assignment operator." << std::endl;
		_type = other._type;
	}
	return *this;
}