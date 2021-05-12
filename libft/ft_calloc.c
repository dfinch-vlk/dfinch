#include "libft.h"

char	*ft_calloc(int first, int second)
{
	char	*result;
	int		count;

	count = 0;
	result = malloc(first * second);
	if (result == NULL)
		return (NULL);
	while (count < (first * second))
	{
		result[count] = 0;
		count++;
	}
	return (result);
}
