#include "so_long.h"

void	check_expansion(const char *file)
{
	int	count;

	count = 1;
	while (file[count])
	{
		if (file[count] == '.')
		{
			if (ft_strcmp(&file[count], ".ber") != 0)
				error_map(NULL, NULL);
		}
		count++;
	}
}

void	check_map_condition(t_long *so_long, char c, \
	char **lines, t_counts *counts)
{
	if (c == 'C')
		so_long->count_coin++;
	if (c == 'E')
		counts->count_exit++;
	if (c == 'P')
		counts->count_hero++;
	if (c != 'V' && c != 'P' && c != 'G' && c != \
		       	'C' && c != 'E' && c != '1' && c != '0')
		error_map(lines, so_long);
}

void	check_map(t_long *so_long, char **lines)
{
	t_counts	counts;
	int			count1;
	int			count2;

	count2 = (counts.count_hero = (so_long->count_coin \
		= (so_long->size = (counts.count_exit = 0))));
	while (count2 < so_long->height)
	{
		count1 = 0;
		so_long->size += ft_strlen(lines[count2]);
		while (lines[count2][count1])
		{
			if ((count2 == 0 || count2 == so_long->height - 1) \
				&& lines[count2][count1] != '1')
				error_map(lines, so_long);
			if (lines[count2][0] != '1' || \
				lines[count2][ft_strlen(lines[count2]) - 1] != '1')
				error_map(lines, so_long);
			check_map_condition(so_long, lines[count2][count1], lines, &counts);
			count1++;
		}
		count2++;
	}
	line_25_1(so_long, &counts, lines);
}

int	count_line_func(int fd)
{
	char	*buf;
	int		result;

	result = 0;
	buf = malloc(sizeof(char) * 2);
	if (!buf)
		error_map(NULL, NULL);
	buf[1] = 0;
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			result++;
	}
	free(buf);
	return (result);
}

void	open_map(t_long *so_long, const char *file)
{
	int		fd;
	char	**lines;
	int		count;
	char	*line;

	check_expansion(file);
	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_map(NULL, NULL);
	so_long->height = count_line_func(fd);
	if (so_long->height < 3)
		error_map(NULL, NULL);
	lines = malloc(sizeof(char *) * so_long->height);
	if (!lines)
		error_map(NULL, NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	while (custom_gnl(fd, &line))
		lines[count++] = line;
	check_map(so_long, lines);
}
