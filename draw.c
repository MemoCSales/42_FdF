/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:46:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/12 15:52:21 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda_algo(t_data *data, t_final a, t_final b)
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
		my_mlx_pixel_put(data, x, y, WHITE);
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
		dst = data->address + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

/*
x' = (x - y) * cos(30)
y' = (x + y) * sin(30) - z*/
void	isometric_projection(t_data *data)
{
	float	iso_x;
	float	iso_y;
	int		x;
	int		y;
	int		index;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			index = y * data->max_x + x;
			iso_x = (data->table[y][x].x - data->table[y][x].y)
				* cos(DEG_TO_RAD(30));
			iso_y = (-data->table[y][x].z + (data->table[y][x].x
						+ data->table[y][x].y) * sin(DEG_TO_RAD(30)));
			data->final_table[index].x = iso_x * data->scale;
			data->final_table[index].y = iso_y * data->scale;
			x++;
		}
		y++;
	}
}
