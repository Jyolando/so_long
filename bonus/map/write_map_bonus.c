/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:25:20 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 21:56:50 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static t_game	init_struct(void)
{
	t_game	map;

	map.map_lenght = 0;
	map.max_score = 0;
	map.te_x = 0;
	map.te_y = 0;
	map.player.curr_dir = 1;
	return (map);
}

static int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

t_game	ft_write_map(t_game map, char *file, int fd)
{
	int	line;

	line = 0;
	map = init_struct();
	map.map_height = get_height(file);
	map.map_content = (char **)malloc(sizeof(char *) * (map.map_height));
	if (map.map_content == NULL)
		ft_error("Error\nMalloc error.\n");
	while (line < map.map_height)
	{
		map.map_content[line] = get_next_line(fd);
		if (!map.map_lenght)
			map.map_lenght = ft_strlen(map.map_content[line]) - 1;
		line++;
	}
	return (map);
}
