#include "push_swap.h"

void	algoritm_main_end1(t_numbers *array, int len, int pos)
{
	int	count;

	count = 0;
	while (count < count_steck(array, len, TRUE) - pos)
	{
		function_rrb(array, len, 1);
		count++;
	}
}

int	count_steck(t_numbers *array, int len, int flag)
{
	int	count;
	int	result;

	count = (result = 0);
	while (count < len)
	{
		if (array[count].check_b == flag)
			result++;
		count++;
	}
	return (result);
}

int	find_number_position(t_numbers *array, int len, int pos, int flag)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == pos && array[count].check_b == flag)
			return (array[count].number);
		count++;
	}
	return (0);
}

int	**distribution_chanks(int min, int len, int count_chanks)
{
	int	**result;
	int	count1;
	int	count2;

	count2 = 0;
	result = malloc(sizeof(int *) * count_chanks - 1);
	while (count2 < count_chanks - 1)
	{
		result[count2] = malloc(sizeof(int) * (len / count_chanks));
		count1 = 0;
		while (count1 < len / count_chanks)
			result[count2][count1++] = min++;
		count2++;
	}
	return (result);
}

int	check_chanks_numbers(int number, int *chanks, int len_chanks)
{
	int	count;

	count = 0;
	while (count < len_chanks)
	{
		if (number == chanks[count])
			return (TRUE);
		count++;
	}
	return (FALSE);
}
