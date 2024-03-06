/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:46:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/06 20:37:35 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void dda_algo(t_data *data, t_final a, t_final b)
{
	float	step;
	float	x;
	float	y;
	int		i;
	t_delta	d;
	// int		offx;
	// int		offy;

	// offx = (data->win_width - (data->max_x * data->scale)) / 2;
	// offy = (data->win_height - (data->max_y * data->scale)) / 2;
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
		my_mlx_pixel_put(data, x  + data->translation, \
						 y  + data->translation, RED); // data->translation missing
		x = x + d.dx;
		y = y + d.dy;
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
		{
			dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
}
/*
x' = (x - y) * cos(30)
y' = (x + y) * sin(30) - z*/
// void isometric_projection(t_data *data)
// {
// 	float	iso_x;
// 	float	iso_y;	
// 	int		x;
// 	int		y;
// 	int		index;
	
// 	y = 0;
// 	while (y < data->max_y)
// 	{
// 		x = 0;
// 		while (x < data->max_x)
// 		{
// 			index = y * data->max_x + x;
// 			iso_x = (data->table[y][x].x - data->table[y][x].y * cos(DEG_TO_RAD(30)));
// 			iso_y = (data->table[y][x].x + data->table[y][x].y * sin(DEG_TO_RAD(30))) - data->table[y][x].z;
// 			data->final_table[index].x = iso_x;
// 			data->final_table[index].y = iso_y;
// 			// printf("iso_x: %f || iso_y: %f\n", data->final_table[index].x, data->final_table[index].y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void isometric_projection(t_final *x, t_final *y)
{
	t_final old_x;
	t_final	old_y;

	old_x = *x;
	old_y = *y;
	x->x = (old_x.x - old_x.y) * cos(0.523599);
	x->y = (old_x.x - old_x.y) * sin(0.523599);
	y->x = (old_y.x - old_y.y) * cos(0.523599);
	y->y = (old_y.x + old_y.y) * sin(0.523599);
	printf("x->x = %f || x->y = %f\n", x->x, x->y);
}