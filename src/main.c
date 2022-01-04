#include "so_long.h"

#include <stdio.h>

int main(int c, char **v)
{
	int fd;
	t_game map;

	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		if (fd < 0)
			ft_error("File doesn't exist.\n");
		map = ft_read_map(fd);
		map = ft_write_map(map);
		if (ft_check_map(map))
		{
			//ft_error("All good");
		}
		//printf("%d\n%d\n%s\n%d\n", map.map_lines, map.map_firstlen, map.map_all, ft_strlen(map.map_all));
		//printf("%s\n%s\n%s\n", map.map_content[0], map.map_content[1], map.map_content[2]);
	}
	else
		ft_error("You need put: ./so_long name_map\n");
}
