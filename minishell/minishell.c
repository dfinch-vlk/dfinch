#include "minishell.h"

void	line_break(int code)
{
	(void)code;
	write(0, "\b\b  \b\b", 6);
	write(0, "\nminishell: ", 12);
	free(g_var.str);
	g_var.str = new_line();
}

void	line_slesh(int code)
{
	(void)code;
	write(0, "\b\b  \b\b", 6);
	if (ft_strlen(g_var.str) > 0)
		exit_but();
	free(g_var.str);
	g_var.str = new_line();
}

void	begin_main(void)
{
	signal(SIGINT, &line_break);
	signal(SIGQUIT, &line_slesh);
	g_var.str = new_line();
	writing_var();
}

int	main(void)
{
	begin_main();
	g_var.str = (char *) NULL;
	while (1)
	{
		if (g_var.str)
		{
			free(g_var.str);
			g_var.str = (char *) NULL;
		}
		g_var.str = readline("minishell: ");
		if (!g_var.str)
			exit_but();
		if (g_var.str && *g_var.str)
			add_history(g_var.str);
		parsing();
	}
	return (0);
}
