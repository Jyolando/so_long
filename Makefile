# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 00:33:30 by jyolando          #+#    #+#              #
#    Updated: 2022/01/08 02:48:41 by jyolando         ###   ########.fr        #
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
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		libft/ft_strdup.c

OBJ = $(SRCS:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -I./mlx -I./gnl -I./libft -g -D BUFFER_SIZE=1 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean:
	rm -rf $(OBJ) $(NAME)

re:				fclean
				make all
