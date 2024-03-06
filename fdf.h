/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:45:50 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/06 20:45:52 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx_linux/mlx.h"
# include "srcs/ft_printf.h"
# include "./libft/libft.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <float.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define PI 3.14159265

# define DEG_TO_RAD(degrees) ((degrees) * PI / 180.0)
# define RED 0XFF0000

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	// int		color;
} t_point;

typedef struct s_final
{
	float	x;
	float	y;
} t_final;

typedef struct s_delta
{
	float	dx;
	float	dy;
} t_delta;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
	int		x_center;
	int		y_center;
	int		scale;
	int		translation;
	int		i;
	float	min_x_value;
	float	min_y_value;
	float	max_x_value;
	float	max_y_value;
	char	*map_path;
	int		win_width;
	int		win_height;
	t_point	**table;
	t_final	*final_table;
} t_data;


// utils.c
int print_error(char *error);
t_data  init_values(t_data *data);
void    center_map(t_data *data);
void find_min_max(t_data *data);

// map_data.c
void	map_size(t_data *data, char *filename);
void	map_format(t_data *data, char *filename);
void	init_coordinates(t_data *data);
void	map_parse(t_data *data, char *filename);
void	final_table(t_data *data);


void 	print_map(t_data *data);
void print_final_table(t_data *data);

// points.c
void	get_point(t_data *data, char *point, int x, int y);
void	connect_point(t_data *data);
void	connect_x_y(t_data *data, int i);

// fdf.c
int	init_fdf(t_data *data);

// draw.c
void 	dda_algo(t_data *data, t_final a, t_final b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void 	isometric_projection(t_data *data);
void isometric_projection(t_final *x, t_final *y);

// hooks.c
void	ft_hooks(t_data *data);
int	key_layout(int key, t_data *data);
int	close_win(t_data *data);



#endif