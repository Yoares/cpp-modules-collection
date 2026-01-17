NAME = RPG

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AMateria.cpp \
	   Character.cpp \
	   Cure.cpp \
	   Ice.cpp \
	   ICharacter.cpp \
	   IMateriaSource.cpp \
	   MateriaSource.cpp \
	   main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re