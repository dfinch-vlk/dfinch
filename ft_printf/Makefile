NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

FILES = ft_atoi.c\
		ft_itoa.c\
		ft_itoal.c\
		ft_printf.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_system.c\
		ft_printf_part1.c\
		ft_printf_part2.c\
		ft_printf_part3.c\
		ft_printf_part4.c\
		ft_printf_part5.c\

OBJS = $(FILES:%.c=%.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re