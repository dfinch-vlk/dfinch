#include "so_long.h"

int	testing_move(int keycode, t_long *so_long)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 2)
		move_right(so_long);
	if (keycode == 1)
		move_up(so_long);
	if (keycode == 13)
		move_down(so_long);
	if (keycode == 0)
		move_left(so_long);
	render(so_long);
	return (1);
}

void	create_sprite(t_long *so_long)
{
	int	size;

	so_long->imgs.img_hero = mlx_png_file_to_image \
	(so_long->mlx, "./img/hero.png", &size, &size);
	so_long->imgs.img_coin = mlx_png_file_to_image \
	(so_long->mlx, "./img/coin.png", &size, &size);
	so_long->imgs.img_wall = mlx_png_file_to_image \
	(so_long->mlx, "./img/wall.png", &size, &size);
	so_long->imgs.img_exit = mlx_png_file_to_image \
	(so_long->mlx, "./img/exit.png", &size, &size);
	so_long->imgs.img_enemy = mlx_png_file_to_image \
	(so_long->mlx, "./img/enemy.png", &size, &size);
}

int	main(int argc, char const *argv[])
{
	t_long	so_long;

	if (argc != 2)
		error_arg();
	open_map(&so_long, argv[1]);
	so_long.plus_pxl = 50;
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx, so_long.width * so_long.plus_pxl, \
	so_long.height * so_long.plus_pxl, "so_long");
	so_long.coin = 0;
	so_long.count_steps = 0;
	create_sprite(&so_long);
	render(&so_long);
	mlx_hook(so_long.win, 2, 1L << 0, testing_move, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
