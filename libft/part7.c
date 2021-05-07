#include <stdlib.h>

int		ft_strlen(char *s);

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		count;
	int		i;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (s1[count])
	{
		result[count] = s1[count];
		count++;
	}
	i = 0;
	while (s2[i])
		result[count++] = s2[i++];
	result[count] = 0;
	return (result);
}

void	ft_memory_split(char *str, char **result, char c)
{
	int	count;
	int	i;
	int	q;

	i = 0;
	count = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == c || str[i + 1] == '\0')
		{
			result[q] = *(char **)malloc(sizeof(char) * (i - count) + 1);
			count = i;
			q++;
		}
		i++;
	}
}

void	ft_split_dop(char *str, int count, char **result, int c)
{
	int	i;
	int	row;

	row = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			result[row][count] = 0;
			count = 0;
			row++;
			i++;
		}
		result[row][count++] = str[i];
		i++;
	}
	result[row][count] = 0;
}

char	**ft_split(char *str, char c)
{
	char	**result;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	count = 0;
	ft_memory_split(str, result, c);
	ft_split_dop(str, count, result, c);
	return (result);
}
