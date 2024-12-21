NAME    = philo
SRC     = src
INCLUDE = include
HEADER  = $(INCLUDE)/philo.h
CFILES  = $(SRC)/main.c \
          $(SRC)/init.c \
          $(SRC)/philo.c \
          $(SRC)/end.c \
          $(SRC)/utils.c
OBJECTS = $(CFILES:.c=.o)
FLAGS   = -fsanitize=thread -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(FLAGS) -I $(INCLUDE) $(OBJECTS) -o $(NAME)

$(SRC)/%.o: $(SRC)/%.c $(HEADER)
	gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

