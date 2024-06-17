/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:20:11 by ballain           #+#    #+#             */
/*   Updated: 2024/06/17 23:20:12 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_data	ft_init_data(t_window *w)
{
	t_data	data;

	mlx_destroy_image(w->mlx, w->data.img);
	data.img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	data.img_ptr = mlx_get_data_addr(data.img, &data.bpp, &data.ll, &data.e);
	return (data);
}

void	ft_draw(int i, int j, t_map *map, t_data *data)
{
	t_coor	prev;
	t_coor	next;

	prev = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	next = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	if (i != 0)
		prev = ft_apply_modif(\
				&map->cgravity, &map->coor[j][i - 1], &map->modif);
	ft_plotline(prev, next, data);
	prev = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	next = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	if (j != 0)
		prev = ft_apply_modif(\
				&map->cgravity, &map->coor[j - 1][i], &map->modif);
	ft_plotline(prev, next, data);
}

int	ft_draw_string(t_window *w, int y, char *name, char *value)
{
	mlx_string_put(w->mlx, w->win, WIDTH - 120, y, 0xFFFFFF, name);
	mlx_string_put(w->mlx, w->win, WIDTH - 50, y, 0xFF0000, value);
	free(value);
	return (20);
}

void	ft_draw_info(t_window *w)
{
	int	y;

	y = 20;
	y += ft_draw_string(w, y, "WIDTH   : ", ft_itoa(WIDTH));
	y += ft_draw_string(w, y, "HEIGHT  : ", ft_itoa(HEIGHT));
	y += ft_draw_string(w, y, "ZOOM    : ", ft_itoa(w->map->modif.zoom / ZOOM));
	y += ft_draw_string(w, y, "pos x   : ", ft_itoa(w->map->modif.gap.x));
	y += ft_draw_string(w, y, "pos y   : ", ft_itoa(w->map->modif.gap.y));
	y += ft_draw_string(w, y, "Teta x  : ", ft_itoa(w->map->modif.teta.x));
	y += ft_draw_string(w, y, "Teta y  : ", ft_itoa(w->map->modif.teta.y));
	ft_draw_string(w, y, "Teta z  : ", ft_itoa(w->map->modif.teta.z));
}

void	ft_draw_image(t_window *w)
{
	int		i;
	int		j;

	j = 0;
	w->data = ft_init_data(w);
	while (j < w->map->row)
	{
		i = 0;
		while (i < w->map->col)
		{
			ft_draw(i, j, w->map, &w->data);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->data.img, 0, 0);
	ft_draw_info(w);
}
