#include "minishell.h"

void	ft_def_output(int count)
{
	int		i;

	i = 0;
	g_var.shell[count].fd_output = 1;
	while (g_var.shell[count].len_arg > i && (g_var.shell[count].fd_output != -1))
	{
		if (g_var.shell[count].arg[i] && g_var.shell[count].arg[i][0] == '>')
		{
			if (g_var.shell[count].fd_output != 1)
				close (g_var.shell[count].fd_output);
			if (g_var.shell[count].arg[i][1] == '>')
				g_var.shell[count].fd_output = open(g_var.shell[count].arg[i + 1],
						O_CREAT | O_APPEND | O_WRONLY, S_IRWXU);
			else
				g_var.shell[count].fd_output = open(g_var.shell[count].arg[i + 1],
						O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
			if (g_var.shell[count].fd_output == -1)
				printf("minishell: %s: %s\n", g_var.shell[count].arg[i + 1],
					strerror(errno));
			g_var.shell[count].arg[i] = NULL;
			g_var.shell[count].arg[i + 1] = NULL;
			i++;
		}
		i++;
	}
}

void	ft_double_input(int count, int i)
{
	char	*str_to_stop;
	char	*buf;

	buf = "string";
	g_var.shell[count].fd_input = open("buf_fo_redirect",
			O_CREAT | O_WRONLY, S_IRWXU);
	str_to_stop = ft_strjoin(g_var.shell[count].arg[i + 1], "");
	while (ft_strcmp(buf, str_to_stop) != 0)
	{
		buf = readline(">");
		if (!ft_strcmp(buf, str_to_stop))
			break ;
		write(g_var.shell[count].fd_input, buf, ft_strlen(buf));
		write(g_var.shell[count].fd_input, "\n", 1);
	}
	close(g_var.shell[count].fd_input);
	g_var.shell[count].fd_input = open("buf_fo_redirect", O_RDONLY, S_IRWXU);
}

void	ft_def_input(int count)
{
	int		i;

	i = 0;
	g_var.shell[count].fd_input = 0;
	while (g_var.shell[count].len_arg > i && (g_var.shell[count].fd_input != -1))
	{
		if (g_var.shell[count].arg[i] && g_var.shell[count].arg[i][0] == '<')
		{
			if (g_var.shell[count].fd_input != 0)
				close (g_var.shell[count].fd_input);
			if (g_var.shell[count].arg[i][1] == '<')
				ft_double_input(count, i);
			else
				g_var.shell[count].fd_input = open(g_var.shell[count].arg[i + 1],
						O_RDONLY);
			if (g_var.shell[count].fd_input == -1)
				printf("minishell: %s: %s\n", g_var.shell[count].arg[i + 1],
					strerror(errno));
			g_var.shell[count].arg[i] = NULL;
			g_var.shell[count].arg[i + 1] = NULL;
		}
		i++;
	}
}

int	ft_check_absolute_path(int count)
{
	char	*path;
	char	*home;
	int		i;

	if (g_var.shell[count].arg[0][0] == '~')
	{
		home = ft_strjoin("/home/", getenv("USER"));
		//	str = ft_strjoin("/Users/", getenv("USER"));
		path = ft_strjoin(home, &g_var.shell[count].arg[0][1]);
		free(home);
		free(g_var.shell[count].arg[0]);
		g_var.shell[count].arg[0] = path;
	}
	i = 0;
	while (g_var.shell[count].arg[0][i])
	{
		if (g_var.shell[count].arg[0][i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	ft_correct_path(int count)
{
	struct stat		check_file;
	char			*add_slash;
	char			*path;
	char			**split_path;
	int				i;

	if (ft_check_absolute_path(count) == 1)
		return ;
	i = 0;
//	path = getenv("PATH");
	path = &g_var.vars[12][5];
//	printf("path = %s\n", path);
	split_path = ft_split(path, ':');
	while (split_path[i] != NULL)
	{
		add_slash = ft_strjoin(split_path[i], "/");
		path = ft_strjoin(add_slash, g_var.shell[count].arg[0]);
		if (stat(path, &check_file) == 0)
			break ;
		i++;
	}
	free(add_slash);
	free(g_var.shell[count].arg[0]);
	g_var.shell[count].arg[0] = path;
}
