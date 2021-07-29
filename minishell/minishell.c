#include "minishell.h"

void line_break(int code)
{
	(void)code;
	write(0, "\b\b  \b\b", 6);
	write(0, "\nminishell: ", 12);
	free(var.str);
	var.str = new_line();
}

void line_slesh(int code)
{
	(void)code;
	write(0, "\b\b  \b\b", 6);
	return ;
}

void	begin_main(void)
{
	signal(SIGINT, &line_break);
	signal(SIGQUIT, &line_slesh);
	var.str = new_line();
	writing_var();
}

int main(void)
{
	char buf[0];
	
	begin_main();
	while (1)
	{
		free(var.str);
		var.str = new_line();
		write(0, "minishell: ", 11);
		while (1)
		{
			if (!read(1, buf, 1))
				exit_but();
			else
			{
				if (buf[0] == '\n')
					break ;
				else
					var.str = my_join(var.str, buf[0]);
			}
		}
		parsing();
	}
	return (0);
}