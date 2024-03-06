#include "fdf.h"

int main(void)
{
    void    *mlx;
    void    *win;
    mlx = mlx_init();
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
    int x;
    int y;

    y = WIN_HEIGHT * 0.1;
    while (y < WIN_HEIGHT * 0.9)
    {
        x = WIN_WIDTH * 0.1;
        while (x < WIN_WIDTH * 0.9)
        {
            mlx_pixel_put(mlx, win, x, y, RED);
            x++;
        }
        y++;
    }
    mlx_loop(mlx);
}