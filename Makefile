# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 00:33:30 by jyolando          #+#    #+#              #
#    Updated: 2022/01/08 22:11:42 by jyolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

SRCS =			src/main.c \
				src/map/write_map.c src/map/check_map.c src/map/init_map.c \
				src/utils.c src/error.c \
				src/render.c src/init_images.c src/movement.c\
				library/gnl/get_next_line.c library/gnl/get_next_line_utils.c \

BONUS_SRCS =	bonus/main_bonus.c \
				bonus/map/write_map_bonus.c bonus/map/check_map_bonus.c bonus/map/init_map_bonus.c \
				bonus/utils_bonus.c bonus/error_bonus.c bonus/render_utils_bonus.c\
				bonus/render_bonus.c bonus/init_images_bonus.c bonus/movement_bonus.c\
				library/gnl/get_next_line.c library/gnl/get_next_line_utils.c \
				library/libft/ft_itoa.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -I./library/mlx -I./library/gnl -I./library/libft -g -D BUFFER_SIZE=1 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C library/mlx
	$(CC) $(OBJ) -L library/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	mv library/mlx/libmlx.dylib .

bonus: $(BONUS_OBJS)
	make -C library/mlx
	$(CC) $(BONUS_OBJS) -L library/mlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)
	mv library/mlx/libmlx.dylib .

clean:
	make -C library/mlx clean
	rm -rf $(OBJ) $(BONUS_OBJS)

fclean:	clean
	rm -rf $(NAME) $(BONUS_NAME) libmlx.dylib

re:				fclean
				make all
