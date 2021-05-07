char	*ft_itoa(int number)
{
	char	*result;
	int		array[3];

	array[0] = 0;
	array[1] = 1;
	array[2] = 0;
	if (number < 0)
	{
		array[2] = 1;
		number *= -1;
	}
	while (number % array[1] != number)
	{	
		array[1] *= 10;
		array[0]++;
	}
	result = malloc(array[0] + array[2] + 2);
	array[0] += array[2];
	if (array[2] == 1)
		result[0] = '-';
	result[array[0] + 1] = 0;
	while (array[0] != array[2] - 1)
	{
		result[array[0]--] = number % 10 + 48;
		number = (number - number % 10) / 10;
	}
	return (result);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	char	symbol;
	int		count;

	count = 1;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	while (nbr % count != nbr)
		count *= 10;
	while (count != 0)
	{
		count /= 10;
		symbol = nbr / count + 48;
		write (fd, &symbol, 1);
		nbr -= count * (nbr / count);
	}
}
