#include "minishell.h"

void parsing_final_if(int i, char **str, int *count, int next)
{
	int count1;
	char *clear;

	free(*str);
	var.shell[i].arg[next][count[0]++] = 0;
	*str = strdup(&var.shell[i].arg[next][1]);
	count1 = *count;
	while (var.shell[i].arg[next][count1] != ' ' && var.shell[i].arg[next][count1])
		count1++;
	var.shell[i].arg[next][count1++] = 0;
	clear = *str;
	str[0] = ft_strjoin(*str, find_var_result(&var.shell[i].arg[next][*count]));
	free(clear);
	clear = *str;
	str[0] = ft_strjoin(*str, &var.shell[i].arg[next][count1]);
	free(clear);
}

int parsing_final(int i)
{
	int count;
	char *str;
	int next;

	next = 0;
	while (next < var.shell[i].len_arg)
	{
		str = strdup(&var.shell[i].arg[next][1]);
		count = 0;
		while (var.shell[i].arg[next][count])
		{
			if (var.shell[i].arg[next][0] == '1' && var.shell[i].arg[next][count] == '$' \
				&& var.shell[i].arg[next][count + 1] != ' ' && var.shell[i].arg[next][count + 1] != 0)
				parsing_final_if(i, &str, &count, next);
			count++;
		}
		free(var.shell[i].arg[next]);
		var.shell[i].arg[next] = str;
		next++;
	}
	return (0);
}