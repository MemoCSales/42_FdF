/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:45:23 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/13 12:31:02 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_error(char *error)
{
	ft_printf("%s\n", error);
	exit(0);
}

t_data	init_values(t_data *data)
{
	data->max_x = 0;
	data->max_y = 0;
	data->max_z = 0;
	data->min_z = 0;
	data->scale = 0;
	data->translation = 1;
	data->min_x_value = 0;
	data->min_y_value = 0;
	data->max_x_value = 0;
	data->max_y_value = 0;
	data->zoom = 1.0;
	data->table = NULL;
	return (*data);
}

void	center_map(t_data *data)
{
	int	x_offset;
	int	y_offset;
	int	x;
	int	y;
	int	index;

	x_offset = WIN_WIDTH / 2 - (data->max_x * data->scale);
	y_offset = WIN_HEIGHT / 2 - (data->max_y * data->scale);
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			index = y * data->max_x + x;
			data->final_table[index].x += x_offset;
			data->final_table[index].y += y_offset;
			x++;
		}
		y++;
	}
}

void	find_min_max(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->min_x_value = MAX_FLT;
	data->min_y_value = MAX_FLT;
	data->max_x_value = MIN_FLT;
	data->max_y_value = MIN_FLT;
	while (i < data->max_y)
	{
		j = 0;
		while (j < data->max_x)
		{
			data->min_x_value = fmin(data->min_x_value, data->table[i][j].x);
			data->min_y_value = fmin(data->min_y_value, data->table[i][j].y);
			data->max_x_value = fmax(data->max_x_value, data->table[i][j].x);
			data->max_y_value = fmax(data->max_y_value, data->table[i][j].y);
			j++;
		}
		i++;
	}
}

void	find_min_values(t_data *data, float *min_x, float *min_y)
{
	int	i;

	*min_x = 0;
	*min_y = 0;
	i = 0;
	while (i < data->max_x * data->max_y)
	{
		if (data->final_table[i].x < *min_x)
			*min_x = data->final_table[i].x;
		if (data->final_table[i].y < *min_y)
			*min_y = data->final_table[i].y;
		i++;
	}
}
