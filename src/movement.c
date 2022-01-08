#include "so_long.h"

#include <stdio.h>

static int is_exit(t_all *all, int x, int y)
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
			mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->map.empty.img,
							all->map.p_x * 24, all->map.p_y * 24);
			all->map.gover = 1;
			return (1);
		}
	}
	return (0);
}

static void is_coin (t_all *all, int x, int y)
{
	if (all->map.map_content[all->map.p_y + y][all->map.p_x + x] == 'C')
	{
		all->map.map_content[all->map.p_y + y][all->map.p_x + x] = '0';
		all->map.max_score--;
	}
}

static int	move(t_all *all, int x, int y)
{
	int flag;

	flag = 0;
	if (all->map.map_content[all->map.p_y + y][all->map.p_x + x] == '1')
		return (0);
	if (all->map.te_x != 0 || all->map.te_y != 0)
	{
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->map.exit.img,
							all->map.te_x * 24, all->map.te_y * 24);
		all->map.te_x = 0;
		all->map.te_y = 0;
		flag = 1;
	}
	if (is_exit(all, x, y))
		return (1);
	is_coin(all, x, y);
	if (!flag)
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->map.empty.img,
								all->map.p_x * 24, all->map.p_y * 24);
	all->map.p_y += y;
	all->map.p_x += x;
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->map.player.img,
							all->map.p_x * 24, all->map.p_y * 24);

	return (1);
}

//static int	move_down(t_all *all)
//{

//}

int ft_move(int keycode, t_all *all)
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
