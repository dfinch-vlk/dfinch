void	*ft_bzero(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	count[2];
	int	result;
	int	checkMinus;

	count[0] = 0;
	count[1] = 0;
	result = 0;
	checkMinus = -1;
	if (str[0] == '-')
	{
		count[0]++;
		checkMinus = 0;
	}
	while (str[count[0]] && (str[count[0]] >= 48 && str[count[0]] <= 57))
		count[0]++;
	--count[0];
	while (count[0] != checkMinus)
	{
		result += (str[count[0]] - 48) * count[1];
		count[1] *= 10;
		--count[0];
	}
	if (str[0] == '-')
		return (result * -1);
	return (result);
}
