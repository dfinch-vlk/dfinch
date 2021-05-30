#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	while (i < (count * size))
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		count;
	int		i;

	count = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[count])
	{
		result[count] = s1[count];
		count++;
	}
	i = 0;
	while (s2[i])
		result[count++] = s2[i++];
	result[count] = 0;
	return (result);
}