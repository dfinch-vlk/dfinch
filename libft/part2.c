int	ft_tolower(int symbol)
{
	if (symbol >= 65 && symbol <= 90)
		return (symbol + 32);
	return (symbol);
}

int	ft_toupper(int symbol)
{
	if (symbol >= 97 && symbol <= 122)
		return (symbol - 32);
	return (symbol);
}

int	ft_strlcpy(char *result, const char *str, int len)
{
	int	count;

	count = 0;
	while (count < len || str[count])
	{
		result[count] = str[count];
		count++;
	}
	result[count] = '\0';
	while (str[count])
		count++;
	return (--count);
}

int	ft_strlcat(char *result, const char *str, int len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (result[count])
		count++;
	count--;
	while (i < len || str[i])
		result[count++] = str[i++];
	result[count] = '\0';
	return (count);
}

char	*ft_strrchr(char *str, int symbol)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == symbol)
			return (&str[i]);
	return (0);
}
