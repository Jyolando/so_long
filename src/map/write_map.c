#include "../so_long.h"

t_game	ft_write_map(t_game map)
{
	int line;
	int i;

	line = 0;
	if ((ft_strlen(map.map_all) / map.map_lines ) != map.map_firstlen)
		ft_error("Map is invalid.\n");
	map.map_height = map.map_lines;
	map.map_lenght = map.map_firstlen - 1;
	map.map_content = (char **)malloc(sizeof(char *) * (map.map_lines));
	if (map.map_content == NULL)
		ft_error("Malloc error.\n");
	while (line < map.map_lines)
	{
		map.map_content[line] = (char *)malloc(sizeof(char) * map.map_firstlen);
		i = 0;
		while (*map.map_all != '\n' && *map.map_all)
		{
			map.map_content[line][i++] = *map.map_all++;
		}
		map.map_content[line][i] = '\0';
		map.map_all++;
		line++;
	}
	return (map);
}
