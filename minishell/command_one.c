#include "minishell.h"

int command_cd(int count)
{
	char *str;
	char *clear;

	if (var.shell[count].len_arg == 1)
	{
		str = ft_strjoin("/Users/", getenv("USER"));
		chdir(str);
		free(str);
		var.ret = 0;
		return (0);
	}
	if (var.shell[count].arg[1][0] == '~')
	{
		str = ft_strjoin("/Users/", getenv("USER"));
		clear = str;
		str = ft_strjoin(str, &var.shell[count].arg[1][1]);
		free(clear);
	}
	else
		str = var.shell[count].arg[1];
	if (chdir(str) == -1)
	{
		var.ret = 1;
		printf("cd: %s: No such file or directory\n", var.shell[count].arg[1]);
	}
	else
		var.ret = 0;
	return (0);
}

char **writing_argv(int i)
{
	int count;
	char **result;

	count = 0;
	result = malloc(sizeof(char *) * var.shell[i].len_arg + 1);
	while (count < var.shell[i].len_arg)
	{
		result[count] = var.shell[i].arg[count];
		count++;
	}
	result[count] = NULL;
	return (result);
}

char *writing_open_com(int i)
{
	char *result;

	if (var.shell[i].arg[0][0] == '.' || var.shell[i].arg[0][0] == '/')
		return (strdup(var.shell[i].arg[0]));
	result = ft_strjoin("/bin/", var.shell[i].arg[0]);
	return (result);
}

int command_open(int count)
{
	pid_t pid;
	int status;
	char *str;
	char **argv;
	char **rev;

	rev = malloc(sizeof(char *));
	rev[0] = NULL;
	argv = writing_argv(count);
	str = writing_open_com(count);
	pid = fork();
	if (!pid)
	{
		execve(str, argv, rev);
		printf("minishell: command not found: %s\n", var.shell[count].arg[0]);
		exit(127);
	}
	wait(&status);
	var.ret = status >> 8;
	free(str);
	free(rev);
	free(argv);
	return (0);
}