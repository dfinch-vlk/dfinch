#include "ft_printf.h"

int	ft_X(va_list args, int accuracy, int width, int *array)
{
	long long	number;
	char		*str;

	if (accuracy != -1 && array[0] == 2)
		array[0] = 3;
	number = va_arg(args, long long);
	if (accuracy == 0 && number == 238)
	{
		str = ft_strdup("EE");
		return (args_next(width, add_str(str, accuracy), array[0], accuracy));
	}
	if (accuracy == 0 && number == 0)
		str = ft_strdup("");
	else
		str = ft_system((unsigned)number, 16, 2);
	return (args_next(width, add_str(str, accuracy), array[0], accuracy));
}

int	ft_p(va_list args, int accuracy, int width, int *array)
{
	uint64_t	p_n;
	char		*str;
	int			number;

	p_n = (uint64_t)va_arg(args, char *);
	if (p_n == 0 && accuracy == 0)
		str = ft_strdup("");
	else
		str = ft_system(p_n, 16, 1);
	number = args_next(width, add_str(ft_strjoin("0x", str), \
	accuracy), array[0], accuracy);
	free(str);
	return (number);
}

int	ft_s(va_list args, int accuracy, int width, int *array)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		len = args_next(width, acc_str(str, accuracy), array[0], accuracy);
		free(str);
		return (len);
	}
	len = args_next(width, acc_str(str, accuracy), array[0] + 3, accuracy);
	return (len);
}

int	ft_sc(int accuracy, int width, int *array)
{
	char	*str;

	if (accuracy > 0 || accuracy == -1)
		str = ft_strdup(" ");
	else
		str = ft_strdup("");
	str[0] = '%';
	return (args_next(width, str, array[0], accuracy));
}

int	ft_id(va_list args, int accuracy, int width, int *array)
{
	int		number;
	char	*str;

	if (accuracy >= 0 && array[0] == 2)
		array[0] = 3;
	number = va_arg(args, int);
	if (accuracy == 0 && number == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(number);
	return (args_next(width, add_str(str, accuracy), array[0], accuracy));
}
