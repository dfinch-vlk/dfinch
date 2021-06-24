#include "push_swap.h"

void	function_rra(t_numbers *array, int len, int write_no)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == \
		count_steck(array, len, FALSE) && array[count].check_b == FALSE)
			break ;
		count++;
	}
	array[count].position = 0;
	count = 0;
	while (count < len)
	{
		if (array[count].check_b == FALSE)
			array[count].position++;
		count++;
	}
	if (write_no == 1)
		write(1, "rra\n", 4);
}

void	function_rrb(t_numbers *array, int len, int write_no)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == \
		count_steck(array, len, TRUE) && array[count].check_b == TRUE)
			break ;
		count++;
	}
	array[count].position = 0;
	count = 0;
	while (count < len)
	{
		if (array[count].check_b == TRUE)
			array[count].position++;
		count++;
	}
	if (write_no == 1)
		write(1, "rrb\n", 4);
}
