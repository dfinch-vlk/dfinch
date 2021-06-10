#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_printf(const char *str, ...);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_itoal(long int n);
char	*ft_system(uint64_t n, uint64_t q, short flag);
char	*ft_strjoin(char const *s1, char const *s2);
int		fr_printf_main(const char *str, va_list args);
int		find_num(const char *str, va_list args, int *flag, int *check);
int		ft_flag(int *flag, int symbol);
int		ft_printf_args(int width, int accuracy, int *array, va_list args);
int		ft_id(va_list args, int accuracy, int width, int *array);
int		ft_sc(int accuracy, int width, int *array);
int		ft_s(va_list args, int accuracy, int width, int *array);
int		ft_p(va_list args, int accuracy, int width, int *array);
int		ft_X(va_list args, int accuracy, int width, int *array);
int		ft_x(va_list args, int accuracy, int width, int *array);
int		ft_u(va_list args, int accuracy, int width, int *array);
int		ft_c(va_list args, int width, int *array);
int		ft_end(int width, int flag);
char	*add_str(char *s, int accuracy);
char	*acc_str(char *s, int accuracy);
int		args_next(int width, char *str, int flag, int accuracy);
int		ft_args3(char *str, int width);
int		ft_args2(char *case_width, char *str);
int		ft_args1(char *case_width, char *str, int width);
char	*ft_malloc(int size, int width, int flag);
int		my_putstr(char *str);
int		ft_isalpha(int c);
int		conditions(int symbol);
int		ft_printf_main_if(int *width, int *count, int array, int arrow);
void	ft_args3_dop(int count1, char *str, char *result);
int		args_next_dop(int accuracy, char *case_width, char *str, int flag);

#endif
