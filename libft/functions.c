#include <stdlib.h>

int        ft_isprint(int symbol)
{
    return (32 <= symbol && symbol <= 126 ? 16384 : 0);
}

int 	ft_isdigit(int symbol)
{
	return (48 <= symbol && symbol <= 57);
}

int     ft_isalnum(int symbol)
{
    if (48 <= symbol && symbol <= 57)
        return (8);
    return ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122) ? 8 : 0);
}

int     ft_isascii(int symbol)
{
    return (symbol >= 0 && symbol <= 127);
}

int     ft_isalpha(int symbol)
{
    return ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122) ? 1024 : 0);
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

int     ft_strlcpy(char *result, const char *str, int len)
{
    int count = 0;

    while (count < len || str[count])
    {
      result[count] = str[count];
      count++;
    }
    result[count] = '\0';
    while (str[count++]);
    return (--count);
}

int     ft_strlcat(char *result, const char *str, int len)
{
    int count = 0;

    while (result[count++]);
    count--;
    for (int i = 0; i < len || str[i]; i++)
        result[count++] = str[i];
    result[count] = '\0';
    return (count);
}
char	*ft_strrchr(char *str, int symbol)
{
	for (int i = 0; str[i]; i++)
		if (str[i] == symbol)
			return (&str[i]);
	return (0);
}

int    ft_strncmp(const char *str1, const char *str2, int len)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
    for (int i = 0; i < len || str1[i]; i++)
        if (str1[i] != str2[i])
            return (str1[i] > str2[i] ? 1 : -1);
    return (0);
}

char	*ft_strchr(char *str, int symbol)
{
  char *result = ft_strdup(str);
  int count[2] = {0, 0};

  while (str[count[0]] != symbol)
    count[0]++;
  while (str[count[0]])
    result[count[1]++] = str[count[0]++];
  result[count[1]] = '\0';
  return (result);
}

int        ft_strlen(char *str)
{
    int    count = 0;

    while (str[count++]);
    return (--count);
}

char    *ft_strdup(char *str)
{
    char    *result = malloc(ft_strlen(str) + 1);
    int		count = -1;

    while (str[++count])
        result[count] = str[count];
    result[count] = '\0';
    return (result);
}

void    *ft_memset(char *str, int symbol, int len)
{
    for (int i = 0; i < len; i++)
        str[i] = symbol;
}

char	*ft_memchr(char *str, int symbol, int len)
{
	for (int i = 0; i < len; i++)
		if (str[i] == symbol)
			return (&str[i]);
	return (0);
}

int 	ft_memcmp(char *str1, char *str2, int len)
{
	for (int i = 0; i < len; i++)
        if (str1[i] != str2[i])
        	return (str1[i] - str2[i]);
    return (0);
}

void    *ft_memmove(char *first, char *second, int len)
{
    char  str[len];
    for (int i = 0; i < len; i++)
      str[i] = second[i];
    for (int i = 0; i < len; i++)
        first[i] = str[i];
}

void	*ft_memcpy(char *first, char *second, int len)
{
	for (int i = 0; i < len; i++)
		first[i] = second[i];
}

void	*ft_memccpy(char *first, char *second, int symbol, int len)
{
	for (int i = 0; i < len || second[i] != symbol; i++)
		first[i] = second[i];
}

void	*ft_bzero(char *str, int len)
{
	for (int i = 0; i < len; i++)
		str[i] = '\0';
}

int     ft_atoi(char *str)
{
    int count[2] = {0, 1};
    int result = 0;
    int checkMinus = -1;

    if (str[0] == '-')
    {
        count[0]++;
        checkMinus = 0;
    }
    while (str[count[0]] && (str[count[0]] >= 48 && str[count[0]] <= 57))
        count[0]++;
    count[0]--;
    while (count[0] != checkMinus)
    {
        result += (str[count[0]] - 48) * count[1];
        count[1] *= 10;
        count[0]--;
    }
    return (str[0] == '-' ? result * -1: result);
}

