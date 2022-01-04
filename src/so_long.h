#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"

typedef struct s_game
{
	int	map_lenght;
	int	map_height;
	int map_lines;
	int map_firstlen;
	int p_x;
	int p_y;
	int e_x;
	int e_y;
	int max_score;
	char *map_all;
	char **map_content;
}				t_game;


void	ft_putstr(char *str);
void ft_free_array(char **arr, int size);
void	ft_error(char *errormsg);

t_game ft_read_map(int fd);
t_game	ft_write_map(t_game map);
int	ft_check_map(t_game map);

#endif
