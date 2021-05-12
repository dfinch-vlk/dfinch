#include "libft.h"
int	checkMinusMemory(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

unsigned int	get_size(long n)
{
	unsigned int	size;

	size = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;
	unsigned int	i;
	long int		nb;

	i = 0;
	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + checkMinusMemory(n) + 1));
	nb = n;
	if (n < 0)
	{
		str[i] = '-';
		size++;
		nb = nb * (-1);
	}
	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
