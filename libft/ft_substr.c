#include "libft.h"

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*result;
	int		count;

	count = 0;
	result = malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
	while (count != len)
		result[count++] = s[start++];
	result[count] = 0;
	return (result);
}
