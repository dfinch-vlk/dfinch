#include "ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_atoi_dop(const char *str, int count)
{
	while ((str[count] == ' ') || (str[count] == '\n') || (str[count] == '\r') \
		|| (str[count] == '\t') || (str[count] == '\v') || (str[count] == '\f'))
		count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	checkMinus;
	int	count;

	result = 0;
	checkMinus = 0;
	count = ft_atoi_dop(str, 0);
	if (ft_strncmp("-2147483648", &str[count], 11) == 0)
		return (-2147483648);
	if (str[count] == '-')
	{
		checkMinus++;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while ((str[count] >= '0' && str[count] <= '9') && str[count] != 0)
	{
		result = (result * 10) + (str[count] - 48);
		count++;
	}
	if (checkMinus == 1)
		return (-result);
	return (result);
}
