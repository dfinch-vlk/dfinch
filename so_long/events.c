#include "so_long.h"

int	stop_this_wall(int x, int y, t_long *so_long)
{
	int	count;

	count = 0;
	while (count < so_long->size)
	{
		if (so_long->cords[count][0] == 1 && so_long->cords[count][1] == x \
			&& so_long->cords[count][2] == y)
			return (0);
		count++;
	}
	return (1);
}

void	this_coin(int x, int y, t_long *so_long)
{
	int	count;

	count = 0;
	while (count < so_long->size)
	{
		if (so_long->cords[count][0] == 2 && so_long->cords[count][1] == x \
			&& so_long->cords[count][2] == y)
		{
			so_long->coin++;
			so_long->cords[count][0] = 0;
			return ;
		}
		count++;
	}
}

void	this_exit(int x, int y, t_long *so_long)
{
	int	count;

	count = 0;
	while (count < so_long->size)
	{
		if (so_long->cords[count][0] == 4 && so_long->cords[count][1] == x \
			&& so_long->cords[count][2] == y)
		{
			if (so_long->coin == so_long->count_coin)
				exit_free(so_long);
			return ;
		}
		if ((so_long->cords[count][0] == 5 || so_long->cords[count][0] == 6) && \
			so_long->cords[count][1] == x && so_long->cords[count][2] == y)
			exit_free(so_long);
		count++;
	}	
}
