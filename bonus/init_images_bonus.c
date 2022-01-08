/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:44:39 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 23:17:18 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	map.player.pl_right = ft_get_img(mlx,
			map.player.pl_right, "assets/images/pl_right.png");
	map.player.pl_left = ft_get_img(mlx,
			map.player.pl_left, "assets/images/pl_left.png");
	map.player.pl_death = ft_get_img(mlx,
			map.player.pl_death, "assets/images/pl_death.png");
	map.exit = ft_get_img(mlx, map.exit, "assets/images/exit.png");
	map.exit_cl = ft_get_img(mlx,
			map.exit_cl, "assets/images/exit_closed.png");
	map.clear = ft_get_img(mlx, map.clear, "assets/images/clear.png");
	map.foe = ft_get_img(mlx, map.foe, "assets/images/foe.png");
	map.coin = ft_get_img(mlx, map.coin, "assets/images/coin.png");
	map.wall = ft_get_img(mlx, map.wall, "assets/images/wall.png");
	map.empty = ft_get_img(mlx, map.empty, "assets/images/empty.png");
	return (map);
}
