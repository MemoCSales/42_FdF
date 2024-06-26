/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:19 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/13 12:29:25 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_fdf(t_data *data)
{
	calculate_scale(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free(data->mlx);
		print_error("Error in mlx_init");
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	ft_hooks(data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
	return (0);
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	final_table(data);
	isometric_projection(data);
	adjust_negatives(data);
	center_map(data);
	connect_point(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
