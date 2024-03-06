#include "fdf.h"

void dda_algo(t_data *data, t_final a, t_final b)
{
	float	step;
	float	x;
	float	y;
	int		i;
	t_delta	d;

	i = 0;
	d.dx = b.x - a.x;
	d.dy = b.y - a.y;
	if (fabsf(d.dx) >= fabsf(d.dy))
		step = fabsf(d.dx);
	else
		step = fabsf(d.dy);
	d.dx = d.dx / step;
	d.dy = d.dy / step;
	x = a.x;
	y = a.y;
	while (i < step)
	{
		my_mlx_pixel_put(data, -x + WIN_WIDTH / 2, -y + WIN_HEIGHT / 2, RED); // data->translation missing
		x = x + d.dx;
		y = y + d.dy;
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		{
			dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
}
