#include "push_swap.h"

void	function_sa(t_numbers *array, int len, int write_no)
{
	int	number2;
	int	number1;
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == 1 && array[count].check_b == FALSE)
			number1 = count;
		if (array[count].position == 2 && array[count].check_b == FALSE)
			number2 = count;
		count++;
	}
	array[number1].position++;
	array[number2].position--;
	if (write_no == 1)
		write(1, "sa\n", 3);
}

void	function_sb(t_numbers *array, int len, int write_no)
{
	int	number2;
	int	number1;
	int	count;

	count = 0;
	while (count < len)
	{
		if (array[count].position == 1 && array[count].check_b == TRUE)
			number1 = count;
		if (array[count].position == 2 && array[count].check_b == TRUE)
			number2 = count;
		count++;
	}
	array[number1].position++;
	array[number2].position--;
	if (write_no == 1)
		write(1, "sb\n", 3);
}
