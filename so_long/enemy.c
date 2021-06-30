#include "so_long.h"

void	enemy_g_dop(t_long *so_long, int count)
{
	if (so_long->cords[count][3] == 1)
	{
		if (!stop_this_wall(so_long->cords[count][1] + 1, \
			so_long->cords[count][2], so_long))
			so_long->cords[count][3] = 0;
		else
			so_long->cords[count][1] += 1;
	}
	else
	{
		if (!stop_this_wall(so_long->cords[count][1] - 1, \
			so_long->cords[count][2], so_long))
			so_long->cords[count][3] = 1;
		else
			so_long->cords[count][1] -= 1;
	}
}

void	enemy_g(t_long *so_long)
{
	int	count;

	count = 0;
	while (count < so_long->size)
	{
		if (so_long->cords[count][0] == 6)
			enemy_g_dop(so_long, count);
		count++;
	}
}

void	enemy_v_dop(t_long *so_long, int count)
{
	if (so_long->cords[count][3] == 1)
	{
		if (!stop_this_wall(so_long->cords[count][1], \
			so_long->cords[count][2] + 1, so_long))
			so_long->cords[count][3] = 0;
		else
			so_long->cords[count][2] += 1;
	}
	else
	{
		if (!stop_this_wall(so_long->cords[count][1], \
			so_long->cords[count][2] - 1, so_long))
			so_long->cords[count][3] = 1;
		else
			so_long->cords[count][2] -= 1;
	}
}

void	enemy_v(t_long *so_long)
{
	int	count;

	count = 0;
	while (count < so_long->size)
	{
		if (so_long->cords[count][0] == 5)
			enemy_v_dop(so_long, count);
		count++;
	}
}
