#include "minishell.h"

void	ft_run_child(int fd_in, int fd_out, int count, int p[])
{
	if (g_var.shell[count].fd_output == -1 || g_var.shell[count].fd_input == -1)
	{
		exit(EXIT_FAILURE);
		p[0] = close(p[0]) + close(p[1]);
	}
	if (g_var.shell[count].fd_output != 1)
		fd_out = g_var.shell[count].fd_output;
	else
		if ((count + 1) != g_var.len_shell)
			fd_out = p[1];
	if (fd_in != 0)
		dup2(fd_in, 0);
	if (fd_out != 1)
		dup2(fd_out, 1);
	close(p[0]);
	close(p[1]);
	if (fd_out != p[1] && fd_out != 1)
		close(fd_out);
	if (fd_in != p[0] && fd_in != 0)
		close(fd_in);
	if (parsing_command(count) != -1)
		exit(EXIT_SUCCESS);
	ft_correct_path(count);
	command_open(count);
	exit(EXIT_FAILURE);
}

void	ft_do_commands(int count)
{
	pid_t	pid;
	int		p[2];
	int		fd_in;
	int		status;

	fd_in = g_var.shell[0].fd_input;
	while (count < g_var.len_shell)
	{
		pipe(p);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			ft_run_child(fd_in, 1, count, p);
		else
		{
			wait(&status);
			g_var.ret = status >> 8;
			close(p[1]);
			if (fd_in != 0)
				close(fd_in);
			fd_in = p[0];
			count++;
			if (count < g_var.len_shell && g_var.shell[count].fd_input != 0)
				fd_in = g_var.shell[count].fd_input;
		}
	}
}

void	ft_do_one_command(void)
{
	int		buf[2];

	if (g_var.shell[0].fd_output == -1 || g_var.shell[0].fd_input == -1)
		return ;
	if (g_var.shell[0].fd_input != 0)
	{
		buf[0] = dup(STDIN_FILENO);
		dup2(g_var.shell[0].fd_input, STDIN_FILENO);
		close (g_var.shell[0].fd_input);
	}
	if (g_var.shell[0].fd_output != 1)
	{
		buf[1] = dup(STDOUT_FILENO);
		dup2(g_var.shell[0].fd_output, STDOUT_FILENO);
		close(g_var.shell[0].fd_output);
	}
	parsing_command(0);
	if (g_var.shell[0].fd_input != 0)
		dup2(buf[0], STDIN_FILENO);
	if (g_var.shell[0].fd_input != 0)
		close(buf[0]);
	if (g_var.shell[0].fd_output != 1)
		dup2(buf[1], STDOUT_FILENO);
	if (g_var.shell[0].fd_output != 1)
		close(buf[1]);
}

void	ft_correct_order(int count)
{
	int		i;
	int		n;

	i = 0;
	while (g_var.shell[count].len_arg > i)
	{
		if (g_var.shell[count].arg[i] == NULL)
		{
			n = i + 1;
			while (n < g_var.shell[count].len_arg
				&& g_var.shell[count].arg[n] == NULL)
				n++;
			if (n == g_var.shell[count].len_arg)
				break ;
			g_var.shell[count].arg[i] = g_var.shell[count].arg[n];
			g_var.shell[count].arg[n] = NULL;
		}
		i++;
	}
}

void	ft_open_pipe(void)
{
	int		count;

	count = 0;
	while (count < g_var.len_shell)
	{
		ft_def_input(count);
		ft_def_output(count);
		count++;
	}
	ft_correct_order(0);
	if (g_var.len_shell == 1 && ft_check_builtin() == 1)
		ft_do_one_command();
	else
		ft_do_commands(0);
}
