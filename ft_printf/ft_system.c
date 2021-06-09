#include "libftprintf.h"

uint64_t	ft_system_mem(uint64_t n, uint64_t q)
{
	uint64_t	count;

	count = 0;
	while (n >= q)
	{
		n = n / q;
		count++;
	}
	return (++count);
}

char	condition_system(uint64_t n, uint64_t q, short flag)
{
	if (((n % q) == 10 || n == 10) && flag == 1)
		return ('a');
	if (((n % q) == 10 || n == 10) && flag == 2)
		return ('A');
	if (((n % q) == 11 || n == 11) && flag == 1)
		return ('b');
	if (((n % q) == 11 || n == 11) && flag == 2)
		return ('B');
	if (((n % q) == 12 || n == 12) && flag == 1)
		return ('c');
	if (((n % q) == 12 || n == 12) && flag == 2)
		return ('C');
	if (((n % q) == 13 || n == 13) && flag == 1)
		return ('d');
	if (((n % q) == 13 || n == 13) && flag == 2)
		return ('D');
	if (((n % q) == 14 || n == 14) && flag == 1)
		return ('e');
	if (((n % q) == 14 || n == 14) && flag == 2)
		return ('E');
	if (((n % q) == 15 || n == 15) && flag == 1)
		return ('f');
	if (((n % q) == 15 || n == 15) && flag == 2)
		return ('F');
	return (0);
}

uint64_t	ft_system_dop(char *first, uint64_t n, uint64_t q, uint64_t flag)
{
	uint64_t	count;

	count = 0;
	while (n >= q)
	{
		if ((n % q) <= 15 && (n % q) >= 10 \
		&& q == 16 && flag != 0)
			first[count] = condition_system(n, q, flag);
		else
			first[count] = (n % q) + 48;
		n = n / q;
		count++;
	}
	if (q == 16 && (n >= 10 && n <= 15))
		first[count++] = condition_system(n, 1, flag);
	else
		first[count++] = n + 48;
	first[count] = 0;
	return (--count);
}

char	*ft_system(uint64_t n, uint64_t q, short flag)
{
	char		*first;
	char		*result;
	int			count;
	uint64_t	i;

	first = malloc(sizeof(char) * ft_system_mem(n, q) + 1);
	if (!first)
		return (0);
	result = malloc(sizeof(char) * ft_system_mem(n, q) + 1);
	if (!result)
		return (0);
	i = 0;
	count = ft_system_dop(first, n, q, flag);
	while (count != -1)
	{
		result[i] = first[count];
		i++;
		count--;
	}
	result[i] = 0;
	free(first);
	return (result);
}
