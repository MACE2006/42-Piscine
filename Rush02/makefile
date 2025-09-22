CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = magic_func.c main.c print_func.c str_func.c

OBJS = $(SRCS:.c=.o)

NAME = rush-02

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c header/header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re