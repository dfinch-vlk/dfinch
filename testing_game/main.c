#include "mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;
int x = 1;
int y = 1;

int	close(int keycode, t_vars *vars)
{
	int size;

	if (keycode == 12)
		exit(1);
	else if (keycode == 2)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->img = mlx_png_file_to_image(vars->mlx, "./main_hero.png", &size, &size);
		x += 100;
		if (x > 1820)
			x = 1820;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
	}
	else if (keycode == 1)
	{	
		y += 100;
		if (y > 1080)
			y = 1080;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
	}
	else if (keycode == 13)
	{
		y -= 100;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);	
	}
	else if (keycode == 0)
	{
		x -= 100;
		if (x < 0)
			x = 1;
		mlx_destroy_image(vars->mlx, vars->img);
		vars->img = mlx_png_file_to_image(vars->mlx, "./main_hero2.png", &size, &size);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);	
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	void *img;
	int size;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img = mlx_png_file_to_image(vars.mlx, "./main_hero.png", &size, &size);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 100, 100);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}