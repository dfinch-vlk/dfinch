#include "push_swap.h"

int	ft_atoi_dop(const char *str, int count)
{
	while ((str[count] == ' ') || (str[count] == '\n') || (str[count] == '\r') \
		|| (str[count] == '\t') || (str[count] == '\v') || (str[count] == '\f'))
		count++;
	return (count);
}

int	ft_atoi(const char *str, t_numbers *array)
{
	long	result;
	int		checkMinus;
	int		count;

	result = 0;
	checkMinus = 0;
	count = ft_atoi_dop(str, 0);
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
	if (result > 2147483647 || result < -2147483648)
		error(array);
	return (result);
}

int	count_space(const char *str)
{
	int	count;
	int	result;

	count = (result = 0);
	while (str[count])
		if (str[count++] == ' ')
			result++;
	return (result);
}

void	error(t_numbers *array)
{
	free(array);
	write(1, "Error!\n", 7);
	exit(-1);
}
