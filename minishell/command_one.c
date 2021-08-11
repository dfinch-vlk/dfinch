#include "minishell.h"

int	command_cd_if(char **str, int count)
{
	char	*clear;

	if (count >= 0)
	{
		*str = ft_strjoin("/Users/", getenv("USER"));
		clear = *str;
		*str = ft_strjoin(*str, &g_var.shell[count].arg[1][1]);
		free(clear);
		return (0);
	}
	*str = ft_strjoin("/Users/", getenv("USER"));
	chdir(*str);
	free(*str);
	g_var.ret = 0;
	return (0);
}

int	command_cd(int count)
{
	char	*str;

	if (g_var.shell[count].len_arg == 1)
		return (command_cd_if(&str, -1));
	if (g_var.shell[count].arg[1][0] == '~')
		command_cd_if(&str, count);
	else
		str = ft_strdup(g_var.shell[count].arg[1]);
	if (chdir(str) == -1)
	{
		g_var.ret = 1;
		printf("cd: %s: No such file or directory\n", g_var.shell[count].arg[1]);
	}
	else
		g_var.ret = 0;
	free(str);
	return (0);
}

int	command_open(int count)
{
	char	*envp[1];

	envp[0] = NULL;
	execve(g_var.shell[count].arg[0], g_var.shell[count].arg, envp);
	printf("minishell: command not found: %s\n", g_var.shell[count].arg[0]);
	exit(EXIT_FAILURE);
}
