#include "ft_fdf.h"

void	ft_move_map(int keycode, t_map *map)
{
	if (keycode == 65361)
		map->modif.gap.x -= GAP;
	if (keycode == 65362)
		map->modif.gap.y -= GAP;
	if (keycode == 65363)
		map->modif.gap.x += GAP;;
	if (keycode == 65364)
		map->modif.gap.y += GAP;;
}

void	ft_zoom_map(int keycode, t_map *map)
{
	if (keycode == 'a')
		map->modif.zoom /= ZOOM;
	if (keycode == 'z')
		map->modif.zoom *= ZOOM;
}

void	ft_rotate_map(int keycode, t_map *map)
{
	if (keycode == 't')
		map->modif.teta.x += DEG;
	if (keycode == 'g')
		map->modif.teta.x -= DEG;
	if (keycode == 'r')
		map->modif.teta.y += DEG;
	if (keycode == 'f')
		map->modif.teta.y -= DEG;
	if (keycode == 'e')
		map->modif.teta.z += DEG;
	if (keycode == 'd')
		map->modif.teta.z -= DEG;
}

int	ft_key_event(int keycode, t_window *w)
{
	ft_update_cgravity(w->map);
	if (keycode == 'x')
		ft_exit(w);
	else if (keycode >= 65361 && keycode <= 65364)
		ft_move_map(keycode, w->map);
	else if (keycode == 'a' || keycode == 'z')
		ft_zoom_map(keycode, w->map);
	else
		ft_rotate_map(keycode, w->map);
	ft_show_map(w->map, 0);
	ft_show_map(w->map, 1);
	ft_update_cgravity(w->map);

	// mlx_clear_window(w->mlx, w->win);
	ft_draw_image(w);
	return (0);
}