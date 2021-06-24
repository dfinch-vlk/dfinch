#include "push_swap.h"

void	algoritm_main_end(t_numbers *array, int len)
{
	int	pos;
	int	count;

	while (count_steck(array, len, TRUE))
	{
		count = 0;
		pos = position_number_max(array, len, TRUE) - 1;
		if (pos <= count_steck(array, len, TRUE) / 2)
		{
			while (count + 1 < pos)
			{
				function_rb(array, len, 1);
				count++;
			}
			if (pos != 0)
				function_sb(array, len, 1);
		}
		else
			algoritm_main_end1(array, len, pos);
		function_pa(array, len, 1);
	}
}

void	algoritm_main_next_1(int steps1, int steps2, t_numbers *array, int len)
{
	int	count;

	count = 0;
	if (steps1 <= steps2)
	{
		while (count < steps1)
		{
			function_ra(array, len, 1);
			count++;
		}
	}
	else
	{
		while (count < steps2)
		{
			function_rra(array, len, 1);
			count++;
		}
	}
	dop1(array, len);
}

void	algoritm_main_next(t_numbers *array, int len, int *chanks, int len_ch)
{
	int	count1;
	int	count2;
	int	len_count;

	len_count = count_steck(array, len, FALSE);
	count1 = (count2 = 0);
	while (1)
	{
		if (check_chanks_numbers(find_number_position(array, len, count1 + 1, FALSE) \
			, chanks, len_ch))
			break ;
		count1++;
	}
	while (1)
	{
		count2++;
		if (check_chanks_numbers(find_number_position(array, len, len_count--, FALSE) \
			, chanks, len_ch))
			break ;
	}
	algoritm_main_next_1(count1, count2, array, len);
}

void	last_push_b(t_numbers *array, int len)
{
	while (count_steck(array, len, FALSE))
	{
		if (count_steck(array, len, FALSE) >= 2 && position_number_min(array, len, FALSE) \
		 == count_steck(array, len, FALSE))
			function_rra(array, len, 1);
		if (count_steck(array, len, FALSE) >= 2 && find_number_position(array, len, 1, FALSE) \
		 > find_number_position(array, len, 2, FALSE))
			function_sa(array, len, 1);
		function_pb(array, len, 1);
		if (find_number_position(array, len, 1, TRUE) < find_number_position \
			(array, len, 2, TRUE))
			function_sb(array, len, 1);
	}
	algoritm_main_end(array, len);
	exit(1);
}

void	algoritm_main(t_numbers *array, int len)
{
	int	**chanks;
	int	count_chanks;
	int	count1;
	int	count2;

	count1 = (count2 = 0);
	count_chanks = 5;
	if (len >= 400)
		count_chanks = 13;
	chanks = distribution_chanks \
	(number_min(array, len, FALSE), len, count_chanks);
	while (count2 < count_chanks - 1)
	{	
		if (count1 == len / count_chanks)
		{
			count1 = 0;
			count2++;
		}
		if (count2 >= count_chanks - 1)
			break ;
		count1++;
		algoritm_main_next(array, len, chanks[count2], len / count_chanks);
	}
	free(chanks);
	last_push_b(array, len);
}
