#include "push_swap.h"

void	function_pb(t_numbers *array, int len, int write_no)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == 1 && array[count].check_b == FALSE)
			break ;
		count++;
	}
	array[count].position--;
	array[count].check_b = TRUE;
	count = 0;
	while (count < len)
	{
		if (array[count].check_b == TRUE)
			array[count].position++;
		else
			array[count].position--;
		count++;
	}
	if (write_no == 1)
		write(1, "pb\n", 3);
}

void	function_pa(t_numbers *array, int len, int write_no)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == 1 && array[count].check_b == TRUE)
			break ;
		count++;
	}
	array[count].position--;
	array[count].check_b = FALSE;
	count = 0;
	while (count < len)
	{
		if (array[count].check_b == FALSE)
			array[count].position++;
		else
			array[count].position--;
		count++;
	}
	if (write_no == 1)
		write(1, "pa\n", 3);
}
