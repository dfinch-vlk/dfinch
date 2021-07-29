#include "minishell.h"

void	exit_but(void)
{
	if (!ft_strlen(var.str))
	{
		printf("\r                 ");
		printf("\rminishell: exit\n");
		free(var.str);
		exit(0);
	}
	write(0, "  \b\b", 4);
}

int miss_space(void)
{
	int count;

	count = 0;
	while (var.str[count] == ' ')
		count++;
	return (count);
}

int clrscr(void) 
{ 
	printf("\033[2J");
	printf("\033[0;0f");
	printf("\n");	
	return (0);
}
