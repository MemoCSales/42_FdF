/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:45:23 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/06 20:45:26 by mcruz-sa         ###   ########.fr       */
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
    data->scale = 50;
    data->translation = 1;
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

	x_offset = (data->win_width - (data->max_x * data->scale)) / 2;
	y_offset = (data->win_height - (data->max_y * data->scale)) / 2;
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->table[y][x].x += x_offset;
			data->table[y][x].y += y_offset;
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
