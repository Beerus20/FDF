/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:22:50 by ballain           #+#    #+#             */
/*   Updated: 2024/06/17 23:22:51 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_ajust_value(double *v, double add, void (*ft)(double *, double *))
{
	ft(v, &add);
	if (ft_abs(*v) >= 360)
		*v = 0;
}

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
	if (keycode == 'a' && (map->modif.zoom / ZOOM) > 0)
		map->modif.zoom /= ZOOM;
	if (keycode == 'z' && (map->modif.zoom * ZOOM) <= 1024)
		map->modif.zoom *= ZOOM;
}

void	ft_rotate_map(int keycode, t_map *map)
{
	if (keycode == 't')
		ft_ajust_value(&map->modif.teta.x, DEG, ft_op_add);
	if (keycode == 'g')
		ft_ajust_value(&map->modif.teta.x, DEG, ft_op_sub);
	if (keycode == 'r')
		ft_ajust_value(&map->modif.teta.y, DEG, ft_op_add);
	if (keycode == 'f')
		ft_ajust_value(&map->modif.teta.y, DEG, ft_op_sub);
	if (keycode == 'e')
		ft_ajust_value(&map->modif.teta.z, DEG, ft_op_add);
	if (keycode == 'd')
		ft_ajust_value(&map->modif.teta.z, DEG, ft_op_sub);
}

int	ft_key_event(int keycode, t_window *w)
{
	while ((int)w->map->modif.teta.x % GAP != 0)
		w->map->modif.teta.x++;
	while ((int)w->map->modif.teta.y % GAP != 0)
		w->map->modif.teta.y++;
	while ((int)w->map->modif.teta.z % GAP != 0)
		w->map->modif.teta.z++;
	if (keycode == 65307)
		ft_exit(w);
	if (keycode == 'p')
		w->a_mouse = 0;
	if (keycode == 'm')
		w->a_mouse = 1;
	if (keycode == 'l')
		w->a_mouse = 2;
	if (keycode == 'o')
		w->a_mouse = 3;
	ft_move_map(keycode, w->map);
	ft_zoom_map(keycode, w->map);
	ft_rotate_map(keycode, w->map);
	ft_update_cgravity(w->map);
	ft_draw_image(w);
	return (0);
}
