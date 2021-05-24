#include "get_next_line.h"
#include <stdio.h>

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

char  *writing(char **line, char *pred, char *ost)
{
	int count1;
	int count2;

	count1 = 0;
	count2 = 0;
	if (pred[0] != '\n')
	{
		while (pred[count1] != 0 && pred[count1] != '\n')
		{
			line[0][count1] = pred[count1];
			count1++;
		}
		line[0][count1] = 0;
	}
	count1++;
	if (pred[0] == '\n')
	{
		free(line[0]);
		line[0] = ft_strdup("\n");
		count1++;
	}
	while (pred[count1] != 0)
		ost[count2++] = pred[count1++];
	ost[count2] = 0;
	free(pred);
	pred = ft_strdup(ost);
	free(ost);
	return (pred);
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
		return(NULL);
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

	if (ft_strnchr(pred, '\n') == -1)
		line[0]  = malloc(sizeof(char) * ft_strnchr(pred, 0) + 1);
	else
		line[0]  = malloc(sizeof(char) * ft_strnchr(pred, '\n') + 1);
	if (!line[0])
		return (-1);
	ost = malloc(sizeof(char) * (ft_strlen(pred) - ft_strnchr(pred, '\n') + 1));
	if (!ost)
		return(-1);
	pred = writing(line, pred, ost);
	return (1);
}