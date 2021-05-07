char	*ft_substr(char const *s, unsigned int start, int len)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		count;
	int		i;

	result = malloc(sizef(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
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

void	**ft_memory_split(const char *str, char **result, char c)
{
	int	count[2];
	int	i;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	while (str[i])
	{
		if (str[i] == c || str[i + 1] == '\0')
		{
			result[count[1]] = (char **)malloc(sizeof(char) * (i - count[0]) + 1);
			count[0] = i;
			count[1]++;
		}
		i++;
	}
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		count;
	int		row;
	int		i;

	i = 0;
	count = 0;
	row = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	result = (char *)malloc(sizeof(char *) * (count + 1));
	count = 0;
	ft_memory_split(str, result, c);
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
	return (result);
}
