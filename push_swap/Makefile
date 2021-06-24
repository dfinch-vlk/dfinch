NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = 25_line.c \
		algoritm_dop.c \
		algoritm_main.c \
		push_swap.c \
		push_swap_dop.c \
		push_swap_utils_part1.c \
		push_swap_utils_part2.c \
		function_p.c \
		function_r.c \
		function_rr.c \
		function_s.c \

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