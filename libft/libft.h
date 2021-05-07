#ifndef LIBFT_H
# define LIBFT_H

int	ft_isprint(int symbol);
int	ft_isdigit(int symbol);
int	ft_isalnum(int symbol);
int	ft_isascii(int symbol);
int	ft_isalpha(int symbol);
int	ft_tolower(int symbol);
int	ft_toupper(int symbol);
int	ft_strlcpy(char *result, const char *str, int len);
int	ft_strlcat(char *result, const char *str, int len);
char	*ft_strrchr(char *str, int symbol);
int	ft_strlen(char *str);
int	ft_strncmp(const char *str1, const char *str2, int len);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, int symbol);
void	ft_memset(char *str, int symbol, int len);
char	*ft_memchr(char *str, int symbol, int len);
int	ft_memcmp(char *str1, char *str2, int len);
void	ft_memmove(char *first, char *second, int len);
void	ft_memcpy(char *first, char *second, int len);
void	ft_memccpy(char *first, char *second, int symbol, int len);
void	ft_bzero(char *str, int len);
int	ft_atoi(char *str);
char	*ft_itoa(int number);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nbr, int fd);
#endif
