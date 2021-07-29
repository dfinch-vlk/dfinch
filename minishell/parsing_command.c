#include "minishell.h"

int parsing_command(int count)
{
	if (!strcmp("exit", var.shell[count].arg[0]))
		exit(0);
	if (!strcmp("pwd", var.shell[count].arg[0]))
	{
		printf("%s\n", getcwd(NULL, 12421));
		return (0);
	}
	if (!strcmp("clear", var.shell[count].arg[0]))
		return (clrscr());
	if (!strcmp("cd", var.shell[count].arg[0]))
		return (command_cd(count));
	if (!strcmp("env", var.shell[count].arg[0]))
		return (command_env());
	if (!strcmp("unset", var.shell[count].arg[0]))
		return (command_unset(count));
	if (!strcmp("export", var.shell[count].arg[0]))
		return (!command_export(count));
	if (!strcmp("echo", var.shell[count].arg[0]))
		return (!command_echo(count));
	return (command_open(count));
}