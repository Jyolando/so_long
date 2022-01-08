/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:03:54 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 22:55:26 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_symbs(t_game map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (j < map.map_lenght)
		{
			if (map.map_content[i][j] != '1' && map.map_content[i][j] != '0' &&
				map.map_content[i][j] != 'P' && map.map_content[i][j] != 'E' &&
				map.map_content[i][j] != 'C' && map.map_content[i][j] != 'F')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_walls(t_game map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (j < map.map_lenght)
		{
			if (i == 0 || i == map.map_height - 1)
				if (map.map_content[i][j] != '1')
					return (0);
			if (i != 0 && i != map.map_height - 1)
				if ((j == 0 || j == map.map_lenght - 1)
					&& map.map_content[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_player(t_game map, char c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (map.map_content[i][j])
		{
			if (flag == 0 && map.map_content[i][j] == c)
				flag = 1;
			else if (flag == 1 && map.map_content[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (flag);
}

static int	check_coin_exit(t_game map, char c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (map.map_content[i][j])
		{
			if (flag == 0 && map.map_content[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (flag);
}

int	ft_check_map(t_game map)
{
	if (!check_symbs(map) || !check_walls(map)
		|| !check_player(map, 'P') || !check_coin_exit(map, 'E')
		|| !check_coin_exit(map, 'C'))
	{
		ft_free_array(map.map_content, map.map_height);
		ft_error("Error\nMap is invalid.\n");
	}
	return (1);
}
