#include "so_long.h"

void	line_25_1(t_long *so_long, t_counts *counts, char **lines)
{
	if (counts->count_hero != 1 || counts->count_exit != 1 \
		|| so_long->count_coin < 1)
		error_map(lines, so_long);
	check_map_continue(so_long, lines);
}
