#include "minishell.h"

int count_shell()
{
	int count;
	int result;
	char c;

	count = (result = 0);
	while (var.str[count])
	{
		if (var.str[count] == 39 || var.str[count] == 34)
		{
			c = var.str[count++];
			while (var.str[count] != c && var.str[count])
				count++;
		}
		if (var.str[count] == ';')
		{
			count++;
			while (var.str[count] == ' ' && var.str[count])
				count++;
			if (var.str[count] == 0)
				break ;
			result++;
		}
		count++;
	}
	return (result + 1);
}

int check_parse_error()
{
	int count;

	count = 0;
	while (var.str[count + 1])
	{
		if (var.str[count] == ';' && var.str[count + 1] == ';')
		{
			var.ret = 258;
			return (printf("shell: syntax error near unexpected token `;;'\n"));
		}
		if (var.str[count] == ';')
		{
			count++;
			while (var.str[count] == ' ' && var.str[count])
				count++;
			if (var.str[count] == ';')
			{
				var.ret = 258;
				return (printf("shell: syntax error near unexpected token `;'\n"));
			}

		}
		count++;
	}
	return (0);
}

void freendom()
{
	int count1;
	int count2;

	count2 = 0;
	while (count2 < var.len_shell)
	{
		count1 = 0;
		while (count1 < var.shell[count2].len_arg)
		{
			free(var.shell[count2].arg[count1]);
			count1++;
		}
		free(var.shell[count2].arg);
		count2++;
	}
	free(var.shell);
}

void parsing(void)
{
	int count;

	count = 0;
	if (check_parse_error())
		return ;
	if (!(ft_strlen(var.str) - count_char(var.str, ' ')))
		return ;
	var.shell = malloc(sizeof(t_shell) * (var.len_shell = count_shell()));
	while (count < var.len_shell)
	 	parsing_main(count++);
	count = 0;
	while (count < var.len_shell)
		parsing_command(count++);
	freendom();
}