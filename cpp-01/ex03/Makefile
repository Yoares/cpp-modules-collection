NAME = program

CC = g++ 

fLAGS = -Wall -Wextra -Werror

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(fLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(fLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re