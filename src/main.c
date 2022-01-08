/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:30:18 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 15:30:50 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int c, char **v)
{
	int		fd;
	t_game	map;

	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		if (fd < 0)
			ft_error("Error\nFile doesn't exist.\n");
		map = ft_write_map(map, v[1], fd);
		if (ft_check_map(map))
		{
			map = ft_init_map(map);
			ft_render(map);
		}
	}
	else
		ft_error("Error\nYou need put: ./so_long name_map\n");
}
