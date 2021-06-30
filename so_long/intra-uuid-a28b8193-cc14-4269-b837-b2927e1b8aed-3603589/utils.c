#include "so_long.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	count;

	count = 0;
	if (!s1 || !s2 || (ft_strlen(s1) != ft_strlen(s2)))
		return (-1);
	while (s1[count])
	{
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
		count++;
	}
	return (0);
}
