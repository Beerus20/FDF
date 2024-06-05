#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_fdf.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	*data;
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

void	ft_update_mapv(t_map *map, int p_id, int (*f)(int))
{
	int	i;
	int	j;

	j = 0;
	while (j < map->row)
	{
		i = 0;
		while (i < map->col)
		{
			if (p_id == 0)
				map->coor[j][i].x = (*f)(map->coor[j][i].x);
			else if (p_id == 1)
				map->coor[j][i].y = (*f)(map->coor[j][i].y);
			else if (p_id == 2)
				map->coor[j][i].z = (*f)(map->coor[j][i].z);
			else
			{
				map->coor[j][i].x = (*f)(map->coor[j][i].x);
				map->coor[j][i].y = (*f)(map->coor[j][i].y);
				map->coor[j][i].z = (*f)(map->coor[j][i].z);
			}
			i++;
		}
		j++;
	}
}

int	ft_test(int value)
{
	return (value * 5);
}

int	ft_zoom(int keycode, t_vars *vars)
{
	if (keycode == 'x')
		exit(0);
	if (keycode == 'z')
	{
		vars->map->sup += 10;
		mlx_clear_window(vars->mlx, vars->win);
		// mlx_destroy_image(vars->mlx, vars->data);
		ft_update_mapv(vars->map, 3, ft_test);
		vars->data = (t_data *)malloc(sizeof(t_data));
		vars->data->img = mlx_new_image(vars->mlx, 500, 500);
		vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bits_per_pixel, &vars->data->line_length, &vars->data->endian);
		ft_draw_map(vars->map, vars->data);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);

		// ft_show_element(vars->map);
		// ft_plotline(prev, next, vars->data);
		// vars->map->sup += 1;
	}
	return (0);
}

int	main(int argc, const char **argv)
{
	t_vars	vars;
	t_data	img;

	vars.data = (t_data *)malloc(sizeof(t_data));
	vars.map = ft_get_map(argv[1]);
	vars.map->sup = 1;
	vars.mlx = mlx_init();
	if (!vars.mlx || !vars.data)
		ft_exit(&vars);
	vars.win = mlx_new_window(vars.mlx, 1000, 800, "FDF ---");
	if (!vars.win)
		ft_exit(&vars);
	vars.data->img = mlx_new_image(vars.mlx, 500, 500);
	vars.data->addr = mlx_get_data_addr(vars.data->img, &vars.data->bits_per_pixel, &vars.data->line_length, &vars.data->endian);
	// mlx_hook(vars.win, 2, 1L<<0, ft_key_event, &vars);
	mlx_key_hook(vars.win, ft_zoom, &vars);
	// ft_plotline(20, 20, 30, 100, &img);
	ft_draw_map(vars.map, vars.data);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.data->img, 0, 0);
	// mlx_destroy_image(vars.mlx, img.img);

	mlx_loop(vars.mlx);
	ft_exit(&vars);
	// ft_free_map(map);
	return (0);
}
