#include "libft.h"

void	*ft_memset(char *str, int symbol, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = symbol;
		i++;
	}
	return (str);
}
