#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, int len)
{
	while (len > 0)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		else if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
		len--;
	}
	return (0);
}
