#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

int ft_strlen(char *str)
{
	int count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *s1)
{
	int		count;
	char	*result;

	count = -1;
	result = malloc(ft_strlen(s1) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[++count])
		result[count] = s1[count];
	result[count] = '\0';
	return (result);
}

void	writing(char **line, char *pred, char *ost)
{
	int count1;
	int count2;

	count1 = 0;
	count2 = 0;
	while (pred[count1] != 0 && pred[count1] != '\n')
	{
		line[0][count1] = pred[count1];
		count1++;
	}
	line[0][count1] = 0;
	while (pred[count1] != 0)
		ost[count2++] = pred[count1++];
	ost[count2] = 0;
	free(pred);
	pred = ft_strdup(ost);
	free(ost);
}

int	ft_strnchr(char *str, char c)
{
	int count;

	count = 0;
	while (str[count] != 0)
		if (str[count++] == c)
			return (--count);
	return (-1);
}

char	*write_pred(char *pred, char *buf)
{
	char	*rew;
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	rew = malloc(sizeof(char) * (ft_strlen(pred) + ft_strlen(buf) + 1));
	if (!rew)
		return(ft_strdup(""));
	if (ft_strlen(pred) != 0)
	{
		while (pred[count1])
		{
			rew[count1] = pred[count1];
			count1++;
		}
	}
	while (buf[count2])
		rew[count1++] = buf[count2++];
	rew[count1] = 0;
	return (rew);
}
int		memory(char **line, char *pred)
{
	char *ost;

	line[0]  = malloc(sizeof(char) * ft_strnchr(pred, '\n') + 2);
	if (!line[0])
		return (-1);
	ost = malloc(sizeof(char) * (ft_strlen(pred) - ft_strnchr(pred, '\n') + 1));
	if (!ost)
		return(-1);
	writing(line, pred, ost);
	return (1);
}

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
	return (1);
}

int main()
{
	int fd = open("text", O_RDONLY);
	char *line;

	for (int i = 0; i < 3; i++)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
	}
	return 0;
}