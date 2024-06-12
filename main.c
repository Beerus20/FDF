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
	map->cgravity.x = map->coor[map->row / 2][map->col / 2].x;
	map->cgravity.y = map->coor[map->row / 2][map->col / 2].y;
	map->cgravity.z = map->coor[map->row / 2][map->col / 2].z;
}

int	ft_zoom(int keycode, t_window *w)
{
	static double	add = 2;
	static double	x = 0;
	static double	z = 10;

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
	ft_show_map(w->map, 0);
	ft_update_cgravity(w->map);
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
