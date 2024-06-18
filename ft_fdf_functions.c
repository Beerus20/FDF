/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:23:59 by ballain           #+#    #+#             */
/*   Updated: 2024/06/18 11:32:59 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_update_cgravity(t_map *map)
{
	map->cgravity.x = map->coor[map->row / 2][map->col / 2].x * map->modif.zoom;
	map->cgravity.y = map->coor[map->row / 2][map->col / 2].y * map->modif.zoom;
	map->cgravity.z = map->coor[map->row / 2][map->col / 2].z * map->modif.zoom;
	ft_op_add(&map->cgravity.x, &map->modif.gap.x);
	ft_op_add(&map->cgravity.y, &map->modif.gap.y);
	ft_op_add(&map->cgravity.z, &map->modif.gap.z);
}

int	ft_mouse_event(int x, int y, t_window *w)
{
	if (w->a_mouse == 1)
	{
		w->map->modif.gap.x = x - ((w->map->col / 2) * w->map->modif.zoom);
		w->map->modif.gap.y = y - ((w->map->row / 2) * w->map->modif.zoom);
	}
	if (w->a_mouse == 2)
	{
		w->map->modif.teta.x = w->map->cgravity.y - y;
		w->map->modif.teta.y = x - w->map->cgravity.x;
	}
	if (w->a_mouse == 3)
		w->map->modif.teta.z = w->map->cgravity.y - y;
	if (w->a_mouse != 0)
	{
		ft_update_cgravity(w->map);
		ft_draw_image(w);
	}
	return (0);
}

int	ft_scroll_wheel(int button_id, int x, int y, t_window *w)
{
	if (button_id == 4)
		ft_zoom_map('z', w->map);
	if (button_id == 5)
		ft_zoom_map('a', w->map);
	if (button_id == 4 || button_id == 5)
	{
		ft_update_cgravity(w->map);
		ft_draw_image(w);
	}
	return (0);
}

t_coor	ft_apply_modif(t_coor *cg, t_coor *e, t_modif *modif)
{
	t_coor	r_value;

	r_value.x = e->x;
	r_value.y = e->y;
	r_value.z = e->z;
	r_value.c = e->c;
	r_value.x *= modif->zoom;
	r_value.y *= modif->zoom;
	r_value.z *= modif->zoom;
	ft_op_add(&r_value.x, &modif->gap.x);
	ft_op_add(&r_value.y, &modif->gap.y);
	ft_op_mul(&r_value.z, &modif->gap.z);
	ft_rot_x_axes(cg, &r_value.y, &r_value.z, modif->teta.x);
	ft_rot_y_axes(cg, &r_value.x, &r_value.z, modif->teta.y);
	ft_rot_z_axes(cg, &r_value.x, &r_value.y, modif->teta.z);
	return (r_value);
}
