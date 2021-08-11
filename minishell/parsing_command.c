#include "minishell.h"

void	command_exit(void)
{
	freendom();
	free_var();
	exit(1);
}

int	ft_check_builtin(void)
{
	if (!ft_strcmp("exit", g_var.shell[0].arg[0])
		|| (!ft_strcmp("pwd", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("cd", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("env", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("unset", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("export", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("echo", g_var.shell[0].arg[0])))
		return (1);
	return (-1);
}

int	parsing_command(int count)
{
	if (!ft_strcmp("exit", g_var.shell[count].arg[0]))
		command_exit();
	if (!ft_strcmp("pwd", g_var.shell[count].arg[0]))
	{
		printf("%s\n", getcwd(NULL, 12421));
		return (0);
	}
	if (!ft_strcmp("cd", g_var.shell[count].arg[0]))
		return (command_cd(count));
	if (!ft_strcmp("env", g_var.shell[count].arg[0]))
		return (command_env());
	if (!ft_strcmp("unset", g_var.shell[count].arg[0]))
		return (command_unset(count));
	if (!ft_strcmp("export", g_var.shell[count].arg[0]))
		return (!command_export(count));
	if (!ft_strcmp("echo", g_var.shell[count].arg[0]))
		return (!command_echo(count));
	return (-1);
}
