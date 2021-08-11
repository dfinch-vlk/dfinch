#include "minishell.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		count;

	count = 0;
	if (!s)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	while (s[count])
	{
		str[count] = s[count];
		count++;
	}
	str[count] = 0;
	return (str);
}
