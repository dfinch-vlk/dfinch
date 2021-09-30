NAME = attacks

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

FILES = HumanB.cpp main.cpp HumanA.cpp Weapon.cpp

OBJS = $(FILES:%.cpp=%.o)

%.o: %.cpp HumanB.hpp HumanA.hpp Weapon.hpp
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