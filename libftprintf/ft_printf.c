#include "libftprintf.h"

int	condition(char c1, char c2)
{
	if (c1 == '%' && (c2 == 's' || c2 == 'i' \
		|| c2 == 'd' || c2 == 'c' || c2 == 'C' \
		|| c2 == 'o' || c2 == 'x' || c2 == 'X'))
		return (1);
	return (0);
}

int	countStr(const char *str, int count, int flag)
{
	int	len;
	int	countArg;

	len = 0;
	countArg = 0;
	while (str[count])
	{
		if (condition(str[count], str[count + 1]) == 1)
		{
			if (flag == 1)
				return (count);
			else if (flag == 2)
				return (len);
			countArg++;
		}
		else if (flag == 1 || flag == 3)
			write (1, &str[count], 1);
		len++;
		count++;
	}
	if (flag == 4)
		return (countArg);
	return (len);
}

int	ft_printf_dop(va_list result, char c)
{
	if (c == 's')
		return (ft_putstr(va_arg(result, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putstr(ft_itoa(va_arg(result, int))));
	if (c == 'c' || c == 'C')
		return (ft_putchar(va_arg(result, int)));
	if (c == 'o')
		return (ft_putstr(ft_system(va_arg(result, int), 8, 0)));
	if (c == 'x')
		return (ft_putstr(ft_system(va_arg(result, int), 16, 1)));
	if (c == 'X')
		return (ft_putstr(ft_system(va_arg(result, int), 16, 2)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	result;
	int		count;
	int		args;
	int		len;

	count = 1;
	args = countStr(str, 0, 1);
	va_start(result, (int)countStr(str, 0, 4));
	len = (ft_printf_dop(result, str[args + 1]) + countStr(str, 0, 2));
	while (count < countStr(str, 0, 4))
	{	
		len += countStr(str, args + 2, 2);
		args = countStr(str, args + 2, 1);
		len += ft_printf_dop(result, str[args + 1]);
		count++;
	}
	len += countStr(str, args + 2, 3);
	va_end(result);
	return (len);
}
