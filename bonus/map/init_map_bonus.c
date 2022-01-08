/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:04:01 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 19:04:06 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static t_game	is_player(t_game map, int i, int j)
{
	map.p_x = j;
	map.p_y = i;
	return (map);
}

t_game	ft_init_map(t_game map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (map.map_content[i][j])
		{
			if (map.map_content[i][j] == 'P')
				map = is_player(map, i, j);
			if (map.map_content[i][j] == 'C')
				map.max_score++;
			j++;
		}
		i++;
	}
	return (map);
}
