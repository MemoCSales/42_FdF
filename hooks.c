/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:56 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/06 15:00:34 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_layout, data);
	mlx_hook(data->win, 17, 0, close_win, data);
}

int	key_layout(int key, t_data *data)
{
	if(key == XK_Escape)
		close_win(data);
	return(0);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}