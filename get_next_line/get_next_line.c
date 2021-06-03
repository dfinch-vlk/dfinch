#include "get_next_line.h"

int	get_next_line_return(char **buf, int len_buf, char *remains)
{
	free(*buf);
	if (!len_buf && !ft_strlen(remains))
		return (0);
	return (1);
}

void	get_next_line_if(char *pn, char **remains, char **line, int flag)
{
	char	*clear;

	*pn = 0;
	if (flag == 1)
		*line = ft_strdup(*remains);
	clear = *remains;
	*remains = ft_strdup(++pn);
	free(clear);
}

char	*get_next_line_dop(char **line, char **remains)
{
	char	*pn;

	pn = NULL;
	if (remains[0])
	{
		pn = ft_strchr(*remains, '\n');
		if (pn)
			get_next_line_if(pn, remains, line, 1);
		else
		{
			*line = *remains;
			*remains = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (pn);
}

int	get_next_line_begin(int fd, int *len_buf, char **line, char **buf)
{
	*len_buf = 1;
	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!*buf)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*remains;
	char		*buf;
	char		*pn;
	char		*clear;
	int			len_buf;

	if (get_next_line_begin(fd, &len_buf, line, &buf) < 0)
		return (-1);
	pn = get_next_line_dop(line, &remains);
	while (!pn)
	{
		len_buf = read(fd, buf, BUFFER_SIZE);
		if (len_buf <= 0)
			break ;
		buf[len_buf] = 0;
		pn = ft_strchr(buf, '\n');
		if (pn)
			get_next_line_if(pn, &remains, line, 0);
		clear = *line;
		*line = ft_strjoin(*line, buf);
		if (!*line || len_buf < 0)
			return (-1);
		free(clear);
	}
	return (get_next_line_return(&buf, len_buf, remains));
}
