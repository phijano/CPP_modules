NAME = megaphone

MAIN = megaphone.cpp

MAINOBJ = $(MAIN:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(MAINOBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(MAINOBJ)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(MAINOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
