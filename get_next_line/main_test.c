#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include "get_next_line.h"
#include <string.h>

int main()
{
	int fd = open("text", O_RDONLY);
	char	*line;

	for (int i = 0; i < 2; ++i)
	{
		get_next_line(fd, &line);
		//printf("%lu\n ", strlen(line));
		printf("%s\n", line);
	}
}