CC=clang
CFLAGS=-Wall -Wextra -Werror -g
NAME=libftprintf.a
SRCS=src/ft_printf.c src/ft_utils.c src/ft_print_chars.c \
	 src/ft_print_numbers.c src/ft_hexa.c src/ft_length.c
HEADER=src/ft_printf.h
OBJS=$(SRCS:.c=.o)
LIBFT = libft/libft.a

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $(OBJS)

$(LIBFT):
	make -C libft all
	cp $(LIBFT) $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

re: fclean all

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

clean:
	rm -rf *.o */*.o

.PHONY: all clean fclean re
