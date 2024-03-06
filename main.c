#include "fdf.h"

int main(int argc, char **argv)
{
	t_data	filename;
	char	*path;

	if (argc != 2)
		print_error("Error... Not enough arguments");
	path = argv[1];
	init_values(&filename);
	filename.map_path = ft_strjoin("./maps/", path);
	map_size(&filename, filename.map_path);
	map_format(&filename, filename.map_path);
	init_coordinates(&filename);
	map_parse(&filename, filename.map_path);
	// final_table(&filename);
	// connect_point(&filename);
	init_fdf(&filename);
	print_final_table(&filename);
	// print_map(&filename);
	printf("Map size-> width: %d, height: %d\n", filename.max_x, filename.max_y);
	return(0);
}
