#include "minishell.h"

int count_arg_if(int *count, int *result, int flag)
{
	char c;

	if (flag == 1)
	{
		while (var.str[*count] != ' ' && var.str[*count] && var.str[*count] != ';')
			*count += 1;
		*result += 1;
		if (var.str[*count] == 0 || var.str[*count] == ';')
			return (2);
		return (0);
	}
	c = var.str[*count];
	*count += 1;
	while (var.str[*count] != c && var.str[*count])
		*count += 1;
	*result += 1;
	if (var.str[*count] == 0)
		return (2);
	else
		count[0]++;
	return (0);
}

int count_arg()
{
	int count;
	int result;

	count = (result = 0);
	while (var.str[count] != ';' && var.str[count])
	{	
		if (var.str[count] != ' ' && var.str[count] != 34 && var.str[count] != 39)
		{
			if (count_arg_if(&count, &result, 1))
				break ;
		}
		if (var.str[count] == 34 || var.str[count] == 39)
		{	
			if (count_arg_if(&count, &result, 2))
				break ;
		}
		count++;
	}
	return (result);
}
