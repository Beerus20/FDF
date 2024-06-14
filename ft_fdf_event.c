#include "ft_fdf.h"

void	ft_move_map(int keycode, t_map *map)
{
	if (keycode == 65361)
		map->modif.gap.x -= GAP + map->modif.zoom;
	if (keycode == 65362)
		map->modif.gap.y -= GAP + map->modif.zoom;
	if (keycode == 65363)
		map->modif.gap.x += GAP + map->modif.zoom;
	if (keycode == 65364)
		map->modif.gap.y += GAP + map->modif.zoom;
	if (keycode == 'y')
		map->modif.gap.z -= 0.1;
	if (keycode == 'h')
		map->modif.gap.z += 0.1;
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
	if (keycode == 65307)
		ft_exit(w);
	ft_move_map(keycode, w->map);
	ft_zoom_map(keycode, w->map);
	ft_rotate_map(keycode, w->map);
	ft_update_cgravity(w->map);
	ft_draw_image(w);
	return (0);
}