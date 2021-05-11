#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isprint(int symbol);
int		ft_isdigit(int symbol);
int		ft_isalnum(int symbol);
int		ft_isascii(int symbol);
int		ft_isalpha(int symbol);
int		ft_tolower(int symbol);
int		ft_toupper(int symbol);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlcat(char *dst, const char *src, int dstsize);
char	*ft_strrchr(char *str, int c);
int		ft_strlen(char *str);
int		ft_strncmp(const char *str1, const char *str2, int len);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, int symbol);
void	*ft_memset(char *str, int symbol, int len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *d, const void *s, int c, size_t n);
void	ft_bzero(char *str, int len);
int		ft_atoi(char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nbr, int fd);
char	*ft_calloc(int first, int second);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
char	*ft_substr(char *s, unsigned int start, int len);
#endif
