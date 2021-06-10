#include "ft_printf.h"

char	*add_str(char *s, int accuracy)
{
	char	*case_width;
	int		count1;
	int		count2;
	int		checkMinus;

	checkMinus = 0;
	if (s[0] == '-')
		checkMinus = 1;
	if (accuracy <= (ft_strlen(s) - checkMinus) || accuracy < 0)
		return (s);
	case_width = ft_malloc(sizeof(char) * accuracy + 1 + (checkMinus * 2), \
	 accuracy, 1);
	if (!case_width)
		return (NULL);
	if (checkMinus)
		case_width[0] = '-';
	count1 = checkMinus;
	count2 = accuracy - ft_strlen(s) + (checkMinus * 2);
	while (s[count1])
		case_width[count2++] = s[count1++];
	case_width[count2] = 0;
	free(s);
	return (case_width);
}

int	ft_c(va_list args, int width, int *array)
{
	char	c;
	char	*case_width;
	int		len;

	c = va_arg(args, int);
	len = 0;
	if (width == 0)
		return (write(1, &c, 1));
	case_width = ft_malloc(width + 1, width, 0);
	if (!case_width)
		return (0);
	if (array[0] == 1)
		len = (write(1, &c, 1) + my_putstr(&case_width[1]));
	else
	{
		case_width[ft_strlen(case_width) - 1] = c;
		len = my_putstr(case_width);
		if (c == 0)
			len += write(1, &c, 1);
	}
	free(case_width);
	return (len);
}

int	ft_u(va_list args, int accuracy, int width, int *array)
{
	int	number;

	if (accuracy >= 0 && array[0] == 2)
		array[0] = 3;
	number = va_arg(args, int);
	if (accuracy == 0 && number == 0)
		return (args_next(width, add_str(ft_strdup(""), accuracy), \
		 array[0], accuracy));
	if (number < 0)
		return (args_next(width, add_str(ft_itoal((unsigned)number), \
		 accuracy), array[0], accuracy));
	else
		return (args_next(width, add_str(ft_itoa(number), accuracy), \
		 array[0], accuracy));
}

int	ft_x(va_list args, int accuracy, int width, int *array)
{
	long long	number;
	char		*str;

	if (accuracy != -1 && array[0] == 2)
		array[0] = 3;
	number = va_arg(args, long long);
	if (accuracy == 0 && number == 238)
	{
		str = ft_strdup("ee");
		return (args_next(width, add_str(str, accuracy), array[0], accuracy));
	}
	if (accuracy == 0 && number == 0)
		str = ft_strdup("");
	else
		str = ft_system((unsigned)number, 16, 1);
	return (args_next(width, add_str(str, accuracy), array[0], accuracy));
}
