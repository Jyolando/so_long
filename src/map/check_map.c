#include "../so_long.h"

static int	check_symbs(t_game map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (map.map_content[i][j])
		{
			if (map.map_content[i][j] != '1' && map.map_content[i][j] != '0' &&
				map.map_content[i][j] != 'P' && map.map_content[i][j] != 'E' &&
				map.map_content[i][j] != 'C')
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
		while (map.map_content[i][j])
		{
			if (i == 0 || i == map.map_height - 1)
				if (map.map_content[i][j] != '1')
					return (0);
			if (i != 0 && i != map.map_height - 1)
				if ((j == 0 || j == map.map_lenght - 1) &&
					map.map_content[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_player_exit(t_game map, char c) {
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

static int	check_coin(t_game map) {
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
			if (flag == 0 && map.map_content[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (flag);
}

int	ft_check_map(t_game map)
{
	if (!check_symbs(map) || !check_walls(map) ||
		!check_player_exit(map, 'P') || !check_player_exit(map, 'E') ||
		!check_coin(map))
	{
		ft_free_array(map.map_content, map.map_height);
		ft_error("Map is invalid.\n");
	}
	return (1);
}
