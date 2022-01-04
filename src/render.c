//include "../gnl/get_next_line.h"
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//void	my_mlx_print_square(t_data *data, int *x, int *y, int color)
//{
//	int	i;
//	int	j;
//	char	*dst;

//	i = x[0];
//	j = y[0];
//	while(i < x[1])
//	{
//		j = y[0];в
//		while (j < y[1])
//		{
//			dst = data->addr + (i * data->line_length + j * (data->bits_per_pixel / 8));
//			*(unsigned int*)dst = color;
//			j++;
//		}
//		i++;
//	}
//}

void draw_map()
{

}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data  bimg;
	(void)argc;
	int i = 0;
	int j = 25;
	int c = 0;
	int memy = 0;
	int memx = 0;

	 int a = 10, b = 10;

	while(argv[1][c])
	{
		if(argv[1][c] == '1' || argv[1][c] == '0')
		{
			if (memx >= memy)
				i += 25;
			memx++;
		}
		else if (argv[1][c] == '\n')
		{
			j += 25;
			memy = memx;
			memx = 0;
		}
		c++;
	}

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, i, j, "Hello world!");

	img.img = mlx_png_file_to_image(mlx, "wall_texture.png",
         &a, &b);
	bimg.img = mlx_png_file_to_image(mlx, "backwall_texture.png",
		&a, &b);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	bimg.addr = mlx_get_data_addr(bimg.img, &bimg.bits_per_pixel, &bimg.line_length,
								&bimg.endian);
	//my_mlx_print_square(&img, x, y, 0x00FF0000);

	i = j = c = memx = memy = 0;
	while (argv[1][c])
	{
		if (argv[1][c] == '1' || argv[1][c] == '0' || argv[1][c] == '\n')
		{
			if (argv[1][c] == '1' || argv[1][c] == '0')
			{
				if (argv[1][c] == '1')
				{
					mlx_put_image_to_window(mlx, mlx_win, img.img, memy, memx);
				}
				else if (argv[1][c] == '0')
				{
					mlx_put_image_to_window(mlx, mlx_win, bimg.img, memy, memx);
				}
				memy += 25;
			}
			else
			{
				memx += 25;
				memy = 0;
			}

		}
		c++;
	}
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//mlx_string_put(mlx, mlx_win, 70, 70, 0x00FF0000, "hello");

	//img = mlx_xpm_file_to_image(mlx, "../images/player.xpm", 25, 25);

	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
