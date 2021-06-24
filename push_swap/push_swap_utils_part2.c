#include "push_swap.h"

int	position_number_max(t_numbers *array, int len, int flag)
{
	int	count;
	int	max;
	int	result;

	max = -2147483648;
	count = 0;
	while (count < len)
	{
		if (array[count].number >= max && array[count].check_b == flag)
		{
			result = array[count].position;
			max = array[count].number;
		}
		count++;
	}
	return (result);
}

int	position_number_min(t_numbers *array, int len, int flag)
{
	int	count;
	int	min;
	int	result;

	min = 2147483647;
	count = 0;
	while (count < len)
	{
		if (array[count].number <= min && array[count].check_b == flag)
		{
			result = array[count].position;
			min = array[count].number;
		}
		count++;
	}
	return (result);
}

int	number_min(t_numbers *array, int len, int flag)
{
	int	count;
	int	min;

	min = 2147483647;
	count = 0;
	while (count < len)
	{
		if (array[count].number <= min && array[count].check_b == flag)
			min = array[count].number;
		count++;
	}
	return (min);
}

int	number_max(t_numbers *array, int len, int flag)
{
	int	count;
	int	max;

	max = -2147483648;
	count = 0;
	while (count < len)
	{
		if (array[count].number >= max && array[count].check_b == flag)
			max = array[count].number;
		count++;
	}
	return (max);
}
