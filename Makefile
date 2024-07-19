### ARGUMENTS
NAME = donto_sort
FILES = main.c errors.c bubble_sort.c insertion_sort.c selection_sort.c \
		counting_sort.c utils.c quick_sort.c
SRC_FILES = $(addprefix src/, $(FILES))
CC = cc -g
CFLAGS = -Wall -Wextra # -Werror
INCLUDE = -I./include -I./raylib/include
RM = rm -rf

### RULES
all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_FILES) -o $(NAME) -Lraylib/lib -lraylib -lm

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
