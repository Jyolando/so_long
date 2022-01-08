# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 00:33:30 by jyolando          #+#    #+#              #
#    Updated: 2022/01/08 18:54:50 by jyolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/main.c \
		src/map/write_map.c src/map/check_map.c \
		src/map/init_map.c \
		src/render.c \
		src/utils.c src/error.c \
		src/init_images.c\
		src/movement.c\
		library/gnl/get_next_line.c library/gnl/get_next_line_utils.c \

OBJ = $(SRCS:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -I./library/mlx -I./library/gnl -I./library/libft -g -D BUFFER_SIZE=1 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C library/mlx
	$(CC) $(OBJ) -L library/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	mv library/mlx/libmlx.dylib .

clean:
	make -C library/mlx clean
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME) libmlx.dylib

re:				fclean
				make all
