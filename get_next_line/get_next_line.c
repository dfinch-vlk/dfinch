#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *pred;
	char		buf[BUFFER_SIZE + 1];

	if (fd == -1)
		return (-1);
	buf[BUFFER_SIZE] = 0;
	buf[0] = 0;
	ft_bzero(buf, BUFFER_SIZE);
	while (ft_strnchr(buf, '\n') == -1)
	{
		if (!read(fd, buf, BUFFER_SIZE))
			break;
		if(!write_pred(&pred, buf))
			return (-1);
	}
	if (!memory(line, &pred))
		return (-1);
	if (ft_strlen(pred) == 0 && !read(fd, buf, BUFFER_SIZE))
		return (0);
	return (1);
}