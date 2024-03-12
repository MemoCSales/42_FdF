/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:46:19 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/12 13:24:30 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_point(t_data *data, char *point, int x, int y)
{
	char	**map;
	int		i;

	data->table[y][x].x = x;
	data->table[y][x].y = y;
	if (ft_strchr(point, ','))
	{
		map = ft_split(point, ',');
		data->table[y][x].z = (float)ft_atoi(map[0]);
		i = 0;
		while (map[i])
			free(map[i++]);
		free(map);
	}
	else
		data->table[y][x].z = (float)ft_atoi(point);
	if (data->table[y][x].z > data->max_z)
		data->max_z = data->table[y][x].z;
	if (data->table[y][x].z < data->min_z)
		data->min_z = data->table[y][x].z;
}

void	connect_point(t_data *data)
{
	int	x;
	int	y;

	data->i = 0;
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			connect_x_y(data, data->i);
			data->i++;
			x++;
		}
		y++;
	}
	free(data->final_table);
}

void	connect_x_y(t_data *data, int i)
{
	t_final	x;
	t_final	y;
	int		row;
	int		col;
	int		index;

	row = i / data->max_x;
	col = i % data->max_x;
	index = row * data->max_x + col;
	x.x = data->final_table[index].x;
	x.y = data->final_table[index].y;
	if (col < data->max_x - 1)
	{
		index = row * data->max_x + (col + 1);
		y.x = data->final_table[index].x;
		y.y = data->final_table[index].y;
		dda_algo(data, x, y);
	}
	if (row < data->max_y - 1)
	{
		index = (row + 1) * data->max_x + col;
		y.x = data->final_table[index].x;
		y.y = data->final_table[index].y;
		dda_algo(data, x, y);
	}
}

void	calculate_scale(t_data *data)
{
	float	scale_x;
	float	scale_y;

	scale_x = (float)(WIN_WIDTH) / (2 * data->max_x);
	scale_y = (float)(WIN_HEIGHT) / (2 * data->max_y);
	data->scale = (fmin(scale_x, scale_y) / 2);
	data->scale *= data->zoom;
}
