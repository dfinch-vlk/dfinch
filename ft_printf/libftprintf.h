#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_atoi(const char *str);
int 	ft_strlen(const char *s);
int ft_printf(char *str, ...);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_itoal(long int n);
char	*ft_system(long n, long q, short flag);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
