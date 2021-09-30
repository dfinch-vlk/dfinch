#ifndef FIXED_CPP
# define FIXED_CPP

# include <iostream>

class Fixed
{
public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed & operator=(const Fixed &n);
	int toInt(void) const;
	float toFloat(void) const;
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &n);
	Fixed();
	~Fixed();
private:
	int value;
	static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif