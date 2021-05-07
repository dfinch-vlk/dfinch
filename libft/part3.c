#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_strncmp(const char *str1, const char *str2, int len)
{
	int	i;

	i = 0;
	while (i < len || str1[i])
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

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

char	*ft_strchr(char *str, int symbol)
{
	char	*result;
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	result = ft_strdup(str);
	while (str[count[0]] != symbol)
		count[0]++;
	while (str[count[0]])
		result[count[1]++] = str[count[0]++];
	result[count[1]] = '\0';
	return (result);
}

void	ft_memset(char *str, int symbol, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = symbol;
		i++;
	}
}
