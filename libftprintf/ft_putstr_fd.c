#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
