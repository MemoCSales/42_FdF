/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:46:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/08 12:53:19 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void dda_algo(t_data *data, t_final a, t_final b)
{
    float   step;
    float   x;
    float   y;
    int     i;
    t_delta d;

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
	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
		{
			dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
}

/*
x' = (x - y) * cos(30)
y' = (x + y) * sin(30) - z*/
void isometric_projection(t_data *data)
{
	float	iso_x;
	float	iso_y;	
	int		x;
	int		y;
	int		index;
	// float	max_iso_x = 0;
	// float	max_iso_y = 0;

	// data->max_iso_x = 0;
	// data->max_iso_y = 0;
	// y = 0;
	// while (y < data->max_y)
	// 	{
	// 		x = 0;
	// 		while (x < data->max_x)
	// 		{
	// 			iso_x = (data->table[y][x].x - data->table[y][x].y) * cos(DEG_TO_RAD(30));
	// 			iso_y = (-data->table[y][x].z + (data->table[y][x].x + data->table[y][x].y) *sin(DEG_TO_RAD(30)));
	// 			if (fabs(iso_x) > data->max_iso_x )
	// 				data->max_iso_x = fabs(iso_x);
	// 			if (fabs(iso_y) > data->max_iso_y)
	// 				data->max_iso_y = fabs(iso_y);
	// 			x++;
	// 		}
	// 		y++;
	// 	}

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			index = y * data->max_x + x;
			iso_x = (data->table[y][x].x - data->table[y][x].y) * cos(DEG_TO_RAD(30));
			iso_y = (-data->table[y][x].z + (data->table[y][x].x + data->table[y][x].y) *sin(DEG_TO_RAD(30)));
			data->final_table[index].x = iso_x * data->scale;
			data->final_table[index].y = iso_y * data->scale;
			// printf("iso_x: %f || iso_y: %f\n", data->final_table[index].x, data->final_table[index].y);
			x++;
		}
		y++;
	}
}

//CHECK IT LATER DONT DELETE
// void isometric_projection(t_data *data)
// {
//     float iso_x;
//     float iso_y;
//     int x;
//     int y;
//     float min_iso_x = FLT_MAX;
//     float min_iso_y = FLT_MAX;
//     float max_iso_x = FLT_MIN;
//     float max_iso_y = FLT_MIN;

//     // Calculate the range of x and y values after the isometric projection
//     for (y = 0; y < data->max_y; y++)
//     {
//         for (x = 0; x < data->max_x; x++)
//         {
//             iso_x = (data->table[y][x].x - data->table[y][x].y) * cos(DEG_TO_RAD(30));
//             iso_y = (-data->table[y][x].z + (data->table[y][x].x + data->table[y][x].y) * sin(DEG_TO_RAD(30)));
//             min_iso_x = fminf(min_iso_x, iso_x);
//             min_iso_y = fminf(min_iso_y, iso_y);
//             max_iso_x = fmaxf(max_iso_x, iso_x);
//             max_iso_y = fmaxf(max_iso_y, iso_y);
//         }
//     }

//     // Determine the scale factor
//     float scale_x = data->win_width / (max_iso_x - min_iso_x);
//     float scale_y = data->win_height / (max_iso_y - min_iso_y);
//     float scale = fminf(scale_x, scale_y);

//     // Adjust the position of the points
//     for (y = 0; y < data->max_y; y++)
//     {
//         for (x = 0; x < data->max_x; x++)
//         {
//             data->table[y][x].x = (data->table[y][x].x - min_iso_x) * scale;
//             data->table[y][x].y = (data->table[y][x].y - min_iso_y) * scale;
//         }
//     }
// }