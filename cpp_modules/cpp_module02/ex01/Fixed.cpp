#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (n << Fixed::bits);
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed &n)
{
	this->value = n.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &n)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = n.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
}
