#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static char *pred;
	char		buf[BUFFER_SIZE + 1];

	buf[BUFFER_SIZE] = 0;
	buf[0] = 0;
	while (ft_strnchr(buf, '\n') == -1)
	{
		if (!read(fd, buf, BUFFER_SIZE))
			break;
		pred = write_pred(pred, buf);
		if (pred[0] == 0)
			return (-1);
	}
	if (!memory(line, pred))
		return (-1);
	printf("%s\n", pred);
	return (1);
}