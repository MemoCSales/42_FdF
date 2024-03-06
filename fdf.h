#ifndef FDF_H
# define FDF_H

// # include "mlx_linux/mlx.h"
# include "mlx_macos/mlx.h"
# include "srcs/ft_printf.h"
# include "./libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <float.h>

# define WIN_WIDTH 500
# define WIN_HEIGHT 500

# define RED 0XFF0000

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
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
	void	*address;
	void	*img;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
	// int		translation;
	int		i;
	char	*map_path;
	t_point	**table;
	t_final	*final_table;
} t_data;


// utils.c
int print_error(char *error);
t_data  init_values(t_data *data);

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
void	connect(t_data *data, int i);

// fdf.c
int	init_fdf(t_data *data);

// draw.c
void 	dda_algo(t_data *data, t_final a, t_final b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);



#endif