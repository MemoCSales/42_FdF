/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:45:23 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/07 18:33:50 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int print_error(char *error)
{
    ft_printf("%s\n", error);
    exit(0);
}

t_data  init_values(t_data *data)
{
    data->max_x = 0;
    data->max_y = 0;
    data->max_z = 0;
    data->min_z = 0;
    data->scale = 1;
    data->translation = 1;
	data->min_x_value = 0;
    data->min_y_value = 0;
    data->max_x_value = (data->max_x - 1) * data->scale;
    data->max_y_value = (data->max_y - 1) * data->scale;
	// data->alpha = 30.0 * (PI / 180.0);
	// data->altitude = 35.264 * (PI / 180.0);
    data->table = NULL;

    return(*data);
}

//probably delete this function later
void	center_map(t_data *data)
{
	int	x_offset;
	int	y_offset;
	int	x;
	int	y;
	int	index;

	x_offset = (data->win_width - (data->max_x * data->scale)) / 2;
	y_offset = (data->win_height - (data->max_y * data->scale)) / 2;
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			index = y * data->max_x + x;
			data->final_table[index].x -= x_offset;
			data->final_table[index].y -= y_offset;
			printf("x_afteroffset: %f || y_afteroffset: %f\n", data->final_table[index].x, data->final_table[index].y);
			x++;
		}
		y++;
	}
}

void find_min_max(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->min_x_value = FLT_MAX;
	data->min_y_value = FLT_MAX;
	data->max_x_value = FLT_MIN;
	data->max_y_value = FLT_MIN;
	while (i < data->max_y)
	{
		while(j < data->max_x)
		{
			data->min_x_value = fmin(data->min_x_value, data->table[i][j].x);
			data->min_y_value = fmin(data->min_y_value, data->table[i][j].y);
			data->max_x_value = fmax(data->max_x_value, data->table[i][j].x);
			data->max_y_value = fmax(data->max_y_value, data->table[i][j].y);
			// printf("Min_x %f | Min_y %f - Max_x %f | Max_y %f\n", data->min_x_value, data->min_y_value, data->max_x_value, data->max_y_value);
			j++;
		}
		i++;
	}
}

void	adjust_negatives(t_data *data)
{
	float	min_x;
	float	min_y;
	int		i;

	min_x = 0;
	min_y = 0;
	i = 0;
	while (i < data->max_x * data->max_y)
	{
		if (data->final_table[i].x < min_x)
			min_x = data->final_table[i].x;
		if (data->final_table[i].y < min_y)
			min_y = data->final_table[i].y;
		i++;
	}
	if (min_x < 0 || min_y < 0)
	{
		i = 0;
		while (i < data->max_x * data->max_y)
		{
			if (min_x < 0)
				data->final_table[i].x -=min_x;
			if (min_y < 0)
				data->final_table[i].y -= min_y;
			i++;
		}
	}
}

void	calculate_scale(t_data *data)
{
	// float	map_width;
	// float	map_height;
	// float	scale_x;
	// float	scale_y;

	// map_width = data->max_x * data->scale;
	// map_height = data->max_y * data->scale;
	// scale_x = (float)WIN_WIDTH / map_width;
	// scale_y = (float)WIN_HEIGHT / map_height;

	// data->scale = fmin(scale_x, scale_y);
	// map_width = data->max_x_value - data->min_x_value;
	// map_height = data->max_y_value - data->min_y_value;
	// scale_x = data->win_width / map_width;
	// scale_y = data->win_height / map_height;

	// data->scale = (scale_x < scale_y) ? scale_x : scale_y;
	// int	max_dimension;
	// int	min_window_size;

	// max_dimension = (data->max_x > data->max_y) ? data->max_x : data->max_y;
	// min_window_size = (WIN_WIDTH < WIN_HEIGHT) ? WIN_WIDTH : WIN_HEIGHT;
	// data->scale = (float)min_window_size / max_dimension;
	// max_dimension = fmax(data->max_x, data->max_y);
	// min_window_size = fmin(WIN_WIDTH, WIN_HEIGHT);
	// data->scale = (float)min_window_size / max_dimension;
	float	scale_x;
	float	scale_y;

	scale_x = (float)(WIN_WIDTH /2) / (data->max_x_value - data->min_x_value);
	scale_y = (float)(WIN_HEIGHT / 2) / (data->max_y_value - data->min_y_value);

	data->scale = fmin(scale_x, scale_y);
	
}