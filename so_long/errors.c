#include "so_long.h"

void	error_map(char **lines)
{
	if (lines != NULL)
		free(lines);
	write(1, "Error: Invalid map\n", 19);
	exit(-1);
}

void	error_arg(void)
{
	write(1, "./so_long [map.ber]\n", 20);
	exit(-1);
}
