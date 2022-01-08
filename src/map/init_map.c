/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:22:28 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 15:22:30 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
