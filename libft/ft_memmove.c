void	ft_memmove(char *first, char *second, int len)
{
	char	str[len];
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
