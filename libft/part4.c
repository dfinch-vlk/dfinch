char	*ft_memchr(char *str, int symbol, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == symbol)
			return (&str[i]);
		i++;
	}
	return (0);
}

int	ft_memcmp(char *str1, char *str2, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	*ft_memmove(char *first, char *second, int len)
{
	char	str[len];
	int		i;

	i = 0;
	while (i < len)
		str[i] = second[i++];
	i = 0;
	while (i < len)
		first[i] = str[i++];
}

void	*ft_memcpy(char *first, char *second, int len)
{
	int	i;

	i = 0;
	while (i < len)
		first[i] = second[i++];
}

void	*ft_memccpy(char *first, char *second, int symbol, int len)
{
	int	i;

	i = 0;
	while (i < len || second[i] != symbol)
		first[i] = second[i++];
}
