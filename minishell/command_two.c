#include "minishell.h"

int command_env()
{
	int count;

	count = 0;
	while (count < var.len_vars)
		printf("%s\n", var.vars[count++]);
	var.ret = 0;
	return (0);
}

int command_unset(int count)
{
	int count1;

	count1 = 1;
	while (count1 < var.shell[count].len_arg)
		delite_var(var.shell[count].arg[count1++]);
	var.ret = 0;
	return (0);
}

int command_export(int count)
{
	int count1;

	count1 = 1;
	while (count1 < var.shell[count].len_arg)
		add_var(var.shell[count].arg[count1++]);
	var.ret = 0;
	return (0);
}