#include "push_swap.h"

void	algoritm_three(t_numbers *array, int len)
{
	int	max;
	int	min;

	max = position_number_max(array, len, FALSE);
	min = position_number_min(array, len, FALSE);
	if (max == 3 && min == 2)
		function_sa(array, len, 1);
	if (max == 1)
	{
		function_ra(array, len, 1);
		if (position_number_min(array, len, FALSE) == 2)
			function_sa(array, len, 1);
		return ;
	}
	if (max == 2)
	{
		if (min == 1)
		{
			function_sa(array, len, 1);
			function_ra(array, len, 1);
		}
		else
			function_rra(array, len, 1);
	}
	return ;
}

void	algoritm_two(t_numbers *array, int len)
{
	if (find_number_position(array, len, 1, FALSE) \
		> find_number_position(array, len, 2, FALSE))
		function_sa(array, len, 1);
	exit(1);
}

void	algoritm_small_begin(t_numbers *array, int len)
{
	int	count;
	int	steps;

	count = 0;
	steps = position_number_min(array, len, FALSE) - 1;
	while (count < steps)
	{
		function_ra(array, len, 1);
		count++;
	}
}

void	algoritm_small_end(t_numbers *array, int len)
{
	int	count;
	int	steps;

	count = 0;
	steps = count_steck(array, len, FALSE) \
	- position_number_min(array, len, FALSE) + 1;
	while (count < steps)
	{
		function_rra(array, len, 1);
		count++;
	}
}

void	algoritm_small(t_numbers *array, int len)
{
	int	count;

	count = 0;
	if (len == 2)
		algoritm_two(array, len);
	while (count_steck(array, len, FALSE) != 3)
	{	
		if (position_number_min(array, len, FALSE) \
		<= count_steck(array, len, FALSE) / 2)
			algoritm_small_begin(array, len);
		else
			algoritm_small_end(array, len);
		function_pb(array, len, 1);
	}
	algoritm_three(array, len);
	while (count < len - 3)
	{
		function_pa(array, len, 1);
		count++;
	}
}
