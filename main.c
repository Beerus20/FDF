#include <stdio.h>
#include <stdlib.h>
#include "ft_fdf.h"

void	ft_exit(t_window *w)
{
	ft_free_map(w->map);
	mlx_destroy_image(w->mlx, w->data.img);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	exit(1);
}

void	ft_update_cgravity(t_map *map)
{
	int	i;
	int	x_sum;
	int	y_sum;

	i = 0;
	x_sum = 0;
	y_sum = 0;
	while (i < map->col)
	{
		x_sum += map->coor[0][i].x;
		i++;
	}
	i = 0;
	while (i < map->row)
	{
		y_sum += map->coor[i][0].y;
		i++;
	}
	map->cgravity.x = map->coor[0][map->col / 2].x;
	map->cgravity.y = map->coor[map->row / 2][0].y;
}

int	ft_zoom(int keycode, t_window *w)
{
	static float	add = 2;

	if (keycode == 'x')
		ft_exit(w);

	if (keycode == 65362 && w->map->coor[0][0].y > 0)
		ft_up_modif_func(w->map, 1, add, ft_op_sub);
	if (keycode == 65361 && w->map->coor[0][0].x > 0)
		ft_up_modif_func(w->map, 0, add, ft_op_sub);
	if (keycode == 65363 && w->map->coor[0][w->map->col - 1].x < WIDTH)
		ft_up_modif_func(w->map, 0, add, ft_op_add);
	if (keycode == 65364)
		ft_up_modif_func(w->map, 1, add, ft_op_add);

	if (keycode == 't')
		ft_up_modif_func(w->map, 4, add, ft_rot_x_axes);
	if (keycode == 'r')
		ft_up_modif_func(w->map, 5, add, ft_rot_y_axes);
	if (keycode == 'e')
		ft_up_modif_func(w->map, 6, add, ft_rot_z_axes);


	if (keycode == 'a' && w->map->coor[0][w->map->col - 1].x > w->map->col - 1)
	{
		ft_up_modif_func(w->map, 3, 2, ft_op_div);
		add /= 2;
	}
	if (keycode == 'z')
	{
		ft_up_modif_func(w->map, 3, 2, ft_op_mul);
		add *= 2;
	}
	ft_show_map(w->map);
	ft_update_cgravity(w->map);
	mlx_clear_window(w->mlx, w->win);
	ft_draw_image(w);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_window	w;

	w.map = ft_get_map(argv[1]);
	w.mlx = mlx_init();
	if (!w.mlx)
		ft_exit(&w);
	w.win = mlx_new_window(w.mlx, WIDTH, HEIGHT, "FDF ---");
	if (!w.win)
		ft_exit(&w);
	mlx_hook(w.win, 2, 1L<<0, ft_zoom, &w);
	ft_update_cgravity(w.map);
	ft_draw_image(&w);

	mlx_loop(w.mlx);
	ft_exit(&w);
	return (0);
}
