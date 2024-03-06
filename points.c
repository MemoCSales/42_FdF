#include "fdf.h"

void	get_point(t_data *data, char *point, int x, int y)
{
	char	**map;
	int		i;

	data->table[y][x].x = x;
	data->table[y][x].y = y;
	if (ft_strchr(point, ','))
	{
		map = ft_split(point, ',');
		data->table[y][x].z = (float)ft_atoi(map[0]);
		i = 0;
		while (map[i])
			free(map[i++]);
		free(map);
	}
	else
		data->table[y][x].z = (float)ft_atoi(point);
	if (data->table[y][x].z > data->max_z)
		data->max_z = data->table[y][x].z;
	if (data->table[y][x].z < data->min_z)
		data->min_z = data->table[y][x].z;
}

void	connect_point(t_data *data)
{
	int x;
	int y;

	data->i = 0;
	y = 0;
	while (y <  data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			connect(data, data->i);
			data->i++;
			x++;
		}
		y++;
	}
	//probably free memory here of the final table;
}

void	connect(t_data *data, int i)
{
	t_final	x;
	t_final	y;
	int		row;
	int		col;

	row = i / data->max_x;
	col = i % data->max_x;
	// x.x = data->table[row][col].x;
	x = data->final_table[i];
	if (col < data->max_x - 1)
	{
		// y.y = data->table[row][col].y;
		y = data->final_table[i + 1];
		dda_algo(data, x, y);
	}
	if (row < data->max_y - 1)
	{
		// y.y = data->table[row + data->max_x][col].y;
		y = data->final_table[i + data->max_x];
		dda_algo(data, x, y);
	}
}