#include "fdf.h"

int	init_fdf(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free(data->mlx);
		print_error("Error in mlx_init");
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_lenght, &data->endian);
	final_table(data);
	connect_point(data);
	mlx_put_image_to_window(data->mlx, data->win, \
							data->img, 0, 0);
	mlx_loop(data->mlx);
	return (0);
}