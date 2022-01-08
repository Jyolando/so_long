/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:44:39 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 15:44:39 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	ft_get_img(t_vars mlx, t_data game, char *file)
{
	int	x;
	int	y;

	game.img = mlx_png_file_to_image(mlx.mlx, file, &x, &y);
	if (game.img == NULL)
		ft_error("Error\nFailed image.");
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	return (game);
}

t_game	ft_init_images(t_vars mlx, t_game map)
{
	map.player = ft_get_img(mlx, map.player, "images/player.png");
	map.exit = ft_get_img(mlx, map.exit, "images/exit.png");
	map.coin = ft_get_img(mlx, map.coin, "images/coin.png");
	map.wall = ft_get_img(mlx, map.wall, "images/wall.png");
	map.empty = ft_get_img(mlx, map.empty, "images/empty.png");
	return (map);
}
