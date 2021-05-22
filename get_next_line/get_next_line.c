#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int countStr(char *str, int countLine, int flag)
{
	int line;
	int count1;
	int count2;

	line = 0;
	count1 = 0;
	count2 = 0;
	if (countLine == 0 && flag == 1)
		return (countLine);
	while (str[count1])
	{
		if (str[count1] == '\n')
			line++;
		if (countLine - line == 1)
			count2++;
		if (line == countLine && flag == 2)
			return (count2);
		if (line == countLine && flag == 3)
			return (count1);
		count1++;
	}
	if (line == countLine && flag == 2)
			return (count2);
	if (line == countLine && flag == 3)
			return (count1);
	return (line);
}

int	write_main(char *str, char **line, int countLine, int flag)
{
	int count1;
	int	count2;

	count1 = 0;
	if (flag == 1)
	{
		if (countLine == 0)
			count2 = 0;
		else
			count2 = countStr(str, countLine, 3) + 1;
		while (str[count2] != 0 && str[count2] != '\n')
			line[0][count1++] = str[count2++];
		line[0][count1] = 0;
	}
	if (flag == 2)
	{
		if (countLine == 0)
			return (0);
		count1 = 0;
		while(str[count1])
			count1++;
		return (count1);
	}
	return (1);
}

void	write_dop(char *new, char *pred, char *buf, int countLine)
{
	int count1;
	int count2;

	count1 = 0;
	count2 = 0;
	if (countLine != 0)
	{
		while (pred[count1])
		{
			new[count1] = pred[count1];
			count1++;
		}
	}
	while (buf[count2])
		new[count1++] = buf[count2++];
	new[count1] = 0;
}

int	memory(char **line, char **results, char *buf, int countLine)
{
	int second;

	if (countLine % 2 == 1)
		second = 0;
	else
		second = 1;
	results[countLine % 2] = malloc(sizeof(char) * (write_main(results[second], 0, countLine, 2) + write_main(buf, 0, 1, 2) + 1));
	if (!results[countLine % 2])
		return (-1);
	write_dop(results[countLine % 2], results[second], buf, countLine);
	free(results[second]);
	line[0] = malloc(sizeof(char) * countStr(results[countLine % 2], countLine, 2));
	if (!line)
		return (-1);
	write_main(results[countLine % 2], line, countLine, 1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static int countLine;
	static char *results[2];
	char		buf[BUFFER_SIZE + 1];

	buf[BUFFER_SIZE] = 0;
	read(fd, buf, BUFFER_SIZE);
	if (memory(line, results, buf, countLine) == -1)
		return (-1);
	if (countLine == 11)
		printf("%s\n", results[countLine % 2]);
	countLine++;
	return (1);
}

int	main()
{
	int fd = open("text", O_RDONLY);
	char	*line;
	for (int i = 0; i < 12; ++i)
	{
		get_next_line(fd, &line);
		//printf("%s\n", line);
	}
}