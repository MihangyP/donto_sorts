### ARGUMENTS
NAME = donto_sort
SRC_FILES = src/main.c src/errors.c src/bubble_sort.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include
RM = rm -rf

### RULES
all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_FILES) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
