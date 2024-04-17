CC=clang
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c
HEADER=libft.h
OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

.PHONY: all clean fclean re bonus
