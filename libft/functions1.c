#include <stdlib.h>
#include <unistd.h>

char    *ft_itoa(int number)
{
    char    *result;
    int     array[3] = {0, 1, 0};
    
    if (number < 0)
    {
        array[2] = 1;
        number *= -1;
    }
    while (number % (array[1] *= 10) != number)
        array[0]++;  
    result = malloc(array[0] + array[2] + 2);
    array[0] += array[2];
    if (array[2] == 1)
        result[0] = '-';
    result[array[0] + 1] = 0;
    while (array[0] != array[2] - 1)
    {
        result[array[0]--] = number % 10 + 48;
        number = (number - number % 10) / 10;
    }    
    return (result);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    for (int i = 0; s[i]; i++)
      write (fd, &s[i], 1); 
}

void	ft_putendl_fd(char *s, int fd)
{
	for (int i = 0; s[i]; i++)
    	write (fd, &s[i], 1); 
    write (fd, "\n", 1);
}

void    ft_putnbr_fd(int nbr, int fd)
{   
    char symbol;
    int count = 1;
    if (nbr < 0)
    {
      write(fd, "-", 1);
      nbr *= -1;
    }
    while (nbr % (count *= 10) != nbr);
    while ((count /= 10) != 0)
    {
        symbol = nbr / count + 48;
        write (fd, &symbol, 1);
        nbr -= count * (nbr / count);
    }
}

char    *ft_substr(char const *s, unsigned int start, int len)
{
    char    *result = malloc(sizeof(char) * (strlen(s) - start) + 1);
    int        count = 0;

    while (count != len)
        result[count++] = s[start++];
    result[count] = 0;
    return (result);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *result = malloc(sizeof(char) * (strlen(s1) + strlen(s2)) + 1);
    int     count = 0;

    while (s1[count])
    {
        result[count] = s1[count];
        count++;
    }
    for (int i = 0; s2[i]; i++)
        result[count++] = s2[i];
    result[count] = 0;
    return (result);
}

void  **ft_memory_split(const char *str, char **result, char c)
{
  int     count[2] = {0,0};
  for (int i = 0; str[i]; i++)
    {
        if (str[i] == c || str[i + 1] == '\0')
        {
            result[count[1]] = (char **)malloc(sizeof(char) * (i - count[0]) + 1);
            count[0] = i;
            count[1]++;
        }
    }
}

char    **ft_split(char const *str, char c)
{
    char    **result;
    int     count = 0;
    int     row = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            count++;
    result = (char *)malloc(sizeof(char *) * (count + 1));
    count = 0;
    ft_memory_split(str, result, c);
    for (int i = 0; str[i]; i++)
    {
      if (str[i] == c)
      {
        result[row][count] = 0;
        count = 0;
        row++;
        i++;
      }
      result[row][count++] = str[i];
    }
    result[row][count] = 0;
    return (result);
}