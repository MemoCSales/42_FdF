/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:56 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/08 00:02:48 by jimenasando      ###   ########.fr       */
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

// and idea for zooming
// void handle_event(t_data *data, SDL_Event event)
// {
//     if (event.type == SDL_MOUSEWHEEL)
//     {
//         if (event.wheel.y > 0) // scroll up
//         {
//             data->zoom *= 1.1; // zoom in
//         }
//         else if (event.wheel.y < 0) // scroll down
//         {
//             data->zoom /= 1.1; // zoom out
//         }

//         calculate_scale(data);
//     }
// }