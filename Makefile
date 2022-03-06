NAME = ser

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard ./*c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): server client

server: $(OBJS)
	gcc -o server server.c minitalk_utils.c ft_printf.c $(CFLAGS)

client: $(OBJS)
	gcc -o client client.c minitalk_utils.c ft_printf.c $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re