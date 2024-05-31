#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

void	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
}

int	ft_key_event(int keycode, t_vars *vars)
{
	if (keycode == 'x')
		ft_exit(vars);
	printf("KEY CODE	: [%d] [%c]\n", keycode, keycode);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_exit(&vars);
	vars.win = mlx_new_window(vars.mlx, 1000, 800, "FDF ---");
	if (!vars.win)
		ft_exit(&vars);
	img.img = mlx_new_image(vars.mlx, 5000, 5000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_hook(vars.win, 2, 1L<<0, ft_key_event, &vars);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	ft_exit(&vars);
	return (0);
}