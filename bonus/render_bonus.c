/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:40:09 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 23:16:39 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_win_closed(int keycode, t_all *all)
{
	exit(0);
	return (0);
}

static int	key_hook(int keycode, t_all *all)
{
	if ((keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		&& all->map.gover != 1)
	{
		if (ft_move(keycode, all))
		{
			++all->moves;
			update_score(all);
		}
	}
	if (keycode == 53)
	{
		mlx_destroy_image(all->mlx.mlx, all->mlx.win);
		exit (0);
	}
	return (0);
}

void	render_objs(t_game map, t_vars mlx, int i, int j)
{
	if (map.map_content[i][j] == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.win,
			map.player.pl_right.img, j * 24, i * 24 + SCR);
	if (map.map_content[i][j] == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.win,
			map.coin.img, j * 24, i * 24 + SCR);
	if (map.map_content[i][j] == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.win,
			map.exit.img, j * 24, i * 24 + SCR);
	if (map.map_content[i][j] == 'F')
		mlx_put_image_to_window(mlx.mlx, mlx.win,
			map.foe.img, j * 24, i * 24 + SCR);
}

void	render_map(t_game map, t_vars mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (map.map_content[i][j])
		{
			if (map.map_content[i][j] == '1')
				mlx_put_image_to_window(mlx.mlx, mlx.win,
					map.wall.img, j * 24, i * 24 + SCR);
			if (map.map_content[i][j] == '0')
				mlx_put_image_to_window(mlx.mlx, mlx.win,
					map.empty.img, j * 24, i * 24 + SCR);
			render_objs(map, mlx, i, j);
			j++;
		}
		i++;
	}
}

void	ft_render(t_game map)
{
	t_vars	mlx;
	t_all	all;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, map.map_lenght * 24,
			map.map_height * 24 + SCR, "so_long_bonus");
	map = ft_init_images(mlx, map);
	render_map(map, mlx);
	all.map = map;
	all.mlx = mlx;
	all.moves = 0;
	mlx_string_put(all.mlx.mlx, all.mlx.win, 20, 50, 0x00C0C0C0, "MOVES:");
	update_score(&all);
	mlx_key_hook(mlx.win, key_hook, &all);
	mlx_hook(mlx.win, 17, 0L, ft_win_closed, &all);
	mlx_loop(mlx.mlx);
}
