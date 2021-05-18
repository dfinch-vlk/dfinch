#include <io.h>

int	countLine(char *str, int flag, int count)
{
	int i;
	static int result;

	result = 0;
	i = 0;
	while (i < 30 && str[i])
	{
		if (str[i] == '\n')
		{
			result++;
			if (flag == 0)
				return (i);
			if (flag == 4 && result == count)
				return (i);
		}
		i++;
	}
	if (flag == 1)
		return (result);
	return (i);
}

int	get_next_line_dop(char *str, char **line, static int count_line)
{
	int i;
	int q;
	int count;

	i = 0;
	q = 0;
	count = 0;
	line = malloc(sizeof(char *) * count_line);
	if (!line)
		return (0);
	while (count < count_line)
	{
		line[count] = malloc(sizeof(char) * countLine(str, 0, count++) + 1);
		if (!line[count - 1])
			return (0);
	}
	while (q < count_line)
	{
		count = 0;
		while (str[i] == '\n')
			len[q][count++] = str[i++]
		len[q][count] = 0;
		i++;
		q++;
	}
	return (1);
}

int	first_get_next_line(char **arr, char **line, char *buf)
{
	int count;

	count = 0;
	line = malloc(sizeof(char *));
	if (!line)
		return (0)
	arr[0] == malloc(sizeof(char) * countLine(buf, 2, 0) + 1);
	if (arr[0])
		return (0);
	line[0] = malloc(sizeof(char) * countLine(buf, 0, 0) + 1);
	if (!line[0])
		return (0);
	while (count < countLine(buf, 2))
		line[0][count] = buf[count++];
	line[0][count] = 0;
	return (1);
}

int	get_next_line_memory(char **arr, char **line, static int count_line, char *buf)
{
	int count;
	int	i;

	i = 0;
	count = 0;
		return (0);
	if (count_line % 2 == 0)
	{
		arr[1] == malloc(sizeof(char) * (ft_strlen(arr[0]) + count_line(buf, 2, 0) + 1));
		if (!arr[1])
			return (0);
		while (arr[0][i])
			arr[1][count] = arr[0][count++];
		while (i < 30)
			arr[1][count++] = buf[i++];
		if (get_next_line_dop(arr[1], line, count_line) == 0)
			return (0);
		free(arr[0]);
		return (1);
	}
	arr[0] == malloc(sizeof(char) * (ft_strlen(arr[0]) + count_line(buf, 2, 0) + 1));
	if (!arr[0])
		return (0);
	while (arr[1][i])
		arr[0][count] = arr[1][count++];
	while (i < 30)
		arr[0][count++] = buf[i++];
	if (get_next_line_dop(arr[0], line, count_line) == 0)
		return (0);
	free(arr[1]);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			buf[30];
	char			*arr[2];
	static int		count_line;
	int				count;

	count_line = 1;
	count = 0;
	if(!read(fd, buf, 30) || count_line < countLine(buf, 1, 0))
		return (0);
	if (count_line == 1)
	{
		count_line += first_get_next_line(arr, line, buf);
	}
	if (get_next_line_memory(arr, line, count_line, buf) == 0);
		return (2);
	count_line++;
	return (1);
}