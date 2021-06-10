#include "ft_printf.h"

long int	checkMinusMemoryl(long int n)
{
	if (n < 0)
		return (1);
	return (0);
}

unsigned long int	get_sizel(long n)
{
	unsigned long int	size;

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

void	ft_itoal_dop(long int n, long int i, char *str)
{
	while (n >= 10)
	{
		str[i--] = (char)(n % 10 + 48);
		n /= 10;
	}
	str[i] = (char)(n % 10 + 48);
}

char	*ft_itoal(long int n)
{
	char				*str;
	unsigned long int	size;
	unsigned long int	i;

	i = 0;
	size = get_sizel(n);
	str = (char *)malloc(sizeof(char) * (size + checkMinusMemoryl(n) + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		size++;
		n = n * (-1);
	}
	i = size - 1;
	ft_itoal_dop(n, i, str);
	str[size] = '\0';
	return (str);
}
