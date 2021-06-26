#include "so_long.h"

int main(int argc, char const *argv[])
{
	t_long so_long;

	if (argc != 2)
		error_arg();
	open_map(&so_long, argv[1]);
	return 0;
}