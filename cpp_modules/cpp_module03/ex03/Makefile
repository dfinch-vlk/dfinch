NAME = ScavTrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

FILES = ClapTrap.cpp  main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = $(FILES:%.cpp=%.o)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
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