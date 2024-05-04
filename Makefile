#Program related variables
NAME= so_long
CL= gcc
CFLAGS= -Wall -Wextra -Werror -gdwarf-4

#Paths for libs
LIBFT= libft/libft.a
PRINTF= ft_printf/libftprintf.a
MLX42= MLX42/

#get_next_line
GNL_SRC= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_HEADER= get_next_line/get_next_line.h

#Files
HEADERS= $(GNL_HEADER) src/headers/so_long.h src/headers/structs.h src/headers/map_init.h \
						src/headers/error.h src/headers/map_checks.h src/headers/map_flood.h \
						src/headers/free.h src/headers/window_management.h src/headers/key_management.h
SRCS= $(GNL_SRC) src/map_init.c src/error.c src/main.c src/map_checks.c src/map_flood.c src/free.c \
					src/window_management.c src/key_management.c
					
LIBMLX= $(MLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS= ${SRCS:.c=.o}

#Rules

#Launching all rules
all : libmlx ftprintf libft $(NAME)

#Compile all libs and so_long
$(NAME) : $(OBJS)
	$(CL) $(OBJS) $(LIBMLX) $(LIBFT) $(PRINTF) ; mv a.out $@

#Build MLX42
libmlx :
	cmake $(MLX42) -B $(MLX42)/build && make -C $(MLX42)/build -j4

#Build ft_printf
ftprintf :
	make -C ft_printf all

#Build libft
libft :
	make -C libft all bonus

#Compile all so_long files
%.o: %.c $(HEADER)
	$(CL) $(CFLAGS) $< -c -o $@

#Clean All .o
clean :
	rm -rf src/*.o
	rm -rf get_next_line/*.o
	make -C ft_printf clean
	make -C libft clean

#Clean all .o and executable
fclean : clean
	rm -rf $(NAME)
	make -C ft_printf fclean
	make -C libft fclean

#Clean and remake all
re : clean all

.PHONY : all, clean, fclean, re, libmlx, ftprintf, libft