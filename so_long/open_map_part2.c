#include "so_long.h"

int	write_condition(char c)
{
	if (c == '1')
		return (1);
	if (c == 'C')
		return (2);
	if (c == 'P')
		return (3);
	if (c == 'E')
		return (4);
	if (c == 'V')
		return (5);
	if (c == 'G')
		return (6);
	else
		return (0);
}

void	enemy_cords(t_long *so_long, int type, int count)
{
	free(so_long->cords[count]);
	so_long->cords[count] = malloc(sizeof(int) * 4);
	so_long->cords[count][0] = type;
	so_long->cords[count][3] = 1;
}

void	write_coordinates(t_long *so_long, char **lines)
{
	int	count1;
	int	count2;
	int	count3;

	count1 = (count2 = (count3 = 0));
	so_long->width = ft_strlen(lines[0]);
	while (count2 < so_long->height)
	{
		count1 = 0;
		while (lines[count2][count1])
		{
			so_long->cords[count3][0] = write_condition(lines[count2][count1]);
			if (so_long->cords[count3][0] == 3)
				so_long->count_hero = count3;
			if (so_long->cords[count3][0] == 5 || \
				so_long->cords[count3][0] == 6)
				enemy_cords(so_long, so_long->cords[count3][0], count3);
			so_long->cords[count3][1] = count1 + 1;
			so_long->cords[count3++][2] = count2 + 1;
			count1++;
		}
		free(lines[count2]);
		count2++;
	}
	free(lines);
}

void	check_map_continue(t_long *so_long, char **lines)
{
	int	count;

	count = 0;
	while (count + 1 < so_long->height)
	{
		if (ft_strlen(lines[count]) != ft_strlen(lines[count + 1]))
			error_map(lines, so_long);
		count++;
	}
	count = 0;
	so_long->cords = malloc(sizeof(int *) * so_long->size);
	while (count < so_long->size)
		so_long->cords[count++] = malloc(sizeof(int) * 3);
	write_coordinates(so_long, lines);
}
