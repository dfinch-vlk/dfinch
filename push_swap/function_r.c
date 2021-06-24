#include "push_swap.h"

void	function_ra(t_numbers *array, int len, int write_no)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == 1 && array[count].check_b == FALSE)
			break ;
		count++;
	}
	array[count].position = count_steck(array, len, FALSE) + 1;
	count = 0;
	while (count < len)
	{
		if (array[count].check_b == FALSE)
			array[count].position--;
		count++;
	}
	if (write_no == 1)
		write(1, "ra\n", 3);
}

void	function_rb(t_numbers *array, int len, int write_no)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == 1 && array[count].check_b == TRUE)
			break ;
		count++;
	}
	array[count].position = count_steck(array, len, TRUE) + 1;
	count = 0;
	while (count < len)
	{
		if (array[count].check_b == TRUE)
			array[count].position--;
		count++;
	}
	if (write_no == 1)
		write(1, "rb\n", 3);
}
