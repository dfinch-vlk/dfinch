#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	while (i < (count * size))
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
