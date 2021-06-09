#include "libftprintf.h"

int	ft_printf_args(int width, int accuracy, int *array, va_list args)
{
	if (array[1] == 's')
		return (ft_s(args, accuracy, width, array));
	if (array[1] == 'c')
		return (ft_c(args, accuracy, width, array));
	if (array[1] == 'd' || array[1] == 'i')
		return (ft_id(args, accuracy, width, array));
	if (array[1] == 'u')
		return (ft_u(args, accuracy, width, array));
	if (array[1] == 'x')
		return (ft_x(args, accuracy, width, array));
	if (array[1] == 'X')
		return (ft_X(args, accuracy, width, array));
	if (array[1] == 'p')
		return (ft_p(args, accuracy, width, array));
	if (array[1] == '%')
		return (ft_sc(accuracy, width, array));
	return (1);
}

int	ft_flag(int *flag, int symbol)
{
	if (symbol == '-')
	{
		*flag = 1;
		return (1);
	}
	if (symbol == '0')
	{
		*flag = 2;
		return (1);
	}
	else
	{
		*flag = 3;
		return (0);
	}
}

int	find_num(const char *str, va_list args, int *flag, int *check)
{
	int	count;

	count = 0;
	*check = 0;
	while (str[count] == '-' || str[count] == '0' || str[count] == ' ')
	{
		if (str[count] == ' ')
			*check = 1;
		if (str[count] == '-')
			*flag = 1;
		count++;
	}
	if (*check == 1)
		write(1, " ", 1);
	if (str[count] == '*')
		return (va_arg(args, int));
	else
		return (ft_atoi(&str[count]));
}

int	fr_printf_main(const char *str, va_list args)
{
	int	width;
	int	accuracy;
	int	count;
	int	array[2];
	int	check;

	accuracy = -1;
	width = 0;
	count = ft_flag(&array[0], str[1]);
	width = find_num(&str[count + 1], args, &array[0], &check);
	array[0] = ft_printf_main_if(&width, &count, array[0], 0);
	while (!conditions(str[count]) && str[count])
	{
		if (str[count++] == '.')
		{
			if (str[count] == '*')
				accuracy = va_arg(args, int);
			else
				accuracy = ft_atoi(&str[count]);
		}
	}
	array[1] = ft_printf_main_if(0, &count, str[count], 1);
	return (ft_printf_args(width, accuracy, array, args) + check);
}

int	ft_printf(const char *str, ...)
{
	int			len;
	int			count;
	const char	*p_arg;
	va_list		args;

	len = 0;
	count = 0;
	va_start(args, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			p_arg = &str[count++];
			while (!conditions(str[count]) && str[count] != 0)
				count++;
			len += fr_printf_main(p_arg, args);
			if (str[count++] == 0)
				return (len);
		}
		else
			len += write(1, &str[count++], 1);
	}
	va_end(args);
	return (len);
}
