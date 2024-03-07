/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:19 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/07 18:37:47 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_fdf(t_data *data)
{
 	// data->win_width = (data->max_x - 1) * data->scale + 2;
    // data->win_height = (data->max_y - 1) * data->scale + 2;
	// data->win_width = WIN_WIDTH;
	// data->win_height = WIN_HEIGHT;
	// calculate_scale(data);
	data->win_width = data->max_x * data->scale + 700;
    data->win_height = data->max_y * data->scale + 500;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free(data->mlx);
		print_error("Error in mlx_init");
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	final_table(data); //this function may not be useful anymore
	isometric_projection(data);
	adjust_negatives(data);
	// center_map(data);
	connect_point(data);
	mlx_put_image_to_window(data->mlx, data->win, \
							data->img, 0, 0);
	ft_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}
