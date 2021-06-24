#include "push_swap.h"

void	check_numbers(int argc, const char *argv[])
{
	int	count1;
	int	count2;

	count2 = 1;
	if (argc == 1)
		exit(-1);
	while (count2 < argc)
	{	
		count1 = 0;
		while (argv[count2][count1])
		{
			if ((argv[count2][count1] < 48 || argv[count2][count1] \
		> 57) && argv[count2][count1] != ' ' && argv[count2][count1] != '-')
			{
				write(1, "Error!\n", 7);
				exit(-1);
			}
			count1++;
		}
		count2++;
	}
}

void	writing_in_array(t_numbers *array, int len, int argc, const char **argv)
{
	int	count1;
	int	count2;

	count1 = (count2 = 0);
	if (argc == 2)
	{	
		while (argv[1][count1])
		{
			if (argv[1][count1] == ' ' || count1 == 0)
			{
				array[count2].number = ft_atoi(&argv[1][count1], array);
				array[count2].check_b = FALSE;
				array[count2].position = count2 + 1;
				count2++;
			}
			count1++;
		}
		return ;
	}
	dop2(array, len, argv);
}

int	success_sort(t_numbers *array, int len)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (find_number_position(array, len, count, FALSE) \
		> find_number_position(array, len, 1 + count, FALSE))
			return (FALSE);
		count++;
	}
	return (TRUE);
}

int	main(int argc, char const *argv[])
{
	t_numbers	*array;
	int			len;

	check_numbers(argc, argv);
	if (argc == 2)
		array = malloc(sizeof(stack_t) * (len = count_space(argv[1]) + 1));
	else
		array = malloc(sizeof(stack_t) * (len = argc - 1));
	if (!array)
		error(array);
	writing_in_array(array, len, argc, argv);
	if (success_sort(array, len) == TRUE)
	{
		free(array);
		return (0);
	}
	if (len == 3)
		algoritm_three(array, len);
	if (len <= 20)
		algoritm_small(array, len);
	else
		algoritm_main(array, len);
	free(array);
	return (0);
}
