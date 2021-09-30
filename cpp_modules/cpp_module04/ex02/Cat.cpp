#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	this->brain = new Brain();
	std::cout << "Create Cat" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
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