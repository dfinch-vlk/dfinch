#include "libftprintf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}
