#include <stdlib.h>

int	ft_strlen(char *str);

void	ft_memmove(char *first, char *second, int len)
{
	char	str[100000];
	int		i;

	i = 0;
	while (i < len)
	{
		str[i] = second[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		first[i] = str[i];
		i++;
	}
}

char	*ft_calloc(int first, int second)
{
	char	*result;
	int		count;

	count = 0;
	result = malloc(first * second);
	while (count < (first * second))
	{
		result[count] = 0;
		count++;
	}
	return (result);
}
