#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
char	*ft_strdup(const char *s1);
int		ft_putchar(char c);
char	*ft_system(int n, int q, int flag);
#endif
