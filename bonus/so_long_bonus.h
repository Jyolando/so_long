/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:45:17 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/08 23:15:56 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define SCR 100

# include "../library/libft/libft.h"
# include "../library/gnl/get_next_line.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player {
	t_data	pl_right;
	t_data	pl_left;
	t_data	pl_death;
	int		curr_dir;
}				t_player;

typedef struct s_game
{
	int			map_lenght;
	int			map_height;
	int			p_x;
	int			p_y;
	int			te_x;
	int			te_y;
	int			gover;
	int			max_score;
	t_player	player;
	t_data		exit;
	t_data		exit_cl;
	t_data		coin;
	t_data		wall;
	t_data		empty;
	t_data		foe;
	t_data		clear;
	char		**map_content;
}				t_game;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_all
{
	t_game	map;
	t_vars	mlx;
	t_data	img;
	int		moves;
}	t_all;

void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_free_array(char **arr, int size);
void	ft_error(char *errormsg);
void	ft_render(t_game map);
void	update_score(t_all *all);

t_game	ft_init_images(t_vars mlx, t_game map);
t_game	ft_write_map(t_game map, char *file, int fd);
t_game	ft_init_map(t_game map);

int		ft_check_map(t_game map);
int		ft_move(int keycode, t_all *all);
int		temp_exit(t_all *all);
int		is_foe(t_all *all, int x, int y);

#endif
