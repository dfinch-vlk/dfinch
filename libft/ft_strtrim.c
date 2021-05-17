#include "libft.h"

char	*ft_strtrim_dop(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1 + start);
	if (end)
		while (s1[end + start - 1] != 0 && \
				ft_strchr(set, s1[end + start - 1]) != 0)
			end--;
	trim = malloc(sizeof(char) * end + 1);
	if (trim == NULL)
		return (NULL);
	ft_strtrim_dop(trim, s1 + start, end);
	trim[end] = '\0';
	return (trim);
}
