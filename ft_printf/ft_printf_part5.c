#include "ft_printf.h"

int	ft_printf_main_if(int *width, int *count, int array, int arrow)
{
	int	flag;

	if (arrow == 0)
	{
		flag = array;
		if (*width < 0)
		{
			flag = 1;
			*width *= -1;
		}
		if (*count == 0)
			*count += 1;
		if (flag != array)
			return (flag);
		return (array);
	}
	if (array == 0)
		flag = '%';
	else
		flag = array;
	return (flag);
}

void	ft_args3_dop(int count1, char *str, char *result)
{
	int	count2;

	count2 = ft_strlen(result) - ft_strlen(str) + count1;
	while (str[count1])
		result[count2++] = str[count1++];
	my_putstr(result);
}

int	args_next_dop(int accuracy, char *case_width, char *str, int flag)
{
	if (flag == -1 || flag == -4)
	{
		if (accuracy > ft_strlen(str) && flag != -4)
			return (ft_args2(case_width, str) + accuracy);
		else
			return (ft_args2(case_width, str));
	}
	else
	{
		if (accuracy > ft_strlen(str) && flag != 5)
			return (ft_args3(str, flag) + accuracy);
		else
			return (ft_args3(str, flag));
	}
	return (0);
}
