#include "ft_printf.h"

int	ft_args1(char *case_width, char *str, int width)
{
	int	count1;
	int	count2;
	int	len;

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

int	ft_args2(char *case_width, char *str)
{
	int	count1;
	int	count2;
	int	len;

	count1 = (count2 = (len = 0));
	while (str[count2])
		case_width[count1++] = str[count2++];
	my_putstr(case_width);
	len = ft_strlen(case_width);
	free(str);
	free(case_width);
	return (len);
}

int	ft_args3(char *str, int width)
{
	int		count1;
	char	*result;
	int		checkMinus;

	if (width < ft_strlen(str))
	{
		count1 = my_putstr(str);
		free(str);
		return (count1);
	}
	count1 = 0;
	result = ft_malloc(width + 1, width, 1);
	if (!result)
		return (0);
	if (str[count1] == '-')
		result[count1++] = '-';
	checkMinus = count1;
	ft_args3_dop(count1, str, result);
	count1 = ft_strlen(result);
	free(str);
	free(result);
	return (count1);
}

int	args_next(int width, char *str, int flag, int accuracy)
{
	char	*case_width;
	int		len;

	len = 0;
	if (flag == 2 || flag == 5)
		return (args_next_dop(accuracy, NULL, str, width));
	if (width < ft_strlen(str))
	{
		len = my_putstr(str);
		free(str);
		return (len);
	}
	case_width = ft_malloc(sizeof(char) * width + 1, width, 0);
	if (!case_width)
		return (-1);
	if (flag == 3 || flag == 6)
	{
		if (accuracy > ft_strlen(str) && flag != 6)
			return (ft_args1(case_width, str, width) + accuracy);
		else
			return (ft_args1(case_width, str, width));
	}
	else
		return (args_next_dop(accuracy, case_width, str, flag * -1));
}

char	*acc_str(char *s, int accuracy)
{
	char	*str;

	str = ft_strdup(s);
	if (accuracy >= 0)
		str[accuracy] = '\0';
	return (str);
}
