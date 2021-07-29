NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = minishell.c \
		minishell_utils1.c \
		minishell_utils2.c \
		minishell_utils3.c \
		parsing_main.c \
		parsing_one.c \
		parsing_two.c \
		parsing_three.c \
		command_one.c \
		command_two.c \
		command_three.c \
		minishell_var_one.c \
		minishell_var_two.c \
		parsing_command.c \
		ft_itoa.c \

OBJS = $(FILES:%.c=%.o)

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re