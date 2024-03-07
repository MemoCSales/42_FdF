/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:19 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/08 00:21:58 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_fdf(t_data *data)
{
 	// data->win_width = (data->max_x - 1) * data->scale + 2;
    // data->win_height = (data->max_y - 1) * data->scale + 2;
	// data->win_width = WIN_WIDTH;
	// data->win_height = WIN_HEIGHT;
	data->win_width = data->max_x_value * data->scale;
    data->win_height = data->max_y_value * data->scale;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free(data->mlx);
		print_error("Error in mlx_init");
	}
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "FdF");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	final_table(data);
	isometric_projection(data);
	adjust_negatives(data);
	// center_map(data);  delete this
	connect_point(data);
	mlx_put_image_to_window(data->mlx, data->win, \
							data->img, 0, 0);
	// ft_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}
