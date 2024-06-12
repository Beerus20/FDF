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
	map->cgravity.x = map->coor[map->row / 2][map->col / 2].x * map->modif.zoom;
	map->cgravity.y = map->coor[map->row / 2][map->col / 2].y * map->modif.zoom;
	map->cgravity.z = map->coor[map->row / 2][map->col / 2].z * map->modif.zoom;
	ft_op_add(&map->cgravity.x, &map->modif.gap.x);
	ft_op_add(&map->cgravity.y, &map->modif.gap.y);
	ft_op_add(&map->cgravity.z, &map->modif.gap.z);
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
	mlx_hook(w.win, 2, 1L<<0, ft_key_event, &w);
	ft_update_cgravity(w.map);
	w.map->modif.zoom = 1;
	ft_draw_image(&w);

	mlx_loop(w.mlx);
	ft_exit(&w);
	return (0);
}
