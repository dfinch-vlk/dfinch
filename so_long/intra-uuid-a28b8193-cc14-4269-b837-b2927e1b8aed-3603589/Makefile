NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = errors.c \
		open_map_part1.c \
		open_map_part2.c\
		render.c \
		so_long.c \
		utils.c \
		custom_gnl.c \
		moves.c \
		events.c \
		enemy.c \
		ft_itoa.c \
		ft_strjoin.c \
		25_lines.c \

OBJS = $(FILES:%.c=%.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L . -lmlx $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re