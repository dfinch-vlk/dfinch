#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_img
{
	void	*img_hero;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;
	void	*img_enemy;
}	t_img;

typedef struct s_long
{
	t_img	imgs;
	int		**cords;
	int		size;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		count_coin;
	int		coin;
	int		plus_pxl;
	int		count_steps;
	int		count_hero;
}	t_long;

typedef struct s_counts
{
	int	count_hero;
	int	count_exit;
}	t_counts;

void	error_map(char **lines);
void	error_arg(void);
void	open_map(t_long *so_long, const char *file);
int		custom_gnl(int fd, char **line);
int		count_line_func(int fd);
void	check_map(t_long *so_long, char **lines);
void	check_map_condition(t_long *so_long, char c, \
	char **lines, t_counts *counts);
void	check_map_continue(t_long *so_long, char **lines);
void	write_coordinates(t_long *so_long, char **lines);
int		write_coordinates_condition(char c);
void	check_expansion(const char *file);
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	render(t_long *so_long);
void	move_right(t_long *so_long);
void	move_left(t_long *so_long);
void	move_up(t_long *so_long);
void	move_down(t_long *so_long);
void	this_coin(int x, int y, t_long *so_long);
void	this_exit(int x, int y, t_long *so_long);
int		stop_this_wall(int x, int y, t_long *so_long);
void	enemy_g(t_long *so_long);
void	enemy_v(t_long *so_long);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);
void	line_25_1(t_long *so_long, t_counts *counts, char **lines);

#endif