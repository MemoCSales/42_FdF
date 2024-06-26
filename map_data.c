/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:45:34 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/13 11:55:10 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_size(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Map does not exists!");
	line = get_next_line(fd);
	while (line != NULL && line)
	{
		if (data->max_y == 0)
		{
			map = ft_split(line, ' ');
			while (map[data->max_x])
			{
				free(map[data->max_x]);
				data->max_x++;
			}
			free(map);
		}
		data->max_y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	map_format(t_data *data, char *filename)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = ft_split(line, ' ');
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		if (i < data->max_x)
			print_error("Wrong map format");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_coordinates(t_data *data)
{
	int	x;
	int	y;

	data->table = malloc(data->max_y * sizeof(t_point *));
	if (!data->table)
		print_error("Allocation of x coordinate failed");
	y = 0;
	while (y < data->max_y)
	{
		data->table[y] = malloc(data->max_x * sizeof(t_point));
		if (!data->table[y])
			print_error("Allocation of y coordinate failed");
		x = 0;
		while (x < data->max_x)
		{
			data->table[y][x].x = 0;
			data->table[y][x].y = 0;
			data->table[y][x].z = 0;
			x++;
		}
		y++;
	}
}

void	map_parse(t_data *data, char *filename)
{
	char	**split;
	char	*line;
	int		fd;
	int		point[2];

	fd = open(filename, O_RDONLY);
	point[1] = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		split = ft_split(line, ' ');
		point[0] = 0;
		while (point[0] < data->max_x)
		{
			get_point(data, split[point[0]], point[0], point[1]);
			free(split[point[0]]);
			point[0]++;
		}
		free(line);
		free(split);
		point[1]++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	final_table(t_data *data)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	x = 0;
	data->final_table = malloc(data->max_x * data->max_y * sizeof(t_final));
	if (!data->final_table)
		print_error("Allocation of final table failed");
	while (y < data->max_y)
	{
		while (x < data->max_x)
		{
			index = y * data->max_x + x;
			data->final_table[index].x = data->table[y][x].x;
			data->final_table[index].y = data->table[y][x].y;
			x++;
		}
		y++;
	}
}
