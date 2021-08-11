#include "minishell.h"

int	command_env(void)
{
	int	count;

	count = 0;
	while (count < g_var.len_vars)
	{
		if (g_var.vars[count])
			printf("%s\n", g_var.vars[count]);
		count++;
	}
	g_var.ret = 0;
	return (0);
}

int	command_unset(int count)
{
	int	count1;

	count1 = 1;
	while (count1 < g_var.shell[count].len_arg)
		delite_var(g_var.shell[count].arg[count1++]);
	g_var.ret = 0;
	return (0);
}

int	command_export(int count)
{
	int	count1;

	count1 = 1;
	while (count1 < g_var.shell[count].len_arg)
		add_var(g_var.shell[count].arg[count1++]);
	g_var.ret = 0;
	return (0);
}
