#include "push_swap.h"

void	dop1(t_numbers *array, int len)
{
	if (count_steck(array, len, TRUE) >= 2 && position_number_max(array, len, TRUE) \
			== count_steck(array, len, TRUE))
		function_rrb(array, len, 1);
	function_pb(array, len, 1);
	if (count_steck(array, len, TRUE) >= 2 \
		&& position_number_min(array, len, TRUE) == 1)
		function_rb(array, len, 1);
}	

void	dop2(t_numbers *array, int len, const char **argv)
{
	int	count;

	count = 0;
	while (count < len)
	{
		array[count].number = ft_atoi(&argv[count + 1][0], array);
		array[count].check_b = FALSE;
		array[count].position = count + 1;
		count++;
	}
}
