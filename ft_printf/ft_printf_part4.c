#include "libftprintf.h"

int	conditions(int symbol)
{
	if (symbol == 'c' || symbol == 's' || \
		symbol == 'p' || symbol == 'd' || \
		symbol == 'i' || symbol == 'u' || \
		symbol == 'x' || symbol == 'X' || symbol == '%')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}

int	my_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		write(1, &str[count++], 1);
	return (count);
}

char	*ft_malloc(int size, int width, int flag)
{
	int		count;
	char	*result;

	result = malloc(size);
	if (!result)
		return (NULL);
	count = 0;
	while (count < width + 1)
	{
		if (flag == 0)
			result[count++] = ' ';
		if (flag == 1)
			result[count++] = '0';
	}
	result[count - 1] = 0;
	return (result);
}
