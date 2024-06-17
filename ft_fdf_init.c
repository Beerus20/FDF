/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:42:48 by ballain           #+#    #+#             */
/*   Updated: 2024/06/17 23:42:49 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_init_modif(t_map *map, int col, int row)
{
	map->modif.teta.x = 55;
	map->modif.teta.y = 35;
	map->modif.teta.z = -20;
	map->modif.gap.x = (WIDTH / 2) - (col / 2);
	map->modif.gap.y = (HEIGHT / 2) - (row / 2);
	map->modif.gap.z = 1;
	map->modif.zoom = 1;
}

t_color	ft_init_color(int color)
{
	t_color	r_color;

	r_color.t = ft_get_t(color);
	r_color.r = ft_get_r(color);
	r_color.g = ft_get_g(color);
	r_color.b = ft_get_b(color);
	return (r_color);
}
