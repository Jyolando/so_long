#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"

#define SCORE 100

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game
{
	int	map_lenght;
	int	map_height;
	t_data player;
	t_data exit;
	t_data coin;
	t_data wall;
	t_data empty;
	int p_x;
	int p_y;
	int te_x;
	int te_y;
	int gover;
	int max_score;
	char **map_content;
}				t_game;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_all
{
	t_game map;
	t_vars mlx;
	int	moves;
}	t_all;

void	ft_putstr(char *str);
void ft_free_array(char **arr, int size);
void	ft_error(char *errormsg);

t_game	ft_write_map(t_game map, char *file, int fd);
t_game	ft_init_map(t_game map);
int	ft_check_map(t_game map);
int ft_move(int keycode, t_all *all);

void	ft_render(t_game map);

t_game ft_init_images(t_vars mlx, t_game map);

#endif
