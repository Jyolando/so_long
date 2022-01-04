# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 00:33:30 by jyolando          #+#    #+#              #
#    Updated: 2022/01/04 23:36:35 by jyolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/main.c \
		src/map/read_map.c src/map/write_map.c\
		src/utils.c src/error.c \
		\
		gnl/get_next_line.c gnl/get_next_line_utils.c \

OBJ = $(SRCS:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -I./mlx -I./gnl -I./libft -D BUFFER_SIZE=42 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean:
	rm -rf $(OBJ) $(NAME)

re:				fclean
				make all
