NAME = main

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c lexer.c eval.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re