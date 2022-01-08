/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:31:28 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 23:22:28 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	temp_exit(t_all *all)
{
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->map.exit.img,
		all->map.te_x * 24, all->map.te_y * 24 + SCR);
	all->map.te_x = 0;
	all->map.te_y = 0;
	return (1);
}

int	is_foe(t_all *all, int x, int y)
{
	if (all->map.map_content[all->map.p_y + y][all->map.p_x + x] == 'F')
	{
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->map.player.pl_death.img, all->map.p_x * 24,
			all->map.p_y * 24 + SCR);
		all->map.gover = 1;
		return (1);
	}
	return (0);
}

void	update_score(t_all *all)
{
	int		i;
	int		j;
	char	*str;

	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
		all->map.clear.img, 85, 20);
	str = ft_itoa(all->moves);
	mlx_string_put(all->mlx.mlx, all->mlx.win, 90, 50, 0x00C0C0C0, str);
	free(str);
}
