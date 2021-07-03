#include "so_long.h"

void	error_map(char **lines, t_long *so_long)
{
	int	count;

	count = 0;
	if (lines != NULL)
	{
		while (count < so_long->height)
		{
			free(lines[count]);
			count++;
		}
		free(lines);
	}
	write(1, "Error: Invalid map\n", 19);
	exit(-1);
}

void	error_arg(void)
{
	write(1, "./so_long [map.ber]\n", 20);
	exit(-1);
}

void	exit_free(t_long *so_long)
{
	int	count;

	count = 0;
	while (count < so_long->size)
	{
		free(so_long->cords[count]);
		count++;
	}
	free(so_long->cords);
	exit (1);
}
