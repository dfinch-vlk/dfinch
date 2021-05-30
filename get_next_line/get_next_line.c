#include "get_next_line.h"

int	get_next_line_return(char *remains, int len_buf)
{
	if (len_buf < 0)
		return (-1);
	if (!len_buf && !ft_strlen(remains))
		return (0);
	return (1);
}

int	get_next_line_begin(char **buf, char **pn, char **line, char **remains)
{
	*buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	*pn = check_remains(remains, line);
	return (1);
}

char	*check_remains(char **remains, char **line)
{
	char	*pn;

	pn = NULL;
	if (*remains)
	{
		if (ft_strchr(*remains, '\n'))
		{
			pn = ft_strchr(*remains, '\n');
			*pn = 0;
			*line = *remains;
			*remains = ft_strdup(++pn);
		}
		else
		{
			*line = *remains;
			*remains = ft_strdup("");
		}
	}
	else
		*remains = ft_strdup("");
	return (pn);
}

int	get_next_line(int fd, char **line)
{
	static char	*remains;
	char		*buf;
	char		*pn;
	int			len_buf;
	char		*clear;

	if (get_next_line_begin(&buf, &pn, line, &remains) < 0)
		return (-1);
	while (!pn)
	{
		len_buf = read(fd, buf, BUFFER_SIZE);
		if (len_buf <= 0)
			break ;
		pn = ft_strchr(buf, '\n');
		if (pn)
		{
			*pn = 0;
			remains = ft_strdup(++pn);
		}
		clear = *line;
		*line = ft_strjoin(*line, buf);
		if (!clear)
			free(clear);
	}
	return (get_next_line_return(remains, len_buf));
}
