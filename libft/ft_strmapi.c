#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = malloc((int)ft_strlen((char *)s) + 1);
	if (s == NULL)
		return (NULL);
	if (result == NULL)
		return (NULL);
	if (s == NULL || result == NULL)
		return (0);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
