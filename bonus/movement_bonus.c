/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:33:10 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 22:36:26 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_exit(t_all *all, int x, int y)
{
	if (all->map.map_content[all->map.p_y + y][all->map.p_x + x] == 'E')
	{
		if (all->map.max_score != 0)
		{
			all->map.te_x = all->map.p_x + x;
			all->map.te_y = all->map.p_y + y;
		}
		else
		{
			mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
				all->map.empty.img, all->map.p_x * 24, all->map.p_y * 24 + SCR);
			mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
				all->map.exit_cl.img, (all->map.p_x + x) * 24,
				(all->map.p_y + y) * 24 + SCR);
			all->map.gover = 1;
			return (1);
		}
	}
	return (0);
}

static void	is_coin(t_all *all, int x, int y)
{
	if (all->map.map_content[all->map.p_y + y][all->map.p_x + x] == 'C')
	{
		all->map.map_content[all->map.p_y + y][all->map.p_x + x] = '0';
		all->map.max_score--;
	}
}

static void	change_direction(t_all *all, int x)
{
	if (x == -1 || (x == 0 && all->map.player.curr_dir == 0))
	{
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->map.player.pl_left.img, all->map.p_x * 24,
			all->map.p_y * 24 + SCR);
		all->map.player.curr_dir = 0;
	}
	else if (x == 1 || (x == 0 && all->map.player.curr_dir == 1))
	{
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->map.player.pl_right.img, all->map.p_x * 24,
			all->map.p_y * 24 + SCR);
		all->map.player.curr_dir = 1;
	}
}

static int	move(t_all *all, int x, int y)
{
	int	flag;

	flag = 0;
	if (all->map.map_content[all->map.p_y + y][all->map.p_x + x] == '1')
		return (0);
	if (all->map.te_x != 0 || all->map.te_y != 0)
		flag = temp_exit(all);
	if (is_exit(all, x, y))
		return (1);
	if (is_foe(all, x, y))
		return (1);
	is_coin(all, x, y);
	if (!flag)
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->map.empty.img,
			all->map.p_x * 24, all->map.p_y * 24 + SCR);
	all->map.p_y += y;
	all->map.p_x += x;
	change_direction(all, x);
	return (1);
}

int	ft_move(int keycode, t_all *all)
{
	if (keycode == 13)
		return (move(all, 0, -1));
	if (keycode == 0)
		return (move(all, -1, 0));
	if (keycode == 1)
		return (move(all, 0, 1));
	if (keycode == 2)
		return (move(all, 1, 0));
	return (0);
}
