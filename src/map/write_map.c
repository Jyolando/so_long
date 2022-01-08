#include "../so_long.h"

static t_game	init_struct()
{
	t_game	map;

	map.map_lenght = 0;
	map.max_score = 0;
	map.te_x = 0;
	map.te_y = 0;
	return (map);
}


int get_height(char *file)
{
	int fd;
	char *line;
	int height;

	height = 0;
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

t_game	ft_write_map(t_game map, char *file, int fd)
{
	int line;

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
