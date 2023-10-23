NAME = Violenciainnecesaria

MAIN = main.cpp

SOURCES = \
		  Weapon.cpp HumanA.cpp HumanB.cpp\

MAINOBJ = $(MAIN:.cpp=.o)
OBJECTS = $(SOURCES:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(MAINOBJ) $(OBJECTS)
	$(CC) -o $(NAME) $(CFLAGS) $(MAINOBJ) $(OBJECTS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(MAINOBJ) $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
