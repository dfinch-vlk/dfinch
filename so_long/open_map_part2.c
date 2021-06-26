#include "so_long.h"

int write_coordinates_condition(char c)
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

void write_coordinates(t_long *so_long, char **lines)
{
	int count1;
	int count2;
	int count3;

	count1 = (count2 = (count3 = 0));
	so_long->width = ft_strlen(lines[0]);
	while (count2 < so_long->height)
	{
		count1 = 0;
		while (lines[count2][count1])
		{
			so_long->cords[count3][0] = write_coordinates_condition(lines[count2][count1]);
			so_long->cords[count3][1] = count1 + 1;
			so_long->cords[count3][2] = count2 + 1;
			count1++;
			count3++;
		}
		count2++;
	}
	free(lines);
	write(1, "The map was successfully read\n", 31);
}

void	check_map_continue(t_long *so_long, char **lines)
{
	int count;

	count = 0;
	while (count + 1 < so_long->height)
	{
		if (ft_strlen(lines[count]) != ft_strlen(lines[count + 1]))
			error_map(lines);
		count++;
	}
	count = 0;
	so_long->cords = malloc(sizeof(int *) * so_long->size);
	while (count < so_long->size)
		so_long->cords[count++] = malloc(sizeof(int) * 3);
	write_coordinates(so_long, lines);
}