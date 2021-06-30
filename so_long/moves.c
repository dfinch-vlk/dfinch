#include "so_long.h"

void	move_right(t_long *so_long)
{
	if (stop_this_wall(so_long->cords[so_long->count_hero][1] + 1, \
		so_long->cords[so_long->count_hero][2], so_long))
		so_long->cords[so_long->count_hero][1] += 1;
	enemy_g(so_long);
	enemy_v(so_long);
	this_coin(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
	this_exit(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
}

void	move_left(t_long *so_long)
{
	if (stop_this_wall(so_long->cords[so_long->count_hero][1] - 1, \
		so_long->cords[so_long->count_hero][2], so_long))
		so_long->cords[so_long->count_hero][1] -= 1;
	enemy_g(so_long);
	enemy_v(so_long);
	this_coin(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
	this_exit(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
}

void	move_up(t_long *so_long)
{
	if (stop_this_wall(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2] + 1, so_long))
		so_long->cords[so_long->count_hero][2] += 1;
	enemy_g(so_long);
	enemy_v(so_long);
	this_coin(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
	this_exit(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
}

void	move_down(t_long *so_long)
{
	if (stop_this_wall(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2] - 1, so_long))
		so_long->cords[so_long->count_hero][2] -= 1;
	enemy_g(so_long);
	enemy_v(so_long);
	this_coin(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
	this_exit(so_long->cords[so_long->count_hero][1], \
		so_long->cords[so_long->count_hero][2], so_long);
}
