#include <stdlib.h>

int        ft_strlen(char *str)
{
    int    count = 0;

    while (str[count++]);
    return (--count);
}

char    *ft_strdup(char *str)
{
    char    *result = malloc(ft_strlen(str) + 1);
    int        count = -1;

    while (str[++count])
        result[count] = str[count];
    result[count] = '\0';
    return (result);
}

int		ft_tolower(int symbol)
{
	if (symbol >= 65 && symbol <= 90)
		return (symbol + 32);
	return (symbol);
}

int		ft_toupper(int symbol)
{
	if (symbol >= 97 && symbol <= 122)
		return (symbol - 32);
	return (symbol);
}

char	*ft_strchr(const char *string, int symbol)
{
	char	result[--ft_strlen];
	int		count = 0;

	while (string[++count + 1] != symbol);
	for (int i = 0; string[count++]; i++)
		result[i] = string[count];
	return (result);
}