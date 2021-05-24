#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int 	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*writing(char **line, char *pred, char *ost);
int		ft_strnchr(char *str, char c);
char	*write_pred(char *pred, char *buf);
int		memory(char **line, char *pred);
int		get_next_line(int fd, char **line);
#endif