#include "so_long.h"

void	render_cond(int x, int y, int type, t_long *so_long)
{
	if (type == 1)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->imgs.img_wall, x, y);
	if (type == 2)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->imgs.img_coin, x, y);
	if (type == 3)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->imgs.img_hero, x, y);
	if (type == 4)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->imgs.img_exit, x, y);
	if (type == 5 || type == 6)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->imgs.img_enemy, x, y);
}

void	render(t_long *so_long)
{
	int		count;
	char	*str;
	char	*steps;

	steps = ft_itoa(so_long->count_steps);
	str = ft_strjoin("Steps = ", steps);
	count = 0;
	mlx_clear_window(so_long->mlx, so_long->win);
	while (count < so_long->size)
	{
		render_cond(so_long->cords[count][1] * so_long->plus_pxl - so_long->plus_pxl, \
		 so_long->cords[count][2] * so_long->plus_pxl - so_long->plus_pxl, \
		 so_long->cords[count][0], so_long);
		count++;
	}
	mlx_string_put(so_long->mlx, so_long->win, 10, 10, 0xFFFFFF, str);
	so_long->count_steps++;
	free(str);
	free(steps);
}
