#include "libft.h"

char	*ft_strchr(char *str, int symbol)
{
	while (*str)
	{
		if (*str == symbol)
			return ((char *)str);
		++str;
	}
	if (symbol == '\0')
		return ((char *)str);
	return (0);
}
