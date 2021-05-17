#include "libft.h"

int	ft_cr(const char *str, char c)
{
	int	count;

	count = 0;
	if (*str != c && *str)
	{
		str++;
		count++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				count++;
		}
		str++;
	}
	return (count);
}

int	ft_cl(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

void	*is_free(char **spt)
{
	int		i;

	i = 0;
	while (spt[i])
	{
		free(spt[i++]);
	}
	free(spt);
	return (NULL);
}

int	ft_split_dop(const char *s, char **spt, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			spt[j] = (char *)malloc(sizeof(char) * (ft_cl(s, c) + 1));
			if (spt[j] == NULL)
				return (0);
			while (*s && *s != c)
				spt[j][i++] = (char)*s++;
			spt[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	spt[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**spt;

	if (s == NULL)
		return (NULL);
	spt = (char **)malloc(sizeof(char *) * (ft_cr(s, c) + 1));
	if (spt == NULL)
		return (NULL);
	if (ft_split_dop(s, spt, c) == 0)
		return (is_free(spt));
	return (spt);
}
