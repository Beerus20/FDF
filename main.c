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

void	ft_update_mapv(t_map *map, int p_id, int (*f)(int, int), int add)
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
				map->coor[j][i].x = (*f)(map->coor[j][i].x, add);
			else if (p_id == 1)
				map->coor[j][i].y = (*f)(map->coor[j][i].y, add);
			else if (p_id == 2)
				map->coor[j][i].z = (*f)(map->coor[j][i].z, add);
			else
			{
				map->coor[j][i].x = (*f)(map->coor[j][i].x, add);
				map->coor[j][i].y = (*f)(map->coor[j][i].y, add);
				map->coor[j][i].z = (*f)(map->coor[j][i].z, add);
			}
			i++;
		}
		j++;
	}
}

int	ft_zoom(int keycode, t_window *w)
{
	int	v_x;
	int	v_y;

	v_x = w->map->coor[0][w->map->col - 1].x;
	if (keycode == 'x')
		ft_exit(w);

	if (keycode == 65362 && w->map->coor[0][0].y > 0)
		ft_update_mapv(w->map, 1, ft_op_sub, 2);
	if (keycode == 65361 && w->map->coor[0][0].x > 0)
		ft_update_mapv(w->map, 0, ft_op_sub, 2);
	if (keycode == 65363 && w->map->coor[0][w->map->col - 1].x < WIDTH)
		ft_update_mapv(w->map, 0, ft_op_add, 2);
	if (keycode == 65364)
		ft_update_mapv(w->map, 1, ft_op_add, 2);

	if (keycode == 'a' && w->map->coor[0][w->map->col - 1].x > w->map->col - 1)
		ft_update_mapv(w->map, 3, ft_op_div, 2);
	if (keycode == 'z')
		ft_update_mapv(w->map, 3, ft_op_mul, 2);
	// ft_printf("value	: [%d] [%c]\n", keycode, keycode);
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
	// w.data.img = mlx_new_image(w.mlx, WIDTH, HEIGHT);
	// w.data.img_ptr = mlx_get_data_addr(w.data.img, &w.data.bpp, &w.data.ll, &w.data.e);

	// mlx_expose_hook(w.win, ft_zoom, &w);
	mlx_hook(w.win, 2, 1L<<0, ft_zoom, &w);
	// mlx_key_hook(w.win, ft_zoom, &w);

	ft_draw_image(&w);

	// mlx_put_image_to_window(w.mlx, w.win, w.data.img, 0, 0);

	mlx_loop(w.mlx);
	ft_exit(&w);
	// ft_free_map(map);

	return (0);
}
