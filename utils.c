#include "fdf.h"

int print_error(char *error)
{
    ft_printf("%s\n", error);
    exit(0);
}

t_data  init_values(t_data *data)
{
    data->max_x = 0;
    data->max_y = 0;
    data->max_z = 0;
    data->min_z = 0;

    data->table = NULL;

    return(*data);
}