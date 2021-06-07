#include "libftprintf.h"
#include <stdio.h>

int conditions(int symbol)
{
	if (symbol == 'c' || symbol == 's' || \
		symbol == 'p' || symbol == 'd' || \
		symbol == 'i' || symbol == 'u' || \
		symbol == 'x' || symbol == 'X')
		return (1);
	return (0);
}

int my_putstr(char *str)
{
	int count;

	count = 0;
	while(str[count])
		write(1, &str[count++], 1);
	return (count);
}

char *ft_malloc(int size, int width, int flag)
{
	int count;
	char *result;

	result = malloc(size);
	if (!result)
		return (NULL);
	count = 0;
	while (count < width + 1)
	{
		if (flag == 0)
			result[count++] = ' ';
		if (flag == 1)
			result[count++] = '0';
	}
	result[count - 1] = 0;
	return (result);
}

int ft_args1(char *case_width, char *str, int width)
{
	int count1;
	int count2;
	int len;

	count1 = (count2 = (len = 0));
	count2 = width - ft_strlen(str);
	while (str[count1])
		case_width[count2++] = str[count1++];
	my_putstr(case_width);
	len = ft_strlen(case_width);
	free(case_width);
	free(str);
	return (len);
}

int ft_args2(char *case_width, char *str)
{
	int count1;
	int count2;
	int len;

	count1 = (count2 = (len = 0));
	while (str[count2])
		case_width[count1++] = str[count2++];
	my_putstr(case_width);
	len = ft_strlen(case_width);
	free(str);
	free(case_width);
	return (len);
}
int ft_printf_args_next(int width, char *str, int flag)
{
	char *case_width;
	int len;
	
	len = 0;
	if (width < ft_strlen(str))
	{
		len = my_putstr(str);
		free(str);
		return (len);
	}
	case_width = ft_malloc(sizeof(char) * width + 1, width, 0);
	if (!case_width)
		return (-1);
	if (flag == 2 || flag == 3)
		return (ft_args1(case_width, str, width));
	else
		return (ft_args2(case_width, str));
 }

char *acc_str(char *s, int accuracy)
{
	char *str;
	str = ft_strdup(s);
	if (accuracy >= 0)
		str[accuracy] = '\0';
	return (str);
}

char *add_str(char *s, int accuracy)
{
	char *case_width;
	int count1;
	int count2;
	int checkMinus;

	checkMinus = 0;
	if (s[0] == '-')
		checkMinus = 1;
	if (accuracy <= (ft_strlen(s) - checkMinus) || accuracy < 0)
		return (s);
	case_width = ft_malloc(sizeof(char) * accuracy + 1 + (checkMinus * 2), accuracy, 1);
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
int ft_c(va_list args, int accuracy, int width, int *array)
{
	char *str;

	if (accuracy > 0 || accuracy == -1)
		str = ft_strdup(" ");
	else
		str = ft_strdup("");
	str[0] = va_arg(args, int);
	return (ft_printf_args_next(width, str, array[0]));
}

int ft_u(va_list args, int accuracy, int width, int *array)
{
	int number;

	number = va_arg(args, int);
	if (number < 0)
		return (ft_printf_args_next(width, add_str(ft_itoal((unsigned)number), accuracy), array[0]));
	else
		return (ft_printf_args_next(width, add_str(ft_itoa(va_arg(args, int)), accuracy), array[0]));
}

int ft_x(va_list args, int accuracy, int width, int *array)
{
		int number;

		number = va_arg(args, int);
		return (ft_printf_args_next(width, add_str(ft_system((unsigned)number, 16, 1), accuracy), array[0]));
}

int ft_X(va_list args, int accuracy, int width, int *array)
{
		int number;

		number = va_arg(args, int);
		return (ft_printf_args_next(width, add_str(ft_system((unsigned)number, 16, 2), accuracy), array[0]));
}

int ft_p(va_list args, int accuracy, int width, int *array)
{
	long p_n;
	char *str;
	int number;

	p_n = (long)va_arg(args, char *);
	str = ft_system(p_n, 16, 1);
	number = ft_printf_args_next(width, add_str(ft_strjoin("0x", str), accuracy), array[0]);
	free(str);
	return (number);
}

int ft_s(va_list args, int accuracy, int width, int *array)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	return (ft_printf_args_next(width, acc_str(str, accuracy), array[0]));
}

int ft_printf_args(int width, int accuracy, int *array, va_list args)
{
	if (array[1] == 's')
		return (ft_s(args, accuracy, width, array));
	if (array[1] == 'c')
		return (ft_c(args, accuracy, width, array));
	if (array[1] == 'd' || array[1] == 'i')
		return (ft_printf_args_next(width, add_str(ft_itoa(va_arg(args, int)), accuracy), array[0]));
	if (array[1] == 'u')
		return (ft_u(args, accuracy, width, array));
	if (array[1] == 'x')
		return (ft_x(args, accuracy, width, array));
	if (array[1] == 'X')
		return (ft_X(args, accuracy, width, array));
	if (array[1] == 'p')
		return (ft_p(args, accuracy, width, array));
	return (1);
}

int ft_flag(int *flag, int symbol)
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

int fr_printf_main(char *str, va_list args)
{
	int width;
	int accuracy;
	int count;
	int array[2];

	accuracy = -1;
	width = 0;
	count = ft_flag(&array[0], str[1]);
	if (str[count + 1] == '*')
		width = va_arg(args, int);
	else
		width = ft_atoi(&str[count + 1]);
	while (!conditions(str[count]))
		if (str[count++] == '.')
		{
			if (str[count] == '*')
				accuracy = va_arg(args, int);
			else
				accuracy = ft_atoi(&str[count]);
		}
	array[1] = str[count];
	return(ft_printf_args(width, accuracy, array, args));
}

int ft_printf(char *str, ...)
{
	int len;
	int count;
	char *p_arg;
	va_list args;

	len = 0;
	count = 0;
	va_start(args, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			p_arg = &str[count];
			while (!conditions(str[count]) && str[count] != 0)
				count++;
			len = fr_printf_main(p_arg, args);
			if (str[count] == 0)
				return (len);
			count++;
		}
		else
			len += write(1, &str[count++], 1);
	}
	va_end(args);
	return (len);
}