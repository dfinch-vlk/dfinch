#include "libftprintf.h"

int		countArg(const char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 's' || str[i + 1] == 'i' \
			|| str[i + 1] == 'c' || str[i + 1] == 'C'))
			count++;
		i++;
	}
	return (count);
}

int		countStr(const char *str, int count, int flag)
{
	int	len;

	len = 0;
	while (str[count])
	{
		if (str[count] == '%' && (str[count + 1] == 's' || str[count + 1] == 'i' \
			|| str[count + 1] == 'c' || str[count + 1] == 'C'))
		{
			if (flag == 1)
				return (count);
			else if (flag == 2)
				return (len);
		}
		else if (flag == 1 || flag == 3)
			write (1, &str[count], 1);
		len++;
		count++;
	}
	return (len);
}


int ft_printf_dop(va_list result, const char *str, int count)
{
	char *s;
	int len;
	char c;

	if (str[count] == 's')
	{
		s = va_arg(result, char *);
		ft_putstr(s);
	}
	if (str[count] == 'i')
	{
		s = ft_itoa(va_arg(result, int));
		ft_putstr(s);
	}
	if (str[count] == 'c' || str[count] == 'C')
	{
		c = va_arg(result, int);
		write (1, &c, 1);
		return (1);
	}
	len = (int)ft_strlen(s);
	return (len);
}

int ft_printf(const char *str, ...)
{
	va_list result;
	int count;
	int args;
	int	len;

	len = 0;
	count = countArg(str);
	args = countStr(str, 0, 1);
	va_start(result, count);
	count = 1;
	len += (ft_printf_dop(result, str, args + 1) + countStr(str, 0, 2));
	while (count < countArg(str))
	{	
		len += countStr(str, args + 2, 2);
		args = countStr(str, args + 2, 1);
		len += ft_printf_dop(result, str, args + 1);
		count++;
	}
	len += countStr(str, args + 2, 3);
	va_end(result);
	return (len);
}

int main() {
  char i[] = "Hello";
  char q[] = "World";
  int d = 122;
  ft_printf("%i \n", ft_printf("1234%s %s %c", i, q, 'W'));
  return 0;
}