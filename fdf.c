/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:19 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/06 20:30:19 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_fdf(t_data *data)
{
 	data->win_width = (data->max_x - 1) * data->scale + 2;
    data->win_height = (data->max_y - 1) * data->scale + 2;
    // int     scale_factor_x = WIN_WIDTH / data->win_width;
    // int     scale_factor_y = WIN_HEIGHT / data->win_height;
    // int     scale_factor = scale_factor_x < scale_factor_y ? scale_factor_x : scale_factor_y; // Choose the smaller scale factor

    // data->scale = scale_factor;
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
	final_table(data); //this function may not be useful anymore
	// center_map(data);
	connect_point(data);
	mlx_put_image_to_window(data->mlx, data->win, \
							data->img, 0, 0);
	ft_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}

// void	get_point(t_data *data, char *point, int x, int y)
// {
// 	char	**map;
// 	int		i;

// 	data->table[y][x].x = x;
// 	data->table[y][x].y = y;
// 	if (ft_strchr(point, ','))
// 	{
// 		map = ft_split(point, ',');
// 		data->table[y][x].z = (float)ft_atoi(map[0]);
// 		i = 0;
// 		while (map[i])
// 			free(map[i++]);
// 		free(map);
// 	}
// 	else
// 		data->table[y][x].z = (float)ft_atoi(point);
// 	if (data->table[y][x].z > data->max_z)
// 		data->max_z = data->table[y][x].z;
// 	if (data->table[y][x].z < data->min_z)
// 		data->min_z = data->table[y][x].z;
// }

// void	connect_point(t_data *data)
// {
// 	int x;
// 	int y;

// 	data->i = 0;
// 	y = 0;
// 	while (y <  data->max_y)
// 	{
// 		x = 0;
// 		while (x < data->max_x)
// 		{
// 			connect_x_y(data, data->i);
// 			data->i++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	//probably free memory here of the final table;
// }

// void	connect_x_y(t_data *data, int i)
// {
// 	t_final	x;
// 	t_final	y;
// 	int		row;
// 	int		col;

// 	row = i / data->max_x;
// 	col = i % data->max_x;
// 	x.x = data->table[row][col].x * data->scale;
// 	x.y = data->table[row][col].y * data->scale;
// 	if (col < data->max_x - 1)
// 	{
// 		y.x = data->table[row][col + 1].x * data->scale;
// 		y.y = data->table[row][col + 1].y * data->scale;
// 		dda_algo(data, x, y);
// 	}
// 	if (row < data->max_y - 1)
// 	{
// 		y.x = data->table[row + 1][col].x * data->scale;
// 		y.y = data->table[row + 1][col].y * data->scale;
// 		dda_algo(data, x, y);
// 	}
// }







// void	map_size(t_data *data, char *filename)
// {
// 	int		fd;
// 	char	*line;
// 	char	**map;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		print_error("Map does not exists!");
// 	while ((line = get_next_line(fd)) != NULL && line)
// 	{
// 		if (data->max_y == 0)
// 		{
// 			map = ft_split(line, ' ');
// 			while (map[data->max_x])
// 			{
// 				free(map[data->max_x]);
// 				data->max_x++;
// 			}
// 			free(map);
// 		}
// 		data->max_y++;
// 		free(line);
// 	}
// 	close(fd);
// }

// void	map_format(t_data *data, char *filename)
// {
// 	char	**map;
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	fd = open(filename, O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		map = ft_split(line, ' ');
// 		i = 0;
// 		while (map[i])
// 		{
// 			free(map[i]);
// 			i++;
// 		}
// 		free(map);
// 		if (i != data->max_x)
// 			print_error("Wrong map format");
// 		free(line);
// 	}
// 	close(fd);
// }

// void	init_coordinates(t_data *data)
// {
// 	int		x;
// 	int		y;

// 	data->table = malloc (data->max_y * sizeof(t_point*));
// 	if (!data->table)
// 		printf("Allocation of x coordinate failed");
// 	y = 0;
// 	while (y < data->max_y)
// 	{
// 		data->table[y] = malloc (data->max_x * sizeof(t_point));
// 		if (!data->table[y])
// 			print_error("Allocation of y coordinate failed");
// 		x = 0;
// 		while (x < data->max_x)
// 		{
// 			data->table[y][x].x = 0;
// 			data->table[y][x].y = 0;
// 			data->table[y][x].z = 0;
// 			x++;
// 		}
// 		y++;
// 	}
// }
// void	map_parse(t_data *data, char *filename)
// {
// 	char	**split;
// 	char	*line;
// 	int		fd;
// 	int		point[2];

// 	fd = open(filename, O_RDONLY);
// 	point[1] = 0;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		split = ft_split(line, ' ');
// 		point[0] = 0;
// 		while (point[0] < data->max_x)
// 		{
// 			get_point(data, split[point[0]], point[0], point[1]);
// 			free(split[point[0]]);
// 			point[0]++;
// 		}
// 		free(split);
// 		free(line);
// 		point[1]++;
// 	}
// 	close(fd);
// }

// void	final_table(t_data *data)
// {
// 	int		x;
// 	int		y;
// 	int		index;

// 	y = 0;
// 	x = 0;
// 	data->final_table = malloc(data->max_x * data->max_y * sizeof(t_final));
// 	if (!data->final_table)
// 		print_error("Allocation of final table failed");
// 	while (y < data->max_y)
// 	{
// 		while (x < data->max_x)
// 		{
// 			index = y * data->max_x + x;
// 			data->final_table[index].x = data->table[y][x].x;
// 			data->final_table[index].y = data->table[y][x].y;
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void print_final_table(t_data *data) {
//     int x, y, index;

//     for (y = 0; y < data->max_y; y++) {
//         for (x = 0; x < data->max_x; x++) {
//             index = y * data->max_x + x;
//             printf("Final point at [%d][%d]: x = %f, y = %f\n", y, x, data->final_table[index].x, data->final_table[index].y);
//         }
//     }
// }

// void print_map(t_data *data) {
//     int x, y;

//     for (y = 0; y < data->max_y; y++) {
//         for (x = 0; x < data->max_x; x++) {
//             printf("Point at [%d][%d]: x = %f, y = %f, z = %f\n", y, x, data->table[y][x].x, data->table[y][x].y, data->table[y][x].z);
//         }
//     }
// }