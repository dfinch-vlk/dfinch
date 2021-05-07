int	ft_isprint(int symbol)
{
	if (32 <= symbol && symbol <= 126)
		return (16384);
	return (0);
}

int 	ft_isdigit(int symbol)
{
	return (48 <= symbol && symbol <= 57);
}

int	ft_isalnum(int symbol)
{
	if (48 <= symbol && symbol <= 57)
		return (8);
	if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122))
		return (8);
	return (0);
}

int	ft_isascii(int symbol)
{
	if (symbol >= 0 && symbol <= 127)
		return (1);
	return (0);
}

int	ft_isalpha(int symbol)
{
	if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122))
		return (1024);
	return (0);
}
