/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:32:43 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/13 12:08:11 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjust_negatives(t_data *data)
{
	float	min_x;
	float	min_y;
	int		i;

	min_x = 0;
	min_y = 0;
	i = 0;
	find_min_values(data, &min_x, &min_y);
	if (min_x < 0 || min_y < 0)
	{
		i = 0;
		while (i < data->max_x * data->max_y)
		{
			if (min_x < 0)
				data->final_table[i].x -= min_x;
			if (min_y < 0)
				data->final_table[i].y -= min_y;
			i++;
		}
	}
}

void	free_coordinates(t_data *data)
{
	int	y;

	if (data->table)
	{
		y = 0;
		while (y < data->max_y)
		{
			if (data->table[y])
				free(data->table[y]);
			y++;
		}
		free(data->table);
	}
}

double	deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}
