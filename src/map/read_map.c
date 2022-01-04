#include "../so_long.h"

static t_game	init_struct()
{
	t_game	map;

	map.map_firstlen = 0;
	map.map_lines = 0;
	map.map_all = "";
	return (map);
}

t_game ft_read_map(int fd)
{
	char *s;
	t_game map;

	map = init_struct();
	s = get_next_line(fd);
	while (s != NULL)
	{
		map.map_all = ft_strjoin(map.map_all, s);
		if (!map.map_firstlen)
		{
			map.map_firstlen = ft_strlen(s);
		}
		map.map_lines++;
		s = get_next_line(fd);
	}
	//
	ft_putstr("OK!\n");
	//
	return (map);
}
