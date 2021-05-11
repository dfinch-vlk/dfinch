#include "libft.h"

char	*ft_strdup(char *str)
{
	int		count;
	char	*result;

	count = -1;
	result = malloc(ft_strlen(str) + 1);
	while (str[++count])
		result[count] = str[count];
	result[count] = '\0';
	return (result);
}
