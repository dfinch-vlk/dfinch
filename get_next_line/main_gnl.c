#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int get_next_line(int fd, char **line);
/*
int main()
{
	int fd = open("text", O_RDONLY);
	char 	*line;
	int check = 1;

	for (int i = 0; check != 0; i++)
	{
		printf("%i - ", (check =  get_next_line(fd, &line)));
		printf("%s\n", line);
	}
}*/

int main(int argc, char const *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	int check = 1;
	char *line;

	while (check > 0)
	{
		check = get_next_line(fd, &line);
		printf("%i --> %s\n", check, line);
	}
	return 0;
}