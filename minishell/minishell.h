#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h> //DELITE
# include <errno.h>

typedef struct s_shell
{	
	char **arg;
	int len_arg;
} t_shell;

typedef struct s_var
{
	char **vars;
	int len_vars;
	char *str;
	t_shell *shell;
	int len_shell;
	int ret;
} t_var;

t_var var;

int ft_strlen(char *str);
char *my_join(char *s, char c);
char *new_line(void);
int ft_strncmp(char *s1, char *s2, int len);
int count_char(char *str, char c);
void exit_but(void);
void parsing(void);
int miss_space(void);
int clrscr(void);
int command_cd(int count);
int command_open(int count);
void freendom();
void	writing_var();
char	*ft_strjoin(char *s1, char *s2);
int command_env();
char *ft_strchr(char *str, char c);
int find_var(char *find);
char *find_var_result(char *find);
int delite_var(char *find);
int command_unset(int count);
void read_file(char *file);
char *get_var(char *find);
char	*ft_itoa(int n);
int add_var(char *find);
int command_export(int count);
int command_echo(int i);
void parsing_main(int i);
int count_arg();
int parsing_final(int i);
int parsing_command(int count);
void check_dup_var(char *s);


#endif