#include "so_long.h"

char	*stj(char *str, char c)
{
	int		count;
	char	*result;

	count = 0;
	result = malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[count])
	{
		result[count] = str[count];
		count++;
	}
	result[count++] = c;
	result[count] = 0;
	return (result);
}

char	*new_line(void)
{
	char	*str;

	str = malloc(1);
	str[0] = 0;
	return (str);
}

int	custom_gnl(int fd, char **line)
{
	char	buf[2];
	char	*clean;
	int		len_read;

	buf[1] = 0;
	*line = new_line();
	while (1)
	{
		len_read = read(fd, buf, 1);
		if (len_read <= 0 || buf[0] == '\n')
			break ;
		clean = *line;
		*line = stj(*line, buf[0]);
		free(clean);
	}
	if (len_read < 0)
		return (-1);
	if (len_read == 0)
		return (0);
	return (1);
}
