#include "minishell.h"

char	*parsing_new_if(char *s, int point)
{
	char	*result;
	char	*clear;

	s[point] = 0;
	s[point + 1] = '\n';
	result = ft_strdup(s);
	clear = result;
	result = ft_strjoin(result, &s[point + 1]);
	free(clear);
	return (result);
}

void	parsing_new_line(int i)
{
	int	count;
	int	count1;

	count = (count1 = 0);
	while (count < g_var.shell[i].len_arg)
	{
		count1 = 0;
		while (g_var.shell[i].arg[count][count1])
		{
			if (g_var.shell[i].arg[count][count1] == 92 \
				&& g_var.shell[i].arg[count][count1 + 1] == 'n')
				g_var.shell[i].arg[count] = \
			parsing_new_if(g_var.shell[i].arg[count], count1);
			count1++;
		}
		count++;
	}
}

void	parsing_final_if(int i, char **str, int *count, int next)
{
	int		count1;
	char	*clear;

	free(*str);
	g_var.shell[i].arg[next][count[0]++] = 0;
	*str = ft_strdup(&g_var.shell[i].arg[next][1]);
	count1 = *count;
	while (g_var.shell[i].arg[next][count1] != \
		' ' && g_var.shell[i].arg[next][count1])
		count1++;
	g_var.shell[i].arg[next][count1++] = 0;
	clear = *str;
	str[0] = ft_strjoin(*str, \
		find_var_result(&g_var.shell[i].arg[next][*count]));
	free(clear);
	clear = *str;
	str[0] = ft_strjoin(*str, &g_var.shell[i].arg[next][count1]);
	free(clear);
}

int	parsing_final(int i)
{
	int		count;
	char	*str;
	int		next;

	next = 0;
	while (next < g_var.shell[i].len_arg)
	{
		str = ft_strdup(&g_var.shell[i].arg[next][1]);
		count = 0;
		while (g_var.shell[i].arg[next][count])
		{
			if (g_var.shell[i].arg[next][0] == '1' && g_var.shell[i].arg[next][count] == '$' \
				&& g_var.shell[i].arg[next][count + 1] != ' ' \
				&& g_var.shell[i].arg[next][count + 1] != 0)
				parsing_final_if(i, &str, &count, next);
			count++;
		}
		free(g_var.shell[i].arg[next]);
		g_var.shell[i].arg[next] = str;
		next++;
	}
	parsing_new_line(i);
	return (0);
}
