#ifndef FIXED_CPP
# define FIXED_CPP

# include <iostream>

class Fixed
{
public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed & operator=(const Fixed &n);
	Fixed(const Fixed &n);
	Fixed();
	~Fixed();
private:
	int value;
	static const int bits = 8;
};

#endif