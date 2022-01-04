#include "so_long.h"

void ft_free_array(char **arr, int size)
{
	while (size--)
	{
		free(arr[size]);
	}
	free(arr);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
