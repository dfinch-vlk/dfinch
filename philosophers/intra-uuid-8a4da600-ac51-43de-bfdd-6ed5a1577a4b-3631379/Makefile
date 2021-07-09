NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = check.c \
		forks.c \
		lifetime.c \
		main.c \
		philo.c \
		time.c \

OBJS = $(FILES:%.c=%.o)

%.o: %.c libft.h
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